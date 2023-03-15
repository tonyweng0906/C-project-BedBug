/**
 * @file PlayArea.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "PlayArea.h"
#include <memory>
#include <iostream>

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// The bug feature image
const std::wstring FeatureBugImageName = L"images/feature.png";

/// The redundancy fly image
const std:: wstring RedundancyFlyImageName = L"images/redundancy-fly-base.png";

const std::wstring NullBugImageName = L"images/scarlet-gray-bug.png";
/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;


/**
 * PlayArea Constructor
 */

PlayArea::PlayArea()
{
	// Adding the GarbageBug bitmap
	std::shared_ptr<wxImage> GarbageBugImage =
		std::make_unique<wxImage>(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);
	std::shared_ptr<wxBitmap> GarbageBugBitmap = std::make_unique<wxBitmap>(*GarbageBugImage);
	mImages.insert({"garbage", GarbageBugBitmap});

	std::shared_ptr<wxImage> FeatureBugImage =
		std::make_unique<wxImage>(FeatureBugImageName, wxBITMAP_TYPE_ANY);
	std::shared_ptr<wxBitmap> FeatureBugBitmap = std::make_unique<wxBitmap>(*FeatureBugImage);
	mImages.insert({"feature", FeatureBugBitmap});

	std::shared_ptr<wxImage> RedundancyFlyImage =
		std::make_unique<wxImage>(RedundancyFlyImageName, wxBITMAP_TYPE_ANY);
	std::shared_ptr<wxBitmap> RedundancyFlyBitmap = std::make_unique<wxBitmap>(*RedundancyFlyImage);
	mImages.insert({"redundancy", RedundancyFlyBitmap});

	std::shared_ptr<wxImage> NullBugImage =
		std::make_unique<wxImage>(NullBugImageName, wxBITMAP_TYPE_ANY);
	std::shared_ptr<wxBitmap> NullBugBitmap = std::make_unique<wxBitmap>(*NullBugImage);
	mImages.insert({"null", NullBugBitmap});

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
		object->Update(elapsed);
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
 * @return Pointer to the bitmap
 */
std::shared_ptr<wxBitmap> PlayArea::GetBitmap(std::string name)
{
	auto bitMap = mImages.find(name);
	if (bitMap!=mImages.end())
	{
		return bitMap->second;
	}
}


