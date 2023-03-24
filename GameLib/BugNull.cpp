/**
 * @file BugNull.cpp
 * @author Xin Weng
 */


#include "pch.h"
#include "BugNull.h"

/// Bug Name
const std::string BugName = "null";

/// Number of sprite images
const int NullBugNumSpriteImages = 7;

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugNull::BugNull(Game *game) : Bug(game,BugName, NullBugNumSpriteImages)
{

}

void BugNull::AddScore() {
    mScoreBoard.AddFixed();
}