/**
 * @file PlayAreaTest.cpp
 * @author Neil Khedekar
 */


#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <BugGarbage.h>
#include <BugNull.h>
#include <BugRedundancy.h>
#include <PlayArea.h>
#include <Feature.h>
#include <Program.h>
using namespace std;
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

class PlayAreaTest : public ::testing::Test
{

};

TEST_F(PlayAreaTest, Construct){
	Game game;
}
