/**
 * @file FatBug.h
 * @author Aron DuBois
 *
 * Super class for fat bugs that have a coding challenge when double clicked
 */

#ifndef PROJECT1BEDBUG_GAMELIB_FATBUG_H
#define PROJECT1BEDBUG_GAMELIB_FATBUG_H

#include <string>
#include "GameObject.h"
#include "Program.h"
#include "CodeDlg.h"

/**
 * Super class for fat bugs that have a coding challenge when double clicked
 */
class FatBug
{
private:
	/// String we search for to pass the test
	std::wstring mPass;
	/// String of the broken code to display
	std::wstring mCode;
	/// IDE window for this bug
	std::unique_ptr<CodeDlg> mIDE = nullptr;
public:
	FatBug();
	void showWindow();
	virtual void XmlLoad(wxXmlNode *node);
	void makeIDE();


};

#endif //PROJECT1BEDBUG_GAMELIB_FATBUG_H
