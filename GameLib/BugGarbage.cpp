/**
 * @file BugGarbage.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "BugGarbage.h"

/// Bug Name
const std::string BugName = "garbage";

/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/// The splat image
const std::wstring GarbageBugSplatImageName = L"images/blue-maize-splat.png";

/// Number of sprite images
const int GarbageBugNumSpriteImages = 5;

void BugGarbage::AddScore() {
    mScoreBoard.AddFixed();
}

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugGarbage::BugGarbage(Game *game) : Bug(game, BugName )
{

}

