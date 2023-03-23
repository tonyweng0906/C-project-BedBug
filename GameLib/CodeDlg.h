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
	std::wstring mPass;
	FatBug* mBug;

public:
	CodeDlg(FatBug* Bug, wxWindow* parent, std::wstring code, std::wstring pass);
	bool testCode(std::wstring pass);
	void OnClose(wxCloseEvent &event);
	void OnOpen();
};

#endif //PROJECT1BEDBUG_GAMELIB_CODEDLG_H
