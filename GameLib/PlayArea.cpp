/**
 * @file PlayArea.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "PlayArea.h"
#include <memory>
using namespace std;

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;


/**
 * PlayArea Constructor
 */

PlayArea::PlayArea()
{
	// Adding the GarbageBug bitmap
	std::shared_ptr<wxImage> GarbageBugImage =
		make_unique<wxImage>(GarbageBugSpriteImageName, wxBITMAP_TYPE_ANY);
	std::shared_ptr<wxBitmap> GarbageBugBitmap = make_unique<wxBitmap>(*GarbageBugImage);
	mImages.insert({"GarbageBug", GarbageBugBitmap});

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
		//object.Accept(visitor);
	}
}

/// Clear the Objects
void PlayArea::ClearObject()
{
	mObjects.clear();
}