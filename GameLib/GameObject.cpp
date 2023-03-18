/**
 * @file GameObject.cpp
 * @author Team BedBug
 */

#include "pch.h"
#include "GameObject.h"
#include "Game.h"
#include <memory>
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

bool mMirror = false;   ///< True mirrors the item image

using namespace std;

/// Distance in pixels to how far away a bug can be clicked on
const double BugHitRange = 50;

/**
 * Destructor
 */
GameObject::~GameObject()
{

}


/**
 * Constructor
 * @param game The game this item is a member of
 * @param filename the loaded in xml file
 */
GameObject::GameObject(Game *game, const std::wstring & name) : mGame(game)
{
	//mGameImage = make_unique<wxImage>(filename, wxBITMAP_TYPE_ANY);
	//mGameBitmap = make_unique<wxBitmap>(*mGameImage);
	//*mItemBitmap = *image;
	mObjectImage = std::make_shared<wxImage>(name);

}

/**
 * Compute the distance from this item to another item
 * @param item Item we are computing the distance to
 * @return Distance in pixels
 */
double GameObject::DistanceTo(std::shared_ptr<GameObject> gameObject)
{
	auto dx = gameObject->GetX() - GetX();
	auto dy = gameObject->GetY() - GetY();
	return sqrt(dx * dx + dy * dy);
}

/**
 * Test to see if we hit near this object with a mouse.
 * @param x X position to test
 * @param y Y position to test
 * @return true if hit.
 */
bool GameObject::HitTest(int x, int y)
{
	double dx = x - GetX();
	double dy = y - GetY();

	return sqrt(dx * dx + dy * dy) < BugHitRange;

	// Previous pre-build code

//	double wid = mGameBitmap->GetWidth();
//	double hit = mGameBitmap->GetHeight();
//
//	// Make x and y relative to the top-left corner of the bitmap image
//	// Subtracting the center makes x, y relative to the image center
//	// Adding half the size makes x, y relative to theimage top corner
//	double testX = x - GetX() + wid / 2;
//	double testY = y - GetY() + hit / 2;
//
//	// Test to see if x, y are in the image
//	if (testX < 0 || testY < 0 || testX >= wid || testY >= hit)
//	{
//		// We are outside the image
//		return false;
//	}
//
//	// Test to see if x, y are in the drawn part of the image
//	// If the location is transparent, we are not in the drawn
//	// part of the image
//	return !mGameImage->IsTransparent((int)testX, (int)testY);
}

void GameObject::Draw(std::shared_ptr<wxGraphicsContext> dc)
{
//	double wid = mGameBitmap->GetWidth();
//	double hit = mGameBitmap->GetHeight();
//	dc->DrawBitmap(*mGameBitmap,
//				   int(GetX() - wid / 2),
//				   int(GetY() - hit / 2));
	if (mObjectBitmap.IsNull())
	{
		mObjectBitmap = dc->CreateBitmapFromImage(*mObjectImage);
	}
	int objectWid = mObjectImage->GetWidth();
	int objectHit = mObjectImage->GetHeight();

	dc->DrawBitmap(mObjectBitmap, mX-(objectWid)/2, mY-(objectHit)/2, objectWid, objectHit);
}


/**
 * Load the attributes for an item node.
 * This is the  base class version that loads the attributes
 * common to all items. Override this to load custom attributes
 * for specific items.
 *
 * @param node The Xml node we are loading the item from
*/
void GameObject::XmlLoad(wxXmlNode *node)
{
	node->GetAttribute(L"x", L"0").ToDouble(&mX);
	node->GetAttribute(L"y", L"0").ToDouble(&mY);
}

/**
* Get the width of image
 * @return width of the fish
*/
int GameObject::GetWidth() const { return mObjectImage->GetWidth();}

/**
* Get the height of image
 * @return height of the fish
*/
int GameObject::GetHeight() const { return mObjectImage->GetHeight();}