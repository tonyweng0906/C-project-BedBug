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

public:
	FatBug(std::wstring pass, std::wstring code);
	void codeWindow(wxWindow* window);


};

#endif //PROJECT1BEDBUG_GAMELIB_FATBUG_H
