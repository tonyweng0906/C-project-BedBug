/**
 * @file ScoreBoard.h
 * @author Alec Gardiner
 * Base class for scoreboard
 */

#ifndef PROJECT1BEDBUG_SCOREBOARD_H
#define PROJECT1BEDBUG_SCOREBOARD_H

#include "GameObject.h"
/**
 * Base class for scoreboard
 */
class ScoreBoard{
public:
    void AddFixed();
    void AddMissed();
    void AddOops();
    void Draw(std::shared_ptr<wxGraphicsContext> graphics);
    void Reset();


private:
    /// fixed score
    int mFixed = 0;

    /// Missed score
    int mMissed = 0;

    /// oops score
    int mOops = 0;



};


#endif //PROJECT1BEDBUG_SCOREBOARD_H
