/**
 * @file Feature.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_FEATURE_H
#define PROJECT1BEDBUG_GAMELIB_FEATURE_H

#include "GameObject.h"

class Feature : public GameObject
{
private:

public:

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitFeature(this);}
};

#endif //PROJECT1BEDBUG_GAMELIB_FEATURE_H
