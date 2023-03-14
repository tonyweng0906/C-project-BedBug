/**
 * @file ScoreBoard.cpp
 * @author Alec Gardiner
 */

#include "pch.h"
#include "ScoreBoard.h"

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

/*
 * increments the Fixed score count
 */
void ScoreBoard::AddFixed() {
    mFixed++;
    return;
}

/*
 * increments the Missed count
 */
void ScoreBoard::AddMissed(){
    mMissed++;
    return;
}

/*
 * increments the Oops count
 */
void ScoreBoard::AddOops(){
    mOops++;
    return;
}
