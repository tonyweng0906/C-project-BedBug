/**
 * @file Program.cpp
 * @author Xin Weng
 */

#include "Program.h"

/// Program image filename
const std::wstring ProgramImage = L"images/laptop.png";

/// Program name font size
const int ProgramNameFontSize = 22;

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
Program::Program(Game *game) : GameObject(game,ProgramImage)
{

}