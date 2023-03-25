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

class BugMulti : public Bug
{
private:
	ScoreBoard mScoreBoard;
public:
	/// Constructor
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

	void AddScore() override;

	void SingleClick() override;

	void PopBug();

};

#endif //PROJECT1BEDBUG_GAMELIB_BUGMULTI_H
