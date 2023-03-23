/**
 * @file BugRedundancy.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "BugRedundancy.h"

using namespace std;

/// Bug Name
const std::string BugName = "redundancy";

/// The bug base image
const std::wstring RedundancyFlyImageName = L"images/redundancy-fly-base.png";

/// The bug top image
const std::wstring RedundancyFlyTopImageName = L"images/redundancy-fly-top.png";

/// The left wing image
const std::wstring RedundancyFlyLeftWingImageName = L"images/redundancy-fly-lwing.png";

/// The right wing image
const std::wstring RedundancyFlyRightWingImageName = L"images/redundancy-fly-rwing.png";

/// The splat image
const std::wstring RedundancyFlySplatImageName = L"images/redundancy-fly-splat.png";

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
	mImageLeftWing = std::make_shared<wxImage>(RedundancyFlyLeftWingImageName);
	mImageRightWing =  std::make_shared<wxImage>(RedundancyFlyRightWingImageName);
	mImageTop = std::make_shared<wxImage>(RedundancyFlyTopImageName);
}


void BugRedundancy::Update(double elapsed)
{
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
		dc->Rotate(mWingRotation);
		dc->DrawBitmap(mRightWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(FirstWingSetX+WingSetXOffset ,WingSetY );
		dc->Rotate(mWingRotation);
		dc->DrawBitmap(mRightWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(2*WingSetXOffset +FirstWingSetX ,WingSetY );
		dc->Rotate(mWingRotation);
		dc->DrawBitmap(mRightWingBitmap, -50, -50, 100, 100);
		dc->PopState();

		dc->PushState();
		dc->Translate(3*WingSetXOffset +FirstWingSetX ,WingSetY );
		dc->Rotate(mWingRotation);
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