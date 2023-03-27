/**
 * @file Game.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_GAME_H
#define PROJECT1BEDBUG_GAMELIB_GAME_H

#include <memory>
#include <vector>

#include "GameObject.h"
#include "Bug.h"
#include "PlayArea.h"

///Class for the Game part
class Game
{
private:
	double mXOffset = 0;
	double mYOffset = 0;
	double mScale = 0;
	bool mShrinked = false;

	/// bool to see if game is paused or not
	bool mPaused = false;
	/// bool lto track if the game has just resumed
	bool mResumed = false;
	/// Current level
	int mLevel = 1;
	/// play area we create
	PlayArea mPlayArea;
	/// Main Window Frame
	wxWindow* mMainFrame = nullptr;

public:

	Game();

	void OnDraw(std::shared_ptr<wxGraphicsContext> graphics, int width, int height);

	int BugCount();

	/// Set the Shrinked when click on view
	void SetShrinked();

	/// Return is Shrinked or not
	/// @return bool
	bool GetShrinked(){return mShrinked;}

	void CreateRedundancyFly(std::shared_ptr<Program> program, double locX, double locY, double speed);
	void CreateFatBug(std::shared_ptr<Program> program, double locX, double locY, double speed);
	void CreateNullBug(std::shared_ptr<Program> program, double locX, double locY, double speed);


	void Load(const wxString &filename);
	void XmlItem(wxXmlNode *node,  std::shared_ptr<Program> program);

	///Getter for the playArea
	///@return PlayArea
	PlayArea* GetPlayArea(){return &mPlayArea;}
	void Update(double elapsed);
	///Getter for X offset @return mXOffset
	double GetXOffset(){return mXOffset;}
	///Getter for Y offset @return mYOffset
	double GetYOffset(){return mYOffset;}
	///Getter for scale @return scale
	double GetScale(){return mScale;}
	///Setter for mainframe of the game
	void SetMainFrame(wxWindow* window){mMainFrame = window;}
	///Setter for game Paused state
	void SetPaused(bool state){mPaused = state;}
	///Getter for game Paused state
	bool GetPaused(){return mPaused;}
	///Setter for game Resumed state
	void SetResumed(bool state){mResumed = state;}
	///Getter for game Resumed state
	bool GetResumed(){return mResumed;}
	///Setter for current level
	void SetLevel(int level){mLevel = level;}

	void Accept(ObjectVisitor * visitor);

};

#endif //PROJECT1BEDBUG_GAMELIB_GAME_H
