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
const int GarbageBugNumSpriteImages = 6;

/**
* Constructor
 * @param game the game this is a member of
 *
*/
BugGarbage::BugGarbage(Game *game) : Bug(game, BugName, GarbageBugNumSpriteImages )
{

}

void BugGarbage::AddScore() {
    ScoreBoard *scoreBoard = GetBoard();
    scoreBoard->AddFixed();
}

