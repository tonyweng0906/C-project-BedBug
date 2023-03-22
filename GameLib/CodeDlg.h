/**
 * @file CodeDlg.h
 * @author Aron DuBois
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_CODEDLG_H
#define PROJECT1BEDBUG_GAMELIB_CODEDLG_H

class CodeDlg : public wxDialog
{
private:
	wxTextCtrl *textBox;
	std::wstring mCode;
	std::wstring mPass;

public:
	CodeDlg(wxWindow* parent, std::wstring code, std::wstring pass);
	bool testCode(std::wstring pass);
};

#endif //PROJECT1BEDBUG_GAMELIB_CODEDLG_H
