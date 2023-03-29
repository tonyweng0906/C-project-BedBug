/**
 * @file Feature.h
 * @author Xin Weng
 *
 * Base class for feature
 */

#ifndef PROJECT1BEDBUG_GAMELIB_FEATURE_H
#define PROJECT1BEDBUG_GAMELIB_FEATURE_H

#include "GameObject.h"
#include "Bug.h"
#include "ScoreBoard.h"

/**
 * Base class for feature
 */
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

	void XmlLoad(wxXmlNode *node);

	/**
	 * Set the target program
	  * @param program the target
	  */
	void SetProgram(std::shared_ptr<Program> program) {mProgram = program;}

	/// adding the score
    void AddScore() override;

	/// adding the missing
    void Missed() override;
};

#endif //PROJECT1BEDBUG_GAMELIB_FEATURE_H
