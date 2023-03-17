/**
 * @file Bug.cpp
 * @author Team BedBug
 */

#include "pch.h"
#include "Bug.h"
#include "Game.h"
#include "Program.h"

/**
 * Constructor
 * @param game The game we are in
 * @param filename Filename for the image we use
 */
Bug::Bug(Game *game, const std::wstring & name ) : GameObject(game, name)
{

}

/**
 * BugSpeed sets the speed for each fish
 * @param speedX x-parameter
 * @param speedY y-parameter
 */

void Bug::BugSpeed(double speedX, double speedY)
{

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

	double angle = atan2(GetY()-mProgram->GetY(),GetX()-mProgram->GetX());
	double newX = GetX() + elapsed * -mSpeed * cos(angle);
	double newY = GetY() + elapsed * -mSpeed * sin(angle);
	SetLocation(newX,newY);

}

/**
 * Load the attributes for a bug node.
 *
 * This is the  derived class version that loads the attributes
 * common to all items.
 *
 *
 * @param node The Xml node we are loading the item from
 */
void Bug::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"speed", L"0").ToDouble(&mSpeed);
	node->GetAttribute(L"start", L"0").ToDouble(&mStart);
	GameObject::XmlLoad(node);
}


