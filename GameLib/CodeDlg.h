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

class CodeDlg : public wxDialog
{
private:
	wxTextCtrl *textBox;
    wxButton *okButton;
	std::wstring mCode;
	std::string mPass;


public:
	CodeDlg(wxWindow* parent, std::wstring code);
	bool testCode(std::string pass);
};

#endif //PROJECT1BEDBUG_GAMELIB_CODEDLG_H
