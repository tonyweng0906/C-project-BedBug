/**
 * @file GameTest.cpp
 * @author Xin Weng
 */





#include <pch.h>
#include "gtest/gtest.h"
#include <Game.h>
#include <BugGarbage.h>
#include <BugNull.h>
#include <BugRedundancy.h>
#include <Feature.h>
#include <Program.h>
using namespace std;
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>

class GameTest : public ::testing::Test
{
protected:
	/**
	* Read a file into a wstring and return it.
	* @param filename Name of the file to read
	* @return File contents
	*/
	wstring ReadFile(const wxString &filename)
	{
		ifstream t(filename.ToStdString());
		wstring str((istreambuf_iterator<char>(t)),
					istreambuf_iterator<char>());

		return str;
	}

	void TestAllTypesWithSpeed(wxString filename)
	{
		cout << "Temp file: " << filename << endl;

		auto xml = ReadFile(filename);
		cout << xml << endl;

		// Ensure the positions are correct

		// Ensure the positions are correct
		ASSERT_TRUE(regex_search(xml, wregex(L"<bug type=\"redundancy\" x=\"100\" y=\"600\" "
											 "speed=\"120\" start=\"0\"")));
		ASSERT_TRUE(regex_search(xml, wregex(L"<feature x=\"100\" y=\"800\" "
											 "speed=\"120\" start=\"0\"")));
	}
};

TEST_F(GameTest, Construct){
Game game;
}

TEST_F(GameTest, Load) {

	// Create an aquarium
	Game game;
	Game game2;
	Game game3;
	//
	// First test, saving an empty aquarium
	//
	TestAllTypesWithSpeed(L"Level/level0.xml");

	game.Load(L"Level/level0.xml");


	cout <<game.GetPlayArea().NumberOfObject() << endl;

	ASSERT_TRUE(game.GetPlayArea().NumberOfObject() == 3);

	game2.Load(L"Level/level1.xml");

	cout << game2.GetPlayArea().NumberOfObject() << endl;

	ASSERT_TRUE(game2.GetPlayArea().NumberOfObject() == 13);


	game3.Load(L"Level/level2.xml");

	cout << game3.GetPlayArea().NumberOfObject() << endl;
	ASSERT_TRUE(game3.GetPlayArea().NumberOfObject() == 27);

//	TestAllTypesWithSpeed(L"Level/level1.xml");

}
