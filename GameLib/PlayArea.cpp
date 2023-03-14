/**
 * @file PlayArea.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "PlayArea.h"



/**
 * PlayArea Constructor
 */

PlayArea::PlayArea()
{

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