/**
 * @file VisitorTest.cpp
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
#include <BugCounterVisitor.h>


class VisitorTest : public ::testing::Test
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

};

TEST_F(VisitorTest, Construct){
	Game game;
}


TEST_F(VisitorTest, Load) {

	// Create an aquarium
	Game game;
	Game game2;
	Game game3;
	//
	// First test, saving an empty aquarium
	//


	game.Load(L"Level/level0.xml");


	cout <<game.GetPlayArea()->NumberOfObject() << endl;

	ASSERT_TRUE(game.GetPlayArea()->NumberOfObject() == 4);

	BugCounterVisitor visitor1;
	game.Accept(&visitor1);

	cout << visitor1.GetNumBugs() << endl;

	ASSERT_TRUE(visitor1.GetNumBugs()== 3);

	game2.Load(L"Level/level1.xml");

	cout << game2.GetPlayArea()->NumberOfObject() << endl;

	ASSERT_TRUE(game2.GetPlayArea()->NumberOfObject() == 13);

	BugCounterVisitor visitor2;
	game2.Accept(&visitor2);

	cout << visitor2.GetNumBugs() << endl;

	ASSERT_TRUE(visitor2.GetNumBugs()== 12);

	game3.Load(L"Level/level2.xml");

	cout << game3.GetPlayArea()->NumberOfObject() << endl;
	ASSERT_TRUE(game3.GetPlayArea()->NumberOfObject() == 27);

	BugCounterVisitor visitor3;
	game3.Accept(&visitor3);

	cout << visitor3.GetNumBugs() << endl;

	ASSERT_TRUE(visitor3.GetNumBugs()== 24);


//	TestAllTypesWithSpeed(L"Level/level1.xml");

}

TEST_F(VisitorTest, VisitorTest)
{
	// test other game
	Game gameTest;
	std::shared_ptr<GameObject> item1;
	std::shared_ptr<GameObject> item2;
	gameTest.GetPlayArea()->ClearObject();

	// add bugGarbage
	item1 = std::make_shared<BugGarbage>(&gameTest);
	gameTest.GetPlayArea()->Add(item1);
	item1->SingleClick();
	item2 = std::make_shared<BugGarbage>(&gameTest);
	gameTest.GetPlayArea()->Add(item2);

	//add null
	item1 = std::make_shared<BugNull>(&gameTest);
	gameTest.GetPlayArea()->Add(item1);
	item1->SingleClick();
	item2 = std::make_shared<BugNull>(&gameTest);
	gameTest.GetPlayArea()->Add(item2);

	//add feature
	item1 = std::make_shared<Feature>(&gameTest);
	gameTest.GetPlayArea()->Add(item1);
	item1->SingleClick();
	item2 = std::make_shared<Feature>(&gameTest);
	gameTest.GetPlayArea()->Add(item2);

	cout << gameTest.GetPlayArea()->NumberOfObject() << endl;
	ASSERT_TRUE(gameTest.GetPlayArea()->NumberOfObject() == 6);

	BugCounterVisitor visitorTest;
	gameTest.Accept(&visitorTest);

	cout << visitorTest.GetNumBugs() << endl;

	ASSERT_TRUE(visitorTest.GetNumBugs() == 3);
}