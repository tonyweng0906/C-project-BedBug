/**
 * @file FatBug.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "FatBug.h"
#include "CodeDlg.h"

/**
 * define behavior for when the bug is double clicked
 */
void FatBug::doubleClicked(wxWindow* window)
{
	CodeDlg dlg(window, mCode);
	dlg.ShowModal();
}

/**
 * constructor for this fatbug
 * @param pass solution for the coding challenge
 * @param code the text of the coding challenge
 */
FatBug::FatBug(std::wstring pass, std::wstring code) : mPass(pass), mCode(code)
{
}
