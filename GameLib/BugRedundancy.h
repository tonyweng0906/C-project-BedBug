/**
 * @file BugRedundancy.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H
#define PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H

#include "Bug.h"

class BugRedundancy : public Bug
{
private:
	double mStartTime; ///< The time at which the bug should start moving towards the program
	double mTimeElapsed; ///< The time that has elapsed since the bug started moving
	double mAngle; ///< The angle at which the bug should move towards the program

public:
	/// constructor
	BugRedundancy(Game* game, double startX, double startY, double speedX, double speedY, double startTime);

	/// Default constructor (disabled)
	BugRedundancy() = delete;

	/// Copy constructor (disabled)
	BugRedundancy(const BugRedundancy&) = delete;

	void Update(double elapsed) override;
	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitBugRedundancy(this);}

};

#endif //PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H
