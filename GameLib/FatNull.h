/**
 * @file FatNull.h
 * @author Aron DuBois
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_FATNULL_H
#define PROJECT1BEDBUG_GAMELIB_FATNULL_H

#include "BugNull.h"
#include "FatBug.h"

/**
 * Base class for far null bug
 */

class FatNull : public BugNull, public FatBug
{
private:

public:
	/// constructor
	FatNull(Game* game);

	/// Default constructor (disabled)
	FatNull() = delete;

	/// Copy constructor (disabled)
	FatNull(const BugGarbage&) = delete;

	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitFatNull(this);
	}

	void XmlLoad(wxXmlNode *node);

	void DoubleClick() override;
	void SingleClick() override;
    void AddScore() override;
	void makeIDE(wxWindow *window);
};

#endif //PROJECT1BEDBUG_GAMELIB_FATNULL_H
