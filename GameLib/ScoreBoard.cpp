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

int ScoreBoard::GetFixed() {return mFixed;}


/*
 * increments the Missed count
 */
void ScoreBoard::AddMissed(){
    mMissed++;
    return;
}

int ScoreBoard::GetMissed() {return mMissed;}

/*
 * increments the Oops count
 */
void ScoreBoard::AddOops(){
    mOops++;
    return;
}

int ScoreBoard::GetOops() {return mOops;}