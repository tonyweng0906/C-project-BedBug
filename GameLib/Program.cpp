/**
 * @file Program.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "Program.h"

/// Program Name
const std::string ProgramName = "program";

/// Program name font size
const int ProgramNameFontSize = 22;

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
Program::Program(Game *game) : GameObject(game,ProgramName)
{

}

/**
 * Load the attributes for an item node.
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
*/
void Program::XmlLoad(wxXmlNode *node)
{
	GameObject::XmlLoad(node);
	mName = node->GetAttribute(L"name", L"");
}


void Program::Draw(std::shared_ptr<wxGraphicsContext> dc)
{
	GameObject::Draw(dc);
	wxFont font(wxSize(0, ProgramNameFontSize),
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_BOLD);
	dc->SetFont(font, *wxWHITE);
	double wid, hit;
	dc->GetTextExtent(mName, &wid, &hit);
	dc->DrawText(mName,GetX()- wid/2, GetY() - hit/2);
}
