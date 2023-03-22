/**
 * @file Game.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "Game.h"
#include <wx/dcbuffer.h>
#include <wx/graphics.h>
#include <memory>
#include "BugGarbage.h"
#include "BugNull.h"
#include "BugRedundancy.h"
#include "FatGarbage.h"
#include "FatNull.h"
#include "Feature.h"
#include "Program.h"

/// Game area in virtual pixels
const static int Width = 1250;

/// Game area height in virtual pixels
const static int Height = 1000;

/// Scale to shrink to when in shrink mode
const double ShrinkScale = 0.75;

/********Scoreboard Constants**********/
/// Score font size to use
const int ScoreSize = 85;

/// Lable for score font size to use
const int LabelSize = 40;

/// The font color to use
const wxColour FontColor = wxColour(0, 200, 200);

/// Left score X location. The right score is
/// the width minus this value.
const int LeftScoreX = 150;

/// Score Y location
const int ScoreY = 20;

/// Score label Y location
const int ScoreLabelY = 100;


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
	for (auto item : mPlayArea.GetObject())
	{
		item->Draw(graphics);
	}

	// hide the bugs
	if (!mShrinked)
	{
		wxBrush rectBrush(*wxBLACK);
		graphics->SetBrush(rectBrush);
		graphics->DrawRectangle(-300, -300, 300, Height+300);
		graphics->DrawRectangle(Width, -300, 300, Height+300);
	}
    /****Drawing ScoreBoard stuff****/
    wxFont LabelFont(wxSize(0,LabelSize),wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_EXTRABOLD);
    graphics->SetFont(LabelFont,FontColor);
    graphics->DrawText(L"Fixed",LeftScoreX-30,ScoreLabelY);
    graphics->DrawText(L"Missed",Width/2-40,ScoreLabelY);
    graphics->DrawText(L"Oops",Width-LeftScoreX-25,ScoreLabelY);

    wxFont ScoreFont(wxSize(0,ScoreSize),wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_EXTRABOLD);
    graphics->SetFont(ScoreFont,FontColor);
    graphics->DrawText(L"6",LeftScoreX,ScoreY);
    graphics->DrawText(L"1",Width/2,ScoreY);
    graphics->DrawText(L"0",Width-LeftScoreX,ScoreY);
    /*****End Scoreboard Stuff*********/


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
	mPlayArea.ClearObject();

	// Get the XML document root node
	auto root = xmlDoc.GetRoot();

	//
	// Traverse the children of the root
	// node of the XML document in memory!!!!
	//
	auto rootChild = root->GetChildren();
	for( ; rootChild; rootChild=rootChild->GetNext())
	{
		// program
		std::shared_ptr<Program> program = std::make_shared<Program>(this);
		mPlayArea.Add(program);
		program->XmlLoad(rootChild);

		//Bugs
		auto child = rootChild->GetChildren();
		for( ; child; child=child->GetNext())
		{

			auto name = child->GetName();
			if(name == L"bug")
			{
				XmlItem(child, program);
			}
			if(name == L"feature")
			{
				XmlItem(child, program);
			}
		}

	}

}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void Game::XmlItem(wxXmlNode *node, std::shared_ptr<Program> program)
{
//	 A pointer for the object we are loading
	std::shared_ptr<GameObject> item;
	// We have an item. What type?
	auto type = node->GetAttribute(L"type");
	// Check if node has child (is a fatbug)
	if (node->GetChildren())
	{
		if(type == L"garbage")
		{
			item = std::make_shared<FatGarbage>(this);
		}
		if(type == L"null")
		{
			item = std::make_shared<FatNull>(this);
		}
	}
	else
	{
		if(type == L"garbage")
		{
			item = std::make_shared<BugGarbage>(this);
		}
		if(type == L"redundancy")
		{
			item = std::make_shared<BugRedundancy>(this);
		}
		if(type == L"null")
		{
			item = std::make_shared<BugNull>(this);
		}
		if(node->GetName() == "feature")
		{
			item = std::make_shared<Feature>(this);
		}
	}

	if (item != nullptr)
	{
		mPlayArea.Add(item);
		item->XmlLoad(node);
		item->SetProgram(program);
	}
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
	mPlayArea.Update(elapsed);
}
