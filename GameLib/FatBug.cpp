/**
 * @file FatBug.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "FatBug.h"
#include "CodeDlg.h"

/**
 * define behavior for when the bug is double clicked
 * Code Window should be called from the FatBug on a double click
 */
void FatBug::codeWindow(wxWindow* window)
{
	CodeDlg dlg(window, mCode);
	dlg.ShowModal();
	// Function testCode not yet built
	// once built, if true, we squish this bug
	auto SquishBug = dlg.testCode(mPass);
}

/**
 * constructor for this fatbug
 * @param pass solution for the coding challenge
 * @param code the text of the coding challenge
 */
FatBug::FatBug()
{

}

/**
 * Load the attributes for a fatbug node.
 *
 * This is the  derived class version that loads the attributes
 * common to all fatbugs.
 *
 *
 * @param node The Xml node we are loading the item from
 */
void FatBug::XmlLoad(wxXmlNode *node)
{
	auto child = node->GetChildren();

}
