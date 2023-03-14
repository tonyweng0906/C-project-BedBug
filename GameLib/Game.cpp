/**
 * @file Game.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "Game.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>

/// Game area in virtual pixels
const static int Width = 1250;

/// Game area height in virtual pixels
const static int Height = 1000;

/// Scale to shrink to when in shrink mode
const double ShrinkScale = 0.75;


/**
 * Game Constructor
 */
 Game::Game()
 {

 }


/**
 * Draw the game area
 * @param graphics The graphics context to draw on
 * @param width Width of the client window
 * @param height Height of the client window
 */
void Game::OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height)
{
	//
	// Automatic Scaling
	//
	auto scaleX = double(width) / double(Width);
	auto scaleY = double(height) / double(Height);
	mScale = std::min(scaleX, scaleY);

	if(mShrinked)
	{
		mScale *= ShrinkScale;
	}

	mXOffset = (width - Width * mScale) / 2;
	mYOffset = (height - Height * mScale) / 2;

	graphics->PushState();

	graphics->Translate(mXOffset, mYOffset);
	graphics->Scale(mScale, mScale);

	// From here on you are drawing virtual pixels
	wxBrush rectBrush(*wxWHITE);
	graphics->SetBrush(rectBrush);
	graphics->DrawRectangle(0, 0, Width, Height);

	//
	// Your drawing code goes here
	//

	//
	// Draw some text for testing, can be deleted anytime
	//
	wxFont font(wxSize(0, 30),
				wxFONTFAMILY_SWISS,
				wxFONTSTYLE_NORMAL,
				wxFONTWEIGHT_BOLD);
	graphics->SetFont(font, *wxBLACK);
	graphics->DrawText(L"Testing", 1250/2, 100);
	graphics->DrawText(L"Testing", 100, 500);
	graphics->DrawText(L"Testing", 1100, 500);
	graphics->DrawText(L"Testing", 1250/2, 900);
	graphics->SetFont(font, *wxWHITE);
	graphics->DrawText(L"I am here", 600, -100);



	graphics->PopState();
}

void Game::SetShrinked()
{
	mShrinked = !mShrinked;
}



/**
 * Load the Game from a  XML file.
 *
 * Opens the XML file and reads the nodes, creating items as appropriate.
 *
 * @param filename The filename of the file to load the game from.
 */
void Game::Load(const wxString &filename)
{
	wxXmlDocument xmlDoc;
	if(!xmlDoc.Load(filename))
	{
		wxMessageBox(L"Unable to load Game file");
		return;
	}
	//mPlayArea->ClearObject();

	// Get the XML document root node
	auto root = xmlDoc.GetRoot();

	//
	// Traverse the children of the root
	// node of the XML document in memory!!!!
	//
	auto child = root->GetChildren();
	for( ; child; child=child->GetNext())
	{
		auto name = child->GetName();
		if(name == L"item")
		{
			XmlItem(child);
		}
	}
}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void Game::XmlItem(wxXmlNode *node)
{

}

