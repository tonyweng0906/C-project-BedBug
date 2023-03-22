/**
 * @file FatBug.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "FatBug.h"


/**
 * define behavior for when the bug is double clicked
 * Code Window should be called from the FatBug on a double click
 */
void FatBug::showWindow()
{
	//CodeDlg dlg(window, mCode);
	mIDE->OnOpen();
	mIDE->ShowModal();
	mGame->SetResumed(true);
	mGame->SetPaused(false);

	// Function testCode not yet built
	// once built, if true, we squish this bug
	auto SquishBug = mIDE->testCode(mPass);
}

/**
 * constructor for this fatbug
 * @param pass solution for the coding challenge
 */
FatBug::FatBug(Game* game)
{
	mGame = game;
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
	mPass = child->GetAttribute(L"pass", L"");
	child = child->GetChildren();
	mCode = child->GetContent();
}

/**
 * Create the code window for the bug to display
 * when double clicked
 * @param window wxWindow *window
 */
void FatBug::makeIDE(wxWindow* window)
{
	mIDE = std::make_unique<CodeDlg>(this, window, mCode, mPass);
}
