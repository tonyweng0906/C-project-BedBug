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
#include <memory>
#include <Program.h>
using namespace std;
#include <wx/filename.h>

class PlayAreaTest : public ::testing::Test {
protected:
	Game *game;
	PlayArea playArea;

	void SetUp() override {
		game = new Game(); // create a new Game object
		playArea = *game->GetPlayArea();
		playArea.ClearObject();
	}

	void TearDown() override {
		delete game; // release the memory used by the Game object
	}

};

TEST_F(PlayAreaTest, AddBug) {
	std::shared_ptr<GameObject> bug = std::make_shared<BugGarbage>(game);
	playArea.Add(bug);
	EXPECT_EQ(playArea.NumberOfObject(), 1);
}


