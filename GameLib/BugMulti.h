/**
 * @file BugMulti.h
 * @author Aron DuBois
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGMULTI_H
#define PROJECT1BEDBUG_GAMELIB_BUGMULTI_H

#include "Bug.h"
#include "ScoreBoard.h"

/**
 * Base class for team feature
 */

class BugMulti : public Bug
{
private:
	/// Scoreboard the this bug
	ScoreBoard mScoreBoard;
public:
	BugMulti(Game *game);

	/// Default constructor (disabled)
	BugMulti() = delete;

	/// Copy constructor (disabled)
	BugMulti(const BugMulti&) = delete;

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitBugMulti(this);}

	/// Adding the score
	void AddScore() override;

	void SingleClick() override;

	void PopBug();

};

#endif //PROJECT1BEDBUG_GAMELIB_BUGMULTI_H
