/**
 * @file FatNull.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "FatNull.h"

/**
* Constructor
 * @param game the game this is a member of
*/
FatNull::FatNull(Game *game) : BugNull(game), FatBug(game)
{
	Bug::SetFatSize();
}


/**
 * Load the attributes for a FatNull node.
 *
 * This is the  derived class version that loads the attributes
 * common to all items and fatbugs
 *
 *
 * @param node The Xml node we are loading the item from
 */
void FatNull::XmlLoad(wxXmlNode *node)
{
	Bug::XmlLoad(node);
	FatBug::XmlLoad(node);
}

/**
 * Set behavior for when this bug is double clicked on
 */
void FatNull::DoubleClick()
{
	FatBug::showWindow();
	if(FatBug::TestCode())
	{
		Squish();
        ScoreBoard *scoreBoard = GetBoard();
        scoreBoard->AddFixed();
	}
}

/**
 * Disable singleClick behavior on this fatbug
 */
void FatNull::SingleClick()
{

}

/**
* calls the make ide function in fatbug class
 * @param wxWindow parent window for the ide
*/
void FatNull::makeIDE(wxWindow* window)
{
	FatBug::makeIDE(window);
}