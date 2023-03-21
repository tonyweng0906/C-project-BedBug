/**
 * @file FatGarbage.h
 * @author Aron DuBois
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_FATGARBAGE_H
#define PROJECT1BEDBUG_GAMELIB_FATGARBAGE_H

#include "BugGarbage.h"
#include "FatBug.h"

class FatGarbage : public BugGarbage, public FatBug
{
private:

public:
	/// constructor
	FatGarbage(Game* game);

	/// Default constructor (disabled)
	FatGarbage() = delete;

	/// Copy constructor (disabled)
	FatGarbage(const BugGarbage&) = delete;

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { //visitor->VisitFatGarbage(this);
		 }

	void XmlLoad(wxXmlNode *node);

};

#endif //PROJECT1BEDBUG_GAMELIB_FATGARBAGE_H
