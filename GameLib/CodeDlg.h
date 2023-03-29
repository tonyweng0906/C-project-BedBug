/**
 * @file CodeDlg.h
 * @author Aron DuBois
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_CODEDLG_H
#define PROJECT1BEDBUG_GAMELIB_CODEDLG_H


#include "Game.h"

class FatBug;

/**
 * Base class for IDE question
 */

class CodeDlg : public wxDialog
{
private:
	/// the text
	wxTextCtrl *textBox;
	/// the ok button
    wxButton *okButton;
	/// The code show in the IDE
	std::wstring mCode;
	/// the passing code
	std::string mPass;


public:
	CodeDlg(wxWindow* parent, std::wstring code);
	bool testCode(std::string pass);
};

#endif //PROJECT1BEDBUG_GAMELIB_CODEDLG_H
