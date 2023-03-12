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
*/

// Does not currently match GameObject constructor, game object has a file name being passed??

//BugGarbage::BugGarbage(Game *game) : GameObject(game)
//{
//	// Set image function likely to go in the Tile class?
//	//SetImage(GarbageImage);
//}

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