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
class ScoreBoard : public GameObject{
public:
    void AddFixed();
    void AddMissed();
    void AddOops();

private:
    /// fixed score
    int mFixed = 0;

    /// Missed score
    int mMissed = 0;

    /// oops score
    int mOops = 0;


};


#endif //PROJECT1BEDBUG_SCOREBOARD_H
