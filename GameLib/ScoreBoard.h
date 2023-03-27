/**
 * @file ScoreBoard.h
 * @author Alec Gardiner
 */

#ifndef PROJECT1BEDBUG_SCOREBOARD_H
#define PROJECT1BEDBUG_SCOREBOARD_H

#include "GameObject.h"
/*
 * class for game scoreboard
 */
class ScoreBoard{
public:
    void AddFixed();
    void AddMissed();
    void AddOops();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);
    void Reset();


private:
    /// fixed score
    int mFixed = 0;

    /// Missed score
    int mMissed = 0;

    /// oops score
    int mOops = 0;

    double mXOffset = 0;
    double mYOffset = 0;
    double mScale = 0;
    bool mShrinked = false;


};


#endif //PROJECT1BEDBUG_SCOREBOARD_H
