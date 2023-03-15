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

/********Scoreboard Constants**********/
/// Score font size to use
const int ScoreSize = 85;

/// Lable for score font size to use
const int LabelSize = 40;

/// The font color to use
const wxColour FontColor = wxColour(0, 200, 200);

/// Left score X location. The right score is
/// the width minus this value.
const int LeftScoreX = 150;

/// Score Y location
const int ScoreY = 20;

/// Score label Y location
const int ScoreLabelY = 100;



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

    wxFont ScoreFont(wxSize(0,ScoreSize),wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_EXTRABOLD);
    dc.SetFont(ScoreFont);
    dc.SetTextForeground(FontColor);
    dc.DrawText(L"6",LeftScoreX,ScoreY);
    dc.DrawText(L"1",rect.GetWidth()/2,ScoreY);
    dc.DrawText(L"0",rect.GetWidth()-LeftScoreX,ScoreY);

    wxFont LabelFont(wxSize(0,LabelSize),wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_EXTRABOLD);
    dc.SetFont(LabelFont);
    dc.SetTextForeground(FontColor);
    GetTextExtent("Fixed",mLabelWidth,mLabelHeight);

    dc.DrawText(L"Fixed",LeftScoreX,ScoreLabelY);
    dc.DrawText(L"Missed",rect.GetWidth()/2,ScoreLabelY);
    dc.DrawText(L"Oops",rect.GetWidth()-LeftScoreX,ScoreLabelY);



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