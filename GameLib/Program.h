/**
 * @file Program.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_PROGRAM_H
#define PROJECT1BEDBUG_GAMELIB_PROGRAM_H

#include "GameObject.h"

/**
 * Base class for program
 */
class Program : public GameObject
{
private:
	/// name of the Program
	std::wstring mName;
public:
	/// Constructor
	Program(Game *game);

	/// Default constructor (disabled)
	Program() = delete;

	/// Copy constructor (disabled)
	Program(const Program&) = delete;

	void XmlLoad(wxXmlNode *node);

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitProgram(this);}

	/**
	* Draw this program
	* @param dc Device context to draw on
	*/
	void Draw(std::shared_ptr<wxGraphicsContext> dc) override;
};

#endif //PROJECT1BEDBUG_GAMELIB_PROGRAM_H
