/**
 * @file GameView.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "GameView.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include "ids.h"

/// Frame duration in milliseconds
const int FrameDuration = 30;



/**
 * Initialize the game view class.
 * @param parent The parent window for this class+
 */
void GameView::Initialize(wxFrame* parent)
{
	Create(parent, wxID_ANY,
		   wxDefaultPosition, wxDefaultSize,
		   wxFULL_REPAINT_ON_RESIZE);
	SetBackgroundStyle(wxBG_STYLE_PAINT);
	Bind(wxEVT_PAINT, &GameView::OnPaint, this);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnShrink, this, IDM_ONSHRINK);
	parent->Bind(wxEVT_UPDATE_UI, &GameView::OnUpdateShrink, this, IDM_ONUPDATESHRINK);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel0, this, IDM_ONLEVEL0);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel1, this, IDM_ONLEVEL1);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel2, this, IDM_ONLEVEL2);
	parent->Bind(wxEVT_COMMAND_MENU_SELECTED, &GameView::OnLevel3, this, IDM_ONLEVEL3);

	Bind(wxEVT_LEFT_DOWN, &GameView::OnLeftDown, this);
	Bind(wxEVT_LEFT_DCLICK, &GameView::OnLeftDoubleClick, this);

	mTimer.SetOwner(this);
	mTimer.Start(FrameDuration);
	mStopWatch.Start();
}

/**
 * Paint event, draws the window.
 * @param event Paint event object
 */
void GameView::OnPaint(wxPaintEvent& event)
{
	// Create a double-buffered display context
	wxAutoBufferedPaintDC dc(this);

	// Compute the time that has elapsed
	// since the last call to OnPaint.
	auto newTime = mStopWatch.Time();
	auto elapsed = (double)(newTime - mTime) * 0.001;
	mTime = newTime;

	// Clear the image to black
	wxBrush background(*wxBLACK);
	dc.SetBackground(background);
	dc.Clear();


	// Create a graphics context
	auto gc =
		std::shared_ptr<wxGraphicsContext>(wxGraphicsContext::Create(dc));

	// Tell the game class to draw
	wxRect rect = GetRect();
	mGame.OnDraw(gc, rect.GetWidth(), rect.GetHeight());


}

void GameView::OnShrink(wxCommandEvent& event)
{
	mGame.SetShrinked();
	Refresh();
}

/**
 * Refresh the system
 * @param event Menu event
 */
void GameView::OnTimerEvent(wxTimerEvent & event)
{
	Refresh();
}


/**
 * Update handler for View>Shrink menu option
 * @param event Update event
 */
void GameView::OnUpdateShrink(wxUpdateUIEvent& event)
{
	event.Check(mGame.GetShrinked());
}

/**
 * Handle the left mouse button down event
 * @param event
 */
void GameView::OnLeftDown(wxMouseEvent &event)
{

}

/**
* Handle the left mouse button double click event
* @param event
*/
void GameView::OnLeftDoubleClick(wxMouseEvent &event)
{


}

/**
* When open level 0
* @param event
*/
void GameView::OnLevel0(wxCommandEvent& event)
{
	mGame.Load(L"Level/level0.xml");
	Refresh();
}

/**
* When open level 1
* @param event
*/
void GameView::OnLevel1(wxCommandEvent& event)
{
	mGame.Load(L"Level/level1.xml");
	Refresh();
}

/**
* When open level 2
* @param event
*/
void GameView::OnLevel2(wxCommandEvent& event)
{
	mGame.Load(L"Level/level2.xml");
	Refresh();
}

/**
* When open level 3
* @param event
*/
void GameView::OnLevel3(wxCommandEvent& event)
{
	mGame.Load(L"Level/level3.xml");
	Refresh();
}