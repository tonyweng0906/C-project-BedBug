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
	/// scale of X
	double mXOffset = 0;
	/// scale of Y
	double mYOffset = 0;
	/// scale number
	double mScale = 0;
	/// if scale or not
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
    /// ScoreBoard we create
    ScoreBoard mScoreBoard;

	///level complete time
	double mCompleteTime = 2;

	///if we need to draw level complete title
	bool mComplete = false;

	///name of the level
	std::wstring mLevelName;

    bool mStart = false;

    double mStartTime = 0;
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
	///@param window The parent window
	void SetMainFrame(wxWindow* window){mMainFrame = window;}

	/**
     * Setter for game Paused state
     * @param state The paused or not
     */
	void SetPaused(bool state){mPaused = state;}

	///Getter for game Paused state
	/// @return Pause or not
	bool GetPaused(){return mPaused;}

	/**
     * Setter for game Resumed state
     * @param state The resume or not
     */
	void SetResumed(bool state){mResumed = state;}

	/**
     * Getter for game Resumed state
     * @return if Resumed or not
     */
	bool GetResumed(){return mResumed;}
	/**
     * Setter for current level
     * @param level The level
     */
	void SetLevel(int level){mLevel = level;}
	/**
	 * Setter for ScoreBoard
	 * @param scoreBoard Set the scoreboard
	 */
    void SetBoard(ScoreBoard scoreBoard){mScoreBoard = scoreBoard;}

	/**
	 * Getter for ScoreBoard
	 * @return Scoreboard
	 */
    ScoreBoard* GetBoard(){return &mScoreBoard;}

	void Accept(ObjectVisitor * visitor);

};

#endif //PROJECT1BEDBUG_GAMELIB_GAME_H
