/**
 * @file CodeDlg.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "CodeDlg.h"
#include "regex"
#include "FatBug.h"

/**
 * Constructor for the code dialog box
 * @param parent window to bind to as parent
 * @param code text to display for user to edit
 */
CodeDlg::CodeDlg(FatBug* Bug, wxWindow* parent, std::wstring code, std::wstring pass)
{
	wxDialog::Create(parent, wxID_ANY, L"Bug Squash IDE", wxDefaultPosition,
					 wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxTRANSPARENT_WINDOW, L"Bug Squash IDE");
	mCode = code;
	mPass = pass;
	mBug = Bug;
	textBox = new wxTextCtrl(this, wxID_ANY, mCode, wxDefaultPosition, wxDefaultSize,
							 wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);

	//Bind(wxCloseEvent, &CodeDlg::OnClose, this, wxID_EXIT);
	Bind(wxEVT_CLOSE_WINDOW, &CodeDlg::OnClose, this, wxID_EXIT);

}


/**
 * Function to test if the correct code has been
 * inserted into the dialogue box
 * @param pass solution for the coding challenge
 * @return true if code is correct, false otherwise
 */
bool CodeDlg::testCode(std::wstring pass)
{
	// This will probably be called from a function in FatBug
	// and the return value will indicate whether it squishes or not

	// This will return the text stored in the text box
	auto code = textBox->GetValue();
	// Still need to build regex test to look for the pass value in the stored text
	return false;
}

/**
 * Function to set behavior on the dialog box closing
 * @param event Close Event
 */
void CodeDlg::OnClose(wxCloseEvent& event)
{
	mBug->GetGame()->SetPaused(false);
}

/**
* Function to pause the game on open
*/
void CodeDlg::OnOpen()
{
	mBug->GetGame()->SetPaused(true);
}