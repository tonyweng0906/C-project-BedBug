/**
 * @file ObjectTest.cpp
 * @author Aron
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <GameObject.h>
#include <Game.h>
#include <FatGarbage.h>


/// The bug sprite image
const std::wstring GarbageBugSpriteImageName = L"images/blue-maize-bug.png";

/** Mock Class for testing the class object */
class ObjectMock : public GameObject {
public:

	ObjectMock(Game *game) : GameObject(game, GarbageBugSpriteImageName) {}
};

TEST(ObjectTest, Construct)
{
	Game game;
	ObjectMock object(&game);
}

TEST(ObjectTest, GettersSetters){
	Game game;
	ObjectMock object(&game);

	// Test Initial Values
	ASSERT_NEAR(0, object.GetX(), 0.0001);
	ASSERT_NEAR(0, object.GetY(), 0.0001);

	// Test SetLocation, GetX, and GetY
	object.SetLocation(10.5, 17.2);
	ASSERT_NEAR(10.5, object.GetX(), 0.0001);
	ASSERT_NEAR(17.2, object.GetY(), 0.0001);

	// Test a second with different values
	object.SetLocation(-72, -107);
	ASSERT_NEAR(-72, object.GetX(), 0.0001);
	ASSERT_NEAR(-107, object.GetY(), 0.0001);
}

TEST(ObjectTest, HitTest)
{
	Game game;
	FatGarbage object(&game);

	object.SetLocation(100, 200);

	// Center of the object should be a true
	ASSERT_TRUE(object.HitTest(100, 200));

	// Within hit range

	// Left of the object
	ASSERT_TRUE(object.HitTest(60, 200));

	// Right of the object
	ASSERT_TRUE(object.HitTest(140, 200));

	// Above the object
	ASSERT_TRUE(object.HitTest(100, 160));

	// Below the object
	ASSERT_TRUE(object.HitTest(100, 240));


	//  Outside of hit range

	// Left of the object
	ASSERT_FALSE(object.HitTest(10, 200));

	// Right of the object
	ASSERT_FALSE(object.HitTest(200, 200));

	// Above the object
	ASSERT_FALSE(object.HitTest(100, 0));

	// Below the object
	ASSERT_FALSE(object.HitTest(100, 300));


}