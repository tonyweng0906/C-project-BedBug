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
	FatBug* mBug;

public:
	CodeDlg(FatBug* Bug, wxWindow* parent, std::wstring code, std::string pass);
	bool testCode(std::string pass);
	void OnClose(wxCloseEvent &event);
	void OnOpen();
};

#endif //PROJECT1BEDBUG_GAMELIB_CODEDLG_H
