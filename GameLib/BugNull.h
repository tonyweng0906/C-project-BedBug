/**
 * @file BugNull.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGNULL_H
#define PROJECT1BEDBUG_GAMELIB_BUGNULL_H

#include "Bug.h"
#include "ScoreBoard.h"

/**
 * Base class for null bug
 */
class BugNull : public Bug
{
private:
public:
	/// Constructor
	BugNull(Game *game);

/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitBugNull(this);}

    void AddScore() override;
};

#endif //PROJECT1BEDBUG_GAMELIB_BUGNULL_H
