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

public:
	/// Constructor
	BugRedundancy(Game *game, std::shared_ptr<wxBitmap> image);
/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitBugRedundancy(this);}

};

#endif //PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H
