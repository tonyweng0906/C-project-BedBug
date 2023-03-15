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

	/// The timer that allows for animation
	wxTimer mTimer;
	/// Stopwatch used to measure elapsed time
	wxStopWatch mStopWatch;
	/// The last stopwatch time
	long mTime = 0;

	void OnPaint(wxPaintEvent& event);
	void OnShrink(wxCommandEvent &event);
	void OnTimerEvent(wxTimerEvent & event);
	void OnUpdateShrink(wxUpdateUIEvent &event);
	void OnLeftDown(wxMouseEvent &event);
	void OnLeftDoubleClick(wxMouseEvent &event);
	void OnLevel0(wxCommandEvent &event);
	void OnLevel1(wxCommandEvent &event);
	void OnLevel2(wxCommandEvent &event);
	void OnLevel3(wxCommandEvent &event);

public:

	void Initialize(wxFrame *parent);


};

#endif //PROJECT1BEDBUG_GAMELIB_GAMEVIEW_H
