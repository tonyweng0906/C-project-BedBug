/**
 * @file Feature.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_FEATURE_H
#define PROJECT1BEDBUG_GAMELIB_FEATURE_H

#include "GameObject.h"
#include "Bug.h"

class Feature : public Bug
{
private:


protected:



public:
	Feature(Game *game);
	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitFeature(this);}


};

#endif //PROJECT1BEDBUG_GAMELIB_FEATURE_H
