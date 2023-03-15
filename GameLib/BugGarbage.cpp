/**
 * @file BugGarbage.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include <sstream>
#include <iostream>
#include "BugGarbage.h"


/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugGarbage::BugGarbage(Game *game) : Bug(game)
{

}

/**
* Save this item to an XML node
 * @param node The node we are going to be a child of
 * @return Allocated node
*/

// GameObject XmlSave function not yet built

//wxXmlNode* BugGarbage::XmlSave(wxXmlNode *node)
//{
//	auto itemNode = GameObject::XmlSave(node);
//	itemNode->AddAttribute(L"type", L"garden");
//  return itemNode;
//}