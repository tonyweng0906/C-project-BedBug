/**
 * @file ScoreBoard.cpp
 * @author Alec Gardiner
 */

#include "pch.h"
#include "ScoreBoard.h"

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
