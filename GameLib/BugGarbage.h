/**
 * @file BugGarbage.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGGARBAGE_H
#define PROJECT1BEDBUG_GAMELIB_BUGGARBAGE_H

#include "Bug.h"
#include "ScoreBoard.h"

class BugGarbage : public Bug
{
private:
    ScoreBoard mScoreBoard;
public:
	/// constructor
	BugGarbage(Game* game);

	/// Default constructor (disabled)
	BugGarbage() = delete;

	/// Copy constructor (disabled)
	BugGarbage(const BugGarbage&) = delete;

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitBugGarbage(this);}

    void AddScore();
};

#endif //PROJECT1BEDBUG_GAMELIB_BUGGARBAGE_H
