/**
 * @file CodeDlg.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "CodeDlg.h"
#include "regex"

/**
 * Constructor for the code dialog box
 * @param parent window to bind to as parent
 * @param code text to display for user to edit
 */
CodeDlg::CodeDlg(wxWindow* parent, std::wstring code, std::wstring pass)
{
	wxDialog::Create(parent, wxID_ANY, L"Bug Squash IDE", wxDefaultPosition,
					 wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxTRANSPARENT_WINDOW, L"Bug Squash IDE");
	mCode = code;
	mPass = pass;

	textBox = new wxTextCtrl(this, wxID_ANY, mCode, wxDefaultPosition, wxDefaultSize,
							 wxTE_MULTILINE | wxTE_RICH, wxDefaultValidator, wxTextCtrlNameStr);

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
