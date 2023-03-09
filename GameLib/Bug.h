/**
 * @file Bug.h
 * @author Team BedBug
 *
 *
 */

#include "GameObject.h"
#include "ObjectVisitor.h"

#ifndef PROJECT1BEDBUG_GAMELIB_BUG_H
#define PROJECT1BEDBUG_GAMELIB_BUG_H

/**
 * Base class for a bug
 * This applies to all of the bug
 * object in the game.
 */
class Bug : public GameObject
{
private:
	/// Bug speed in the X direction
	/// in pixels per second
	double mSpeedX;

	/// Bug speed in the Y direction
	/// in pixels per second
	double mSpeedY;

public:
	/// Default constructor (disabled)
	Bug() = delete;

	/// Copy constructor (disabled)
	Bug(const Bug &) = delete;

	/// Assignment operator
	void operator=(const Bug &) = delete;

	/**
	 * Accept a visitor
	  * @param visitor The visitor we accept
	  */
	virtual void Accept(ObjectVisitor* visitor) = 0;


protected:
	Bug(Game *game, const std::wstring &filename);

	void Update(double elapsed);
/**
	wxXmlNode *XmlSave(wxXmlNode *node);
	void XmlLoad(wxXmlNode *node);
*/
	void BugSpeed(double speedX, double speedY);


};

#endif //PROJECT1BEDBUG_GAMELIB_BUG_H
