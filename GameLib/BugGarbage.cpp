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

