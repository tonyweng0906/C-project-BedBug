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

protected:
	/// Bug speed in the X direction
	/// in pixels per second
	double mSpeed = 0;

	/// start time
	double mStart = 0;

	/// Bug rotation in degrees
	double mRotation = 0;

	/// Bug is splat
	bool mSplat = false;

	/// The item sub bitmap
	wxGraphicsBitmap mSubBugBitmap;

	/// Image of the splat bug
	std::shared_ptr<wxImage> mSplatImage;

	/// Bitmap of the splat bug
	wxGraphicsBitmap mSplatBitmap;

	/// Program the bug will target
	std::shared_ptr<Program> mProgram;
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
	double GetSpeed() const { return mSpeed; }

	/**
	 * Set the target program
	  * @param program the target
	  */
	void SetProgram(std::shared_ptr<Program> program) {mProgram = program;}

	void Update(double elapsed) override;

	//void XmlLoad(wxXmlNode *node);

	void BugSpeed(double speedX, double speedY);

	/// Setter for bug speed
	void SetSpeed(double speed){mSpeed = speed;}

	virtual void XmlLoad(wxXmlNode *node);

	bool MoveFinish();

	void Draw(std::shared_ptr<wxGraphicsContext> dc) override;

	void Squish();

	bool HitTest(int x, int y) override;

	void SingleClick();

//	int GetWidth() const;
//
//	int GetHeight() const;
protected:
	Bug(Game *game, const std::string & name );


};

#endif //PROJECT1BEDBUG_GAMELIB_BUG_H
