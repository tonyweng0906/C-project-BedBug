/**
 * @file BugNull.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGNULL_H
#define PROJECT1BEDBUG_GAMELIB_BUGNULL_H

#include "Bug.h"

class BugNull : public Bug
{
private:

public:
	/// Constructor
	BugNull(Game *game, std::shared_ptr<wxBitmap> image);

/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitBugNull(this);}
};

#endif //PROJECT1BEDBUG_GAMELIB_BUGNULL_H
