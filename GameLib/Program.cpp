/**
 * @file Program.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "Program.h"

/// Program Name
const std::string ProgramName = "program";

/// Program name font size
const int ProgramNameFontSize = 22;

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
Program::Program(Game *game) : GameObject(game,ProgramName)
{

}