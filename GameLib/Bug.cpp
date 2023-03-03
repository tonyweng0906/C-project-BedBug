/**
 * @file Bug.cpp
 * @author Team BedBug
 */

#include "pch.h"
#include "Bug.h"
#include "Game.h"

/**
 * Constructor
 * @param aquarium The aquarium we are in
 * @param filename Filename for the image we use
 */
Bug::Bug(Game *game, const std::wstring &filename) :
	GameObject(game, filename)
{
	/**
	std::uniform_real_distribution<> distribution(MinSpeedX, MaxSpeedX);
	mSpeedX = distribution(aquarium->GetRandom());
	mSpeedY = distribution(aquarium->GetRandom());
	 */
}

/**
 *  FishSpeed sets the speed for each fish
 * @param speedX x-parameter
 * @param speedY y-parameter
 */

void Bug::BugSpeed(double speedX, double speedY)
{
	/**
	std::uniform_real_distribution<> distribution(speedX, speedX);
	mSpeedX = distribution(GetGame()->GetRandom());
	mSpeedY = distribution(GetGame()->GetRandom());
	 */
}

/**
 * Handle updates in time of our bug
 *
 * This is called before we draw and allows us to
 * move our bug. We add our speed times the amount
 * of time that has elapsed.
 * @param elapsed Time elapsed since the class call
 */
void Bug::Update(double elapsed)
{
	/*
	SetLocation(GetX() + mSpeedX * elapsed,
				GetY() + mSpeedY * elapsed);

	int half_bug_width = GetWidth() / 2;
	int half_bug_height = GetHeight() / 2;

	if (mSpeedX > 0 && GetX() + half_bug_width >= GetGame()->GetWidth() - 10)
	{
		mSpeedX = -mSpeedX;
		SetMirror(true);
	}

	if (mSpeedX < 0 && GetX() - half_bug_width < 10)
	{
		mSpeedX = -mSpeedX;
		SetMirror(false);
	}

	if (mSpeedY > 0 && GetY() + half_bug_height >= GetGame()->GetHeight() - 10)
	{
		mSpeedY = -mSpeedY;
	}
	if (mSpeedY < 0 && GetY() - half_bug_height < 10)
	{
		mSpeedY = -mSpeedY;
	}
	*/
}

/**
 * Save this item to an XML node
 * @param node The parent node we are going to be a child of
 * @return wxXmlNode that we saved the item into

wxXmlNode *Fish::XmlSave(wxXmlNode *node)
{
	auto itemNode = Item::XmlSave(node);
	itemNode->AddAttribute(L"speedX", wxString::FromDouble(mSpeedX));
	itemNode->AddAttribute(L"speedY", wxString::FromDouble(mSpeedY));

	return itemNode;
}

/**
 * Load the attributes for an fish node.
 *
 * This is the  derived class version that loads the attributes
 * common to all items.
 *
 *
 * @param node The Xml node we are loading the item from

void Fish::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"speedX", L"0").ToDouble(&mSpeedX);
	node->GetAttribute(L"speedY", L"0").ToDouble(&mSpeedY);
	Item::XmlLoad(node);
}
*/

