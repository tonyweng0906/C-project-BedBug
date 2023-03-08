/**
 * @file Game.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_GAME_H
#define PROJECT1BEDBUG_GAMELIB_GAME_H

#include <memory>
#include <vector>

#include "Bug.h"

class BugVisitor;

class Game
{
private:
	double mXOffset = 0;
	double mYOffset = 0;
	double mScale = 0;
	bool mShrinked = false;
	std::vector<std::shared_ptr<Bug>> mBugs;

public:
	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	/// Set the Shrinked when click on view
	void SetShrinked();

	/// Return is Shrinked or not
	/// @return bool
	bool GetShrinked(){return mShrinked;}

	/// Accept the visitor
	/// @param visitor Bug visitor
	void Accept(BugVisitor *visitor);
};

#endif //PROJECT1BEDBUG_GAMELIB_GAME_H
