/**
 * @file BugNull.cpp
 * @author Xin Weng
 */


#include "pch.h"
#include "BugNull.h"

/// The bug sprite image
const std::wstring NullBugSpriteImageName = L"images/scarlet-gray-bug.png";

/// The splat image
const std::wstring NullBugSplatImageName = L"images/scarlet-gray-splat.png";

/// Number of sprite images
const int NullBugNumSpriteImages = 6;

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugNull::BugNull(Game *game) : Bug(game,NullBugSpriteImageName)
{

}

void BugNull::AddScore() {
    mScoreBoard.AddFixed();
}