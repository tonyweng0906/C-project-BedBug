/**
 * @file BugRedundancy.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "BugRedundancy.h"
#include "Game.h"

using namespace std;

/// Bug Name
const std::string BugName = "redundancy";

/// Wing flapping period in seconds
const double WingPeriod = 0.2;

/// Starting rotation angle for wings in radians
const double WingRotateStart = 0.0;

/// End rotation angle for wings in radians
const double WingRotateEnd = 1.5;

/// How many sets of wings does this bug have?
const int NumberOfSetsOfWings = 4;

/// Number of virtual pixels between each of the wing sets
const int WingSetXOffset = 12;

/// X position relative to center of bug for the first (back) wing set
const int FirstWingSetX = -36;

/// Y position relative to center of bug for the right wings. The negative
/// of this is the Y position for the left wings.
const int WingSetY = 5;

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugRedundancy::BugRedundancy(Game *game) : Bug(game,BugName)
{
	mImageLeftWing = game->GetPlayArea().GetImage("leftWing");
	mImageRightWing =  game->GetPlayArea().GetImage("rightWing");
	mImageTop = game->GetPlayArea().GetImage("redundancyTop");

}


void BugRedundancy::Update(double elapsed)
{
	if (mClockwise)
	{
		mWingRotation += WingPeriod/(WingRotateEnd/4);
		if (mWingRotation >= 1.5)
		{
			mClockwise = false;
		}
	}
	else
	{
		mWingRotation -= WingPeriod/(WingRotateEnd/4);
		if (mWingRotation <= 0)
		{
			mClockwise = true;
		}
	}
	Bug::Update(elapsed);

}

void BugRedundancy::Draw(std::shared_ptr<wxGraphicsContext> dc)
{
	if (mObjectBitmap.IsNull())
	{
		mObjectBitmap = dc->CreateBitmapFromImage(*mObjectImage);
	}
	if (mSplatBitmap.IsNull())
	{
		mSplatBitmap = dc->CreateBitmapFromImage(*mSplatImage);
	}
	if (mLeftWingBitmap.IsNull())
	{
		mLeftWingBitmap = dc->CreateBitmapFromImage(*mImageLeftWing);
	}
	if (mRightWingBitmap.IsNull())
	{
		mRightWingBitmap = dc->CreateBitmapFromImage(*mImageRightWing);
	}
	if (mTopBitmap.IsNull())
	{
		mTopBitmap = dc->CreateBitmapFromImage(*mImageTop);
	}


	if(!mSplat){
		dc->PushState();

		dc->Translate(mX,mY);
		dc->Rotate(mRotation);
		dc->DrawBitmap(mObjectBitmap, -50, -50, 100, 100);


		//left wing
		dc->PushState();
		dc->Translate(FirstWingSetX ,-WingSetY );
		dc->Rotate(mWingRotation);
		dc->DrawBitmap(mLeftWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(FirstWingSetX+WingSetXOffset ,-WingSetY );
		dc->Rotate(mWingRotation);
		dc->DrawBitmap(mLeftWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(2*WingSetXOffset +FirstWingSetX ,-WingSetY );
		dc->Rotate(mWingRotation);
		dc->DrawBitmap(mLeftWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(3*WingSetXOffset +FirstWingSetX ,-WingSetY );
		dc->Rotate(mWingRotation);
		dc->DrawBitmap(mLeftWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		//right wing
		dc->PushState();
		dc->Translate(FirstWingSetX ,WingSetY );
		dc->Rotate(-mWingRotation);
		dc->DrawBitmap(mRightWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(FirstWingSetX+WingSetXOffset ,WingSetY );
		dc->Rotate(-mWingRotation);
		dc->DrawBitmap(mRightWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(2*WingSetXOffset +FirstWingSetX ,WingSetY );
		dc->Rotate(-mWingRotation);
		dc->DrawBitmap(mRightWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(3*WingSetXOffset +FirstWingSetX ,WingSetY );
		dc->Rotate(-mWingRotation);
		dc->DrawBitmap(mRightWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		// draw the top
		dc->PushState();
		dc->DrawBitmap(mTopBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PopState();
	}
	else{
		int objectWid = mSplatImage->GetWidth();
		int objectHit = mSplatImage->GetHeight();
		dc->DrawBitmap(mSplatBitmap, mX-(objectWid/2), mY-(objectHit/2), objectWid, objectHit);
	}





}

void BugRedundancy::AddScore() {
    mScoreBoard.AddFixed();
}

/**
 * Set Redundancy Bug behavior on single click
 */
void BugRedundancy::SingleClick()
{
	if(mOriginal)
	{
		this->PopBug();
	}

}
void BugRedundancy::PopBug()
{
	mPopped = true;
}

/**
* Determine if we should remove the bug
* @return bool true if we should remove false otherwise
*/
bool BugRedundancy::MoveFinish()
{
	if(mPopped)
	{
		return true;
	}
	else
	{
		Bug::MoveFinish();
	}

}