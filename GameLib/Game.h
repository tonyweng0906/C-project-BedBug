/**
 * @file Game.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_GAME_H
#define PROJECT1BEDBUG_GAMELIB_GAME_H

class Game
{
private:
	double mXOffset = 0;
	double mYOffset = 0;
	double mScale = 0;
	bool mShrinked = false;

public:
	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
	/// Set the Shrinked when click on view
	void SetShrinked();
	/// Return is Shrinked or not
	/// @return bool
	bool GetShrinked(){return mShrinked;}
};

#endif //PROJECT1BEDBUG_GAMELIB_GAME_H
