/**
 * @file Bug.h
 * @author Team BedBug
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUG_H
#define PROJECT1BEDBUG_GAMELIB_BUG_H

#include "GameObject.h"
#include "ObjectVisitor.h"
#include "Program.h"

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

	/// Starting X position of the bug
	double mStartX;

	/// Starting Y position of the bug
	double mStartY;

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

	/**
	 * Get the starting X position of the bug
	 * @return The starting X position
	 */
	double GetStartX() const { return mStartX; }

	/**
	 * Get the starting Y position of the bug
	 * @return The starting Y position
	 */
	double GetStartY() const { return mStartY; }

protected:
	Bug(Game *game, std::shared_ptr<wxBitmap> image);

	void Update(double elapsed);

	void XmlLoad(wxXmlNode *node);

	void BugSpeed(double speedX, double speedY);
};

#endif //PROJECT1BEDBUG_GAMELIB_BUG_H
