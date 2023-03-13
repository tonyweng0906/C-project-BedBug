/**
 * @file ScoreBoard.h
 * @author Alec Gardiner
 */

#ifndef PROJECT1BEDBUG_SCOREBOARD_H
#define PROJECT1BEDBUG_SCOREBOARD_H


class ScoreBoard {
public:
    void AddFixed(){mFixed++;}
    void AddMissed(){mMissed++;}
    void AddOops(){mOops++;}

private:
    /// fixed score
    int mFixed = 0;

    /// Missed score
    int mMissed = 0;

    /// oops score
    int mOops = 0;


};


#endif //PROJECT1BEDBUG_SCOREBOARD_H
