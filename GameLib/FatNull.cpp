/**
 * @file FatNull.cpp
 * @author Aron DuBois
 */

#include "FatNull.h"

/**
* Constructor
 * @param game the game this is a member of
*/
FatNull::FatNull(Game *game) : BugNull(game)
{

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

