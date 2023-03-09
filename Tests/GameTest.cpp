/**
 * @file GameTest.cpp
 * @author Xin Weng
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>

using namespace std;

TEST(GameTest, Construct){
	Game game;
}