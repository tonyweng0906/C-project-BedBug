/**
 * @file BugNull.cpp
 * @author Xin Weng
 */


#include "pch.h"
#include "BugNull.h"

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugNull::BugNull(Game *game, std::shared_ptr<wxBitmap> image) : Bug(game, image)
{

}