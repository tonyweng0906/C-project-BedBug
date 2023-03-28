/**
 * @file Feature.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "Feature.h"
#include "Program.h"
#include "Game.h"

/// Bug Name
const std::string BugName = "feature";


/// Number of sprite images
const int FeatureNumSpriteImages = 7;

/**
 * Constructor
 * @param game The game we are in
 */
Feature::Feature(Game *game) : Bug(game, BugName, FeatureNumSpriteImages)
{

}

/**
 * Load the attributes for a Feature node.
 *
 * This is the  derived class version that loads the attributes
 * common to all items.
 * @param node The Xml node we are loading the item from
 */
void Feature::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"speed", L"0").ToDouble(&mSpeed);
	node->GetAttribute(L"start", L"0").ToDouble(&mStart);
	Bug::XmlLoad(node);
}


void Feature::AddScore() {
    ScoreBoard *scoreBoard = GetBoard();
    scoreBoard->AddOops();
}
/**
 * Disables missed for features
 */
void Feature::Missed() {

}