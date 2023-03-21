/**
 * @file Feature.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "Feature.h"
#include "Program.h"
#include "Game.h"

/// The feature sprite image
const std::wstring FeatureImageName = L"images/feature.png";

/// The splat image
const std::wstring FeatureSplatImageName = L"images/feature-splat.png";

/// Number of sprite images
const int FeatureNumSpriteImages = 7;

/**
 * Constructor
 * @param game The game we are in
 */
Feature::Feature(Game *game) : GameObject(game, FeatureImageName)
{

}

/**
 * Load the attributes for a Feature node.
 *
 * This is the  derived class version that loads the attributes
 * common to all items.
 * @param node The Xml node we are loading the item from
 */
void Feature::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"speed", L"0").ToDouble(&mSpeed);
	node->GetAttribute(L"start", L"0").ToDouble(&mStart);
	GameObject::XmlLoad(node);
}

/**
 * Handle updates in time of our feature
 * This is called before we draw and allows us to
 * move our bug. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Feature::Update(double elapsed)
{
	double angle = atan2(GetY()-mProgram->GetY(),GetX()-mProgram->GetX());
	mRotation = 3.1415926+angle;
	double newX = GetX() + elapsed * -mSpeed * cos(angle);
	double newY = GetY() + elapsed * -mSpeed * sin(angle);
	SetLocation(newX,newY);
	if (GetY()-mProgram->GetY() <= 5 && GetX()-mProgram->GetX() <= 5)
	{

	}
}

/**
* Draw this GameObject
* @param dc Device context to draw on
*/

void Feature::Draw(std::shared_ptr<wxGraphicsContext> dc)
{
	if (mObjectBitmap.IsNull())
	{
		mObjectBitmap = dc->CreateBitmapFromImage(*mObjectImage);
	}

	if (mObjectBitmap.IsNull())
	{
		mObjectBitmap = dc->CreateBitmapFromImage(*mObjectImage);
	}

	mSubBugBitmap = dc->CreateSubBitmap(mObjectBitmap,0,0,100,100);
	dc->PushState();
	dc->Translate(mX,mY);
	dc->Rotate(mRotation);
	dc->DrawBitmap(mSubBugBitmap, -50, -50, 100, 100);
	dc->PopState();
}