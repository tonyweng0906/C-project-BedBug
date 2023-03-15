/**
 * @file BugRedundancy.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "BugRedundancy.h"

/**
* Constructor
 * @param game the game this is a member of
 * @param image the image this object is represented by
*/
BugRedundancy::BugRedundancy(Game* game, double startX, double startY, double speedX, double speedY, double startTime)
	: Bug(game, game->GetImage(wxT("redundancy-fly-base.png")))
	, mStartTime(startTime)
	, mTimeElapsed(0)
{
	BugSpeed(speedX, speedY);
	mStartX = startX;
	mStartY = startY;
	mX = startX;
	mY = startY;
	mAngle = atan2(game->GetProgram()->GetY() - mY, game->GetProgram()->GetX() - mX);
}

void BugRedundancy::Update(double elapsed)
{
	if (mTimeElapsed >= mStartTime) {
		double newX = mX + elapsed * mSpeedX * cos(mAngle);
		double newY = mY + elapsed * mSpeedY * sin(mAngle);
		mX = newX;
		mY = newY;
		mAngle = atan2(GetGame()->GetProgram()->GetY() - mY, GetGame()->GetProgram()->GetX() - mX);

		// Check if the bug has reached the program
		double distanceToProgram = sqrt(pow(mX - GetGame()->GetProgram()->GetX(), 2) + pow(mY - GetGame()->GetProgram()->GetY(), 2));
		if (distanceToProgram < 5) {
			GetGame()->GetProgram()->SquishBug();
			SetPendingRemoval(true);
		}
	}
	else {
		mTimeElapsed += elapsed;
	}
}