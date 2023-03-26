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
#include "BugCounterVisitor.h"
#include "BugMulti.h"

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
	 Load(L"Level/level1.xml");
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
	mPlayArea.Draw(graphics);

	// hide the bugs
	if (!mShrinked)
	{
		wxBrush rectBrush(*wxBLACK);
		graphics->SetBrush(rectBrush);
		graphics->DrawRectangle(-300, -300, 300, Height+300);
		graphics->DrawRectangle(Width, -300, 500, Height+300);
	}



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
	std::vector<std::shared_ptr<Program>> programList;
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
		programList.push_back(program);
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
	for(auto program : programList)
	{
		mPlayArea.Add(program);
	}
	mPlayArea.ReverseOrder();

}

/**
 * Handle a node of type item.
 * @param node XML node
 */
void Game::XmlItem(wxXmlNode *node, std::shared_ptr<Program> program)
{
	// A pointer for the object we are loading
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
		if(type == L"multi")
		{
			item = std::make_shared<BugMulti>(this);
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
		if(node->GetChildren())
		{
			item->makeIDE(mMainFrame);
		}
	}
}

/**
 * Handle updates for animation
 * @param elapsed The time since the last update
 */
void Game::Update(double elapsed)
{
	mPlayArea.Update(elapsed);
	if(!BugCount())
	{
		switch(mLevel)
		{
			case 0:
				Load(L"Level/level1.xml");
				mLevel = 1;
				break;
			case 1:
				Load(L"Level/level2.xml");
				mLevel = 2;
				break;
			case 2:
				Load(L"Level/level3.xml");
				mLevel = 3;
				break;
			case 3:
				Load(L"Level/level3.xml");
				break;
		}

	}
}

/**
 * Create a Redundancy Fly to add to the game
 * Bug begins moving immediately
 * @param program Program this bug will target
 * @param locX X Location this bug begins at
 * @param locY Y location this bug begins at
 * @param speed Speed of this bug
 */
void Game::CreateRedundancyFly(std::shared_ptr<Program> program, double locX, double locY, double speed)
{
	auto item = std::make_shared<BugRedundancy>(this);
	mPlayArea.Add(item);
	item->SetProgram(program);
	item->SetLocation(locX, locY);
	item->SetOriginal(false);
	item->SetSpeed(speed);
}

/**
 * Create a Fatbug to add to the game
 * Bug begins moving immediately
 * @param program Program this bug will target
 * @param locX X Location this bug begins at
 * @param locY Y location this bug begins at
 * @param speed Speed of this bug
 */
void Game::CreateFatBug(std::shared_ptr<Program> program, double locX, double locY, double speed)
{
	auto item = std::make_shared<BugGarbage>(this);
	mPlayArea.Add(item);
	item->SetProgram(program);
	item->SetLocation(locX, locY);
	item->SetSpeed(speed);
}

/**
 * Create a NullBug to add to the game
 * Bug begins moving immediately
 * @param program Program this bug will target
 * @param locX X Location this bug begins at
 * @param locY Y location this bug begins at
 * @param speed Speed of this bug
 */
void Game::CreateNullBug(std::shared_ptr<Program> program, double locX, double locY, double speed)
{
	auto item = std::make_shared<BugNull>(this);
	mPlayArea.Add(item);
	item->SetProgram(program);
	item->SetLocation(locX, locY);
	item->SetSpeed(speed);
}


/**
 * Count the number of bugs in the game
 */
int Game::BugCount()
{
	BugCounterVisitor visitor;
	mPlayArea.Accept(&visitor);
	return visitor.GetNumBugs();
}


/**
 * Accept a visitor for the collection
 * @param visitor The visitor for the collection
 */
void Game::Accept(ObjectVisitor *visitor)
{
	mPlayArea.Accept(visitor);
}