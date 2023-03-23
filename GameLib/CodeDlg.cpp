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
CodeDlg::CodeDlg(FatBug* Bug, wxWindow* parent, std::wstring code, std::string pass)
{
	wxDialog::Create(parent, wxID_ANY, L"Bug Squash IDE", wxDefaultPosition,
					 wxDefaultSize, wxDEFAULT_DIALOG_STYLE | wxTRANSPARENT_WINDOW, L"Bug Squash IDE");
	mCode = code;
	mPass = pass;
	mBug = Bug;
	textBox = new wxTextCtrl(this, wxID_ANY, mCode, wxDefaultPosition, wxDefaultSize,
							 wxTE_MULTILINE | wxTE_RICH | wxScrolledWindowStyle, wxDefaultValidator, wxTextCtrlNameStr);
    okButton = new wxButton(this, wxID_OK , "OK", wxDefaultPosition, wxDefaultSize);



    auto sizer = new wxBoxSizer( wxVERTICAL );

    sizer->Add(textBox,1, wxEXPAND | wxALL );
    sizer->Add(okButton,1, wxALIGN_CENTER | wxALL );
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
	auto code = textBox->GetValue().ToStdString();
	// Still need to build regex test to look for the pass value in the stored text
	std::regex key;
	key.assign(pass);
	return std::regex_search(code, key);

}

/**
* Function to pause the game on open
*/
void CodeDlg::OnOpen()
{
	mBug->GetGame()->SetPaused(true);
}