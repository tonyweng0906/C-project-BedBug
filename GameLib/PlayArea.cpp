/**
 * @file PlayArea.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "PlayArea.h"
#include <memory>
#include <iostream>


/// The garbage bug image
const std::wstring GarbageBugImageName = L"images/blue-maize-bug.png";

/// The garbage bug splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// The bug feature image
const std::wstring FeatureBugImageName = L"images/feature.png";

/// The bug feature splat image
const std::wstring FeatureBugSplatImageName = L"images/feature-splat.png";

/// The redundancy fly image
const std:: wstring RedundancyFlyImageName = L"images/redundancy-fly-base.png";

/// The redundancy top image
const std::wstring RedundancyFlyTopImageName = L"images/redundancy-fly-top.png";

/// The left wing image
const std::wstring RedundancyFlyLeftWingImageName = L"images/redundancy-fly-lwing.png";

/// The right wing image
const std::wstring RedundancyFlyRightWingImageName = L"images/redundancy-fly-rwing.png";

/// The redundancy fly splat image
const std::wstring RedundancyFlySplatImageName = L"images/redundancy-fly-splat.png";

/// The Null Bug image
const std::wstring NullBugImageName = L"images/scarlet-gray-bug.png";

/// The Null Bug splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// The Program image
const std::wstring ProgramImageName = L"images/laptop.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;


/**
 * PlayArea Constructor
 */

PlayArea::PlayArea()
{
	// Adding the GarbageBug image
	std::shared_ptr<wxImage> GarbageBugImage = std::make_shared<wxImage>(GarbageBugImageName);
	mImages.insert({"garbage", GarbageBugImage});

	// Adding the splat GarbageBug image
	std::shared_ptr<wxImage> GarbageBugSplatImage = std::make_shared<wxImage>(GarbageBugSplatImageName);
	mImages.insert({"garbageSplat", GarbageBugSplatImage});

	// Adding the NullBug image
	std::shared_ptr<wxImage> NullBugImage = std::make_shared<wxImage>(NullBugImageName);
	mImages.insert({"null", NullBugImage});

	// Adding Nullbug splat image
	std::shared_ptr<wxImage> NullBugSplatImage = std::make_shared<wxImage>(NullBugSplatImageName);
	mImages.insert({"nullSplat", NullBugSplatImage});

	// Adding FeatureBug Image
	std::shared_ptr<wxImage> FeatureBugImage = std::make_shared<wxImage>(FeatureBugImageName);
	mImages.insert({"feature", FeatureBugImage});

	// Adding FeatureBug Splat Image
	std::shared_ptr<wxImage> FeatureBugSplatImage = std::make_shared<wxImage>(FeatureBugSplatImageName);
	mImages.insert({"featureSplat", FeatureBugSplatImage});

	// Adding RedundancyFly Image
	std::shared_ptr<wxImage> RedundancyFlyImage = std::make_shared<wxImage>(RedundancyFlyImageName);
	mImages.insert({"redundancy", RedundancyFlyImage});

	// Adding RedundancyFlyTop Image
	std::shared_ptr<wxImage> RedundancyFlyTopImage = std::make_shared<wxImage>(RedundancyFlyTopImageName);
	mImages.insert({"redundancyTop", RedundancyFlyTopImage});

	// Adding LeftWing Image
	std::shared_ptr<wxImage> LeftWingImage = std::make_shared<wxImage>(RedundancyFlyLeftWingImageName);
	mImages.insert({"leftWing", LeftWingImage});

	// Adding RightWing Image
	std::shared_ptr<wxImage> RightWingImage = std::make_shared<wxImage>(RedundancyFlyRightWingImageName);
	mImages.insert({"rightWing", RightWingImage});

	// Adding RedundancyFly Splat Image
	std::shared_ptr<wxImage> RedundancyFlySplatImage = std::make_shared<wxImage>(RedundancyFlySplatImageName);
	mImages.insert({"redundancySplat", RedundancyFlySplatImage});

	// Adding Program Image
	std::shared_ptr<wxImage> ProgramImage = std::make_shared<wxImage>(ProgramImageName);
	mImages.insert({"program", ProgramImage});

}

/**
 * Add an object to the PlayArea
 * @param object new object to add
 */
void PlayArea::Add(std::shared_ptr<GameObject> object)
{
	mObjects.push_back(object);
}


/**
 * Test an x,y click location to see if it clicked
 * on some object in the play area
 * @param x X location
 * @param y Y location
 * @return Pointer to object clicked on or nullptr if none.
 */
std::shared_ptr<GameObject> PlayArea::HitTest(int x, int y)
{

	for (auto i = mObjects.rbegin(); i != mObjects.rend(); i++)
	{
		if ((*i)->HitTest(x,y))
		{
			return *i;
		}
	}
	return nullptr;
}


/**
 * Delete an object from the play area
 * @param object the object to delete
 */
void PlayArea::DeleteObject(std::shared_ptr<GameObject> object)
{
	auto loc = find(std::begin(mObjects), std::end(mObjects), object);
	if (loc != std::end(mObjects))
	{
		mObjects.erase(loc);
	}
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void PlayArea::Update(double elapsed)
{
	for (auto object : mObjects)
	{
		if (object != nullptr)
		{
			object->Update(elapsed);
			if (object->MoveFinish())
			{
				DeleteObject(object);
				continue;
			}
		}
	}
}

/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void PlayArea::Accept(ObjectVisitor *visitor)
{
	for (auto object : mObjects)
	{
		//Need to build accept function in object class
		object->Accept(visitor);
	}
}

/// Clear the Objects
void PlayArea::ClearObject()
{
	mObjects.clear();
}

/**
 * Get the Bitmap when call the name of the object
 * @param name name of the object
 * @return  the bitmap
 */
std::shared_ptr<wxImage> PlayArea::GetImage(std::string name)
{
	auto image = mImages.find(name);
	if (image!=mImages.end())
	{
		return image->second;
	}
	return nullptr;
}


/**
 * Draw all the item
 * @param dc wxGraphicsContext
 *
 */
void PlayArea::Draw(std::shared_ptr<wxGraphicsContext> dc)
{
	for (auto item : mObjects)
	{
		item->Draw(dc);
	}
}
