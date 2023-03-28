/**
 * @file CodeDlg.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "CodeDlg.h"
#include "regex"
#include "FatBug.h"
#include <wx/regex.h>

/**
 * Constructor for the code dialog box
 * @param parent window to bind to as parent
 * @param code text to display for user to edit
 */
CodeDlg::CodeDlg(wxWindow* parent, std::wstring code)
{
	wxDialog::Create(parent, wxID_ANY, L"Bug Squash IDE", wxDefaultPosition,
            wxSize( 490,510 ), wxDEFAULT_DIALOG_STYLE | wxTRANSPARENT_WINDOW, L"Bug Squash IDE");
	mCode = code;
	textBox = new wxTextCtrl(this, wxID_ANY, mCode, wxDefaultPosition, wxDefaultSize,
							 wxTE_MULTILINE | wxTE_RICH | wxScrolledWindowStyle | wxALWAYS_SHOW_SB, wxDefaultValidator, wxTextCtrlNameStr);
    okButton = new wxButton(this, wxID_OK , "OK", wxDefaultPosition, wxDefaultSize);

    auto sizer = new wxBoxSizer( wxVERTICAL );

    sizer->Add(textBox,10, wxEXPAND | wxALL );
    sizer->Add(okButton, 0.5, wxALIGN_CENTER | wxALL );
    // Set the sizer for this frame
    SetSizer( sizer );

    // Layout (place) the child windows.
    Layout();


}


/**
 * Function to test if the correct code has been
 * inserted into the dialogue box
 * @param pass solution for the coding challenge
 * @return true if code is correct, false otherwise
 */
bool CodeDlg::testCode(std::string pass)
{
	// This will probably be called from a function in FatBug
	// and the return value will indicate whether it squishes or not

	// This will return the text stored in the text box
	auto code = textBox->GetValue();
	// Create the Regex Key to test against
	auto key = wxRegEx(pass);
	// Test text against key
	return key.Matches(code);
}
