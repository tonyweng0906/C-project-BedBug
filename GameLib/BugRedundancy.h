/**
 * @file BugRedundancy.h
 * @author Xin Weng
 *
 * Base class for redundancy bug
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H
#define PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H

#include <wx/graphics.h>
#include "Bug.h"
#include "ScoreBoard.h"

/**
 * Base class for redundancy bug
 */
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

	/// score board of the bug
    ScoreBoard mScoreBoard;
	/// wing rotation rate
	double mWingRotation = 0;
	/// rotate clockwise or not
	double mClockwise = true;

	/// Track if this Redundancy fly is an original
	bool mOriginal = true;

	/// Track if this bug has been popped
	bool mPopped = false;

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

	/// adding the score
    void AddScore() override;

	/**
     * Update the animation
     * @param elapsed Time past
     */
	void Update(double elapsed);

	/**
     * Draw the object
     * @param graphics Draw
     */
	void Draw (std::shared_ptr<wxGraphicsContext> graphics);

	void SingleClick() override;

	void PopBug();

	bool MoveFinish() override;

	/**
     * Setter for if this bug is an original
     * @param state At original or not
     */
	void SetOriginal(bool state){mOriginal = state;}

    /// adding the missing
    void Missed() override;

//	void Draw (std::shared_ptr<wxGraphicsContext> graphics);
};

#endif //PROJECT1BEDBUG_GAMELIB_BUGREDUNDANCY_H
