/**
 * @file BugGarbage.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGGARBAGE_H
#define PROJECT1BEDBUG_GAMELIB_BUGGARBAGE_H

#include "Bug.h"

class BugGarbage : public Bug
{
private:

public:

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(BugVisitor* visitor) override { visitor->VisitBugGarbage(this);}

};

#endif //PROJECT1BEDBUG_GAMELIB_BUGGARBAGE_H
