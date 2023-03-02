/**
 * @file CodeDlg.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "CodeDlg.h"

/**
 * Constructor for the code dialog box
 * @param parent window to bind to as parent
 * @param code text to display for user to edit
 */
CodeDlg::CodeDlg(wxWindow* parent, std::wstring code)
{
	wxDialog::Create(parent, wxID_ANY, L"Bug Squash IDE", wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, code);

}


/**
 * Function to test if the correct code has been
 * inserted into the dialogue box
 * @param pass solution for the coding challenge
 * @return true if code is correct, false otherwise
 */
bool CodeDlg::testCode(std::wstring pass)
{
	return false;
}
