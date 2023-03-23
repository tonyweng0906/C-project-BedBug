/**
 * @file FatGarbage.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "FatGarbage.h"

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
FatGarbage::FatGarbage(Game *game) : BugGarbage(game), FatBug(game)
{

}


/**
 * Load the attributes for a FatGarbage node.
 *
 * This is the  derived class version that loads the attributes
 * common to all items and fatbugs
 *
 *
 * @param node The Xml node we are loading the item from
 */
void FatGarbage::XmlLoad(wxXmlNode *node)
{
	Bug::XmlLoad(node);
	FatBug::XmlLoad(node);
}

/**
 * Set behavior for when this bug is double clicked on
 */
void FatGarbage::DoubleClick()
{
	FatBug::showWindow();
}

/**
 * Disable singleClick behavior on this fatbug
 */
 void FatGarbage::SingleClick()
 {

 }

/**
* calls the make ide function in fatbug class
 * @param wxWindow parent window for the ide
*/
void FatGarbage::makeIDE(wxWindow* window)
{
	FatBug::makeIDE(window);
}