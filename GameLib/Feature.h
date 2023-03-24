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
#include "ScoreBoard.h"

class Feature : public Bug
{
private:

    ScoreBoard mScoreBoard;
protected:



public:
	Feature(Game *game);
	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitFeature(this);}

	void XmlLoad(wxXmlNode *node);

	/**
	 * Set the target program
	  * @param program the target
	  */
	void SetProgram(std::shared_ptr<Program> program) {mProgram = program;}

    void AddScore() override;
};

#endif //PROJECT1BEDBUG_GAMELIB_FEATURE_H
