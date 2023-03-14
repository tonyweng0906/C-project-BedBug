/**
 * @file BugRedundancy.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "BugRedundancy.h"

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugRedundancy::BugRedundancy(Game *game, std::shared_ptr<wxBitmap> image) : Bug(game, image)
{

}