/**
 * @file BugMulti.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "BugMulti.h"
#include <sstream>
#include <iostream>
#include "Game.h"

/// Bug Name
const std::string BugName = "multi";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 6;

/// Avg distance for new bugs to generate at
const int Distance = 201;

/// Number of bugs to generate on death
const int NewBugs1 = rand() % 3 + 1;

/// Number of bugs to generate on death
const int NewBugs2 = rand() % 3 +1;

void BugMulti::AddScore() {
	mScoreBoard.AddFixed();
}

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugMulti::BugMulti(Game *game) : Bug(game, BugName, GarbageBugNumSpriteImages )
{

}

/**
 * Set Multi Bug behavior on single click
 */
void BugMulti::SingleClick()
{
		this->PopBug();
		Bug::SingleClick();
}

/**
 * Pop this bug into multiple null and garbage bugs
 */
void BugMulti::PopBug()
{
	for (int i = 0; i < NewBugs2; i++)
	{
		auto locX = this->GetX() + rand() % Distance;
		auto locY = this->GetY() + rand() % Distance;
		auto speed = this->GetSpeed();
		this->GetGame()->CreateFatBug(mProgram, locX, locY, speed);
	}

	for (int i = 0; i < NewBugs1; i++)
	{
		auto locX = this->GetX() + rand() % Distance;
		auto locY = this->GetY() + rand() % Distance;
		auto speed = this->GetSpeed();
		this->GetGame()->CreateNullBug(mProgram, locX, locY, speed);
	}
}