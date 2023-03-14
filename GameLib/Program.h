/**
 * @file Program.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_PROGRAM_H
#define PROJECT1BEDBUG_GAMELIB_PROGRAM_H

#include "GameObject.h"

class Program : public GameObject
{
private:

public:

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitProgram(this);}
};

#endif //PROJECT1BEDBUG_GAMELIB_PROGRAM_H
