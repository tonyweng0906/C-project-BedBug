/**
 * @file BugRedundancy.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H
#define PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H

#include <wx/graphics.h>
#include "Bug.h"

class BugRedundancy : public Bug
{
private:
	/// left wing image
	std::shared_ptr<wxImage> mImageLeftWing;
	/// right wing image
	std::shared_ptr<wxImage> mImageRightWing;
	/// top image
	std::shared_ptr<wxImage> mImageTop;

	/// left wing bitmap
	wxGraphicsBitmap mLeftWingBitmap;
	/// right wing bitmap
	wxGraphicsBitmap mRightWingBitmap;
	/// top bitmap
	wxGraphicsBitmap mTopBitmap;

public:
	/// constructor
	BugRedundancy(Game* game);

	/// Default constructor (disabled)
	BugRedundancy() = delete;

	/// Copy constructor (disabled)
	BugRedundancy(const BugRedundancy&) = delete;

	/// Assignment operator
	void operator=(const BugRedundancy &) = delete;

	//void Update(double elapsed) override;
	/**
     * Accept a visitor
     * @param visitor The visitor we accept
     */
	void Accept(ObjectVisitor* visitor) override { visitor->VisitBugRedundancy(this);}

//	void Draw (std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H
