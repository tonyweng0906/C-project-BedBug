/**
 * @file Feature.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_FEATURE_H
#define PROJECT1BEDBUG_GAMELIB_FEATURE_H

#include "Bug.h"

class Feature : public Bug
{
private:

public:

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(BugVisitor* visitor) override { visitor->VisitFeature(this);}
};

#endif //PROJECT1BEDBUG_GAMELIB_FEATURE_H
