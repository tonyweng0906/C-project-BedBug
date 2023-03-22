/**
 * @file ScoreBoard.cpp
 * @author Alec Gardiner
 */

#include "pch.h"
#include "ScoreBoard.h"
using namespace std;

/// Game area in virtual pixels
const static int Width = 1250;

/// Game area height in virtual pixels
const static int Height = 1000;

/// Scale to shrink to when in shrink mode
const double ShrinkScale = 0.75;

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


void ScoreBoard::Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height) {

    //
    // Automatic Scaling
    //
    auto scaleX = double(width) / double(Width);
    auto scaleY = double(height) / double(Height);
    mScale = std::min(scaleX, scaleY);

    if(mShrinked)
    {
        mScale *= ShrinkScale;
    }

    mXOffset = (width - Width * mScale) / 2;
    mYOffset = (height - Height * mScale) / 2;

    graphics->PushState();

    graphics->Translate(mXOffset, mYOffset);
    graphics->Scale(mScale, mScale);

    /****Drawing ScoreBoard stuff****/
    wxFont LabelFont(wxSize(0,LabelSize),wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_EXTRABOLD);
    graphics->SetFont(LabelFont,FontColor);
    graphics->DrawText(L"Fixed",LeftScoreX-30,ScoreLabelY);
    graphics->DrawText(L"Missed",Width/2-40,ScoreLabelY);
    graphics->DrawText(L"Oops",Width-LeftScoreX-25,ScoreLabelY);
    wxFont ScoreFont(wxSize(0,ScoreSize),wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_EXTRABOLD);
    graphics->SetFont(ScoreFont,FontColor);
    graphics->DrawText(to_string(mFixed),LeftScoreX,ScoreY);
    graphics->DrawText(to_string(mMissed),Width/2,ScoreY);
    graphics->DrawText(to_string(mOops),Width-LeftScoreX,ScoreY);
    /*****End Scoreboard Stuff*********/
}


/**
 * increments the Fixed score count
 */
void ScoreBoard::AddFixed() {
    mFixed++;
    return;
}

/**
 * increments the Missed count
 */
void ScoreBoard::AddMissed(){
    mMissed++;
    return;
}

/**
 * increments the Oops count
 */
void ScoreBoard::AddOops(){
    mOops++;
    return;
}

