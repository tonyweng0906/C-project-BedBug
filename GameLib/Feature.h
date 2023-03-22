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

class Feature : public Bug
{
private:
	/// Bug speed in the X direction
	/// in pixels per second
	double mSpeed = 0;

	/// start time
	double mStart = 0;

	/// rotate degree
	double mRotation = 0;

/// Program the bug will target
	std::shared_ptr<Program> mProgram;

	/// The item bitmap
	wxGraphicsBitmap mSubBugBitmap;

	/// The item sub bitmap
	wxGraphicsBitmap mSubMovingBugBitmap1;

	/// The item sub bitmap
	wxGraphicsBitmap mSubMovingBugBitmap2;

	/// The item sub bitmap
	wxGraphicsBitmap mSubMovingBugBitmap3;

	/// The item sub bitmap
	wxGraphicsBitmap mSubMovingBugBitmap4;

	/// The item sub bitmap
	wxGraphicsBitmap mSubMovingBugBitmap5;

	/// The item sub bitmap
	wxGraphicsBitmap mSubMovingBugBitmap6;
protected:



public:
	Feature(Game *game);
	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitFeature(this);}

	void XmlLoad(wxXmlNode *node);

	void Update(double elapsed) override;

	void Draw(std::shared_ptr<wxGraphicsContext> dc) override;
	/**
	 * Set the target program
	  * @param program the target
	  */
	void SetProgram(std::shared_ptr<Program> program) {mProgram = program;}
};

#endif //PROJECT1BEDBUG_GAMELIB_FEATURE_H
