/**
 * @file GameView.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_GAMEVIEW_H
#define PROJECT1BEDBUG_GAMELIB_GAMEVIEW_H

#include "Game.h"

/**
 * View class for our game
 */
class GameView  : public wxWindow
{
private:
	/// An object that describes our game
	Game  mGame;

	void OnPaint(wxPaintEvent& event);

public:

	void Initialize(wxFrame *parent);
};

#endif //PROJECT1BEDBUG_GAMELIB_GAMEVIEW_H
