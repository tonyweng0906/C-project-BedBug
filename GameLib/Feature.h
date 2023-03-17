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
	/// Bug speed in the X direction
	/// in pixels per second
	double mSpeed = 0;

	/// start time
	double mStart = 0;

/// Program the bug will target
	std::shared_ptr<Program> mProgram;

protected:



public:
	Feature(Game *game);
	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitFeature(this);}

	void XmlLoad(wxXmlNode *node);

	void Update(double elapsed);

	/**
	 * Set the target program
	  * @param program the target
	  */
	void SetProgram(std::shared_ptr<Program> program) {mProgram = program;}
};

#endif //PROJECT1BEDBUG_GAMELIB_FEATURE_H
