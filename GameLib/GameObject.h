/**
 * @file GameObject.h
 * @author Team BedBug
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_GAMEOBJECT_H
#define PROJECT1BEDBUG_GAMELIB_GAMEOBJECT_H

#include <wx/graphics.h>
#include "ObjectVisitor.h"

class Game;
class ScoreBoard;

/**
 * Base class for any Object in our game.
 */
class GameObject
{
private:
	/// The game this object is contained in
	Game  *mGame;

protected:
	GameObject(Game *game, const std::string & name );

	// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	/// The item image
	std::shared_ptr<wxImage> mObjectImage;

	/// The item bitmap
	wxGraphicsBitmap mObjectBitmap;

	double mObjectWidth;

	double mObjectHeight;

	int mNumOfSheets = 0;

	double mSheetHeight = 0.0;

public:
	virtual ~GameObject();
	/**
	* Determine if we should remove the bug
	* @return bool true if we should remove false otherwise
	*/
	virtual bool MoveFinish() {return false;}
	/**
	* Determine if the bug is splatted
	* @return bool true if the bug is splatted
	*/
	virtual bool GetSplat() {return false;}
	/**
     * The X location of the item
     * @return X location in pixels
     */
	double GetX() const { return mX; }

	/**
	 * The Y location of the item
	 * @return Y location in pixels
	 */
	double GetY() const { return mY; }

	/**
	 * Set the item location
	 * @param x X location in pixels
	 * @param y Y location in pixels
	 */
	void SetLocation(double x, double y) { mX = x; mY = y; }

	/// Default constructor (disabled)
	GameObject() = delete;

	/// Copy constructor (disabled)
	GameObject(const GameObject &) = delete;

	/// Assignment operator
	void operator=(const GameObject &) = delete;

	/**
	* Draw this GameObject
	* @param dc Device context to draw on
	*/
	virtual void Draw(std::shared_ptr<wxGraphicsContext> dc);

	/**
	 * stub function for creating an IDE for Fatbugs
	 * @param window a wxwindow pointer
	 */
	virtual void makeIDE(wxWindow* window){};

	virtual bool HitTest(int x, int y);

	double DistanceTo(std::shared_ptr<GameObject> gameObject);

	/**
	 * Double Click executes actions for being double clicked
	 */
	virtual void DoubleClick(){};

	/**
	 * single Click executes actions for being double clicked
	 */
	virtual void SingleClick(){};
    /**
     * Score functions that add scores
     */
    virtual void AddScore(){};
    virtual void AddFatScore(){};
	/**
	 * Set the target program
	  * @param program the target
	  */
	virtual void SetProgram(std::shared_ptr<Program> program) {};

	virtual void XmlLoad(wxXmlNode *node);


	/**
 	* Handle updates for animation
 	* @param elapsed The time since the last update
 	*/
	virtual void Update(double elapsed) {}

	/**
 	* Get the pointer to the game object
	 * @return Pointer to game object
 	*/
	Game *GetGame() { return mGame;  }


	virtual int GetWidth() const;

	virtual int GetHeight() const;

	/**
 	* Accept a visitor
 	 * @param visitor The visitor we accept
 	 */
	virtual void Accept(ObjectVisitor* visitor) {};

	void UpdateSpriteSheet();

    ScoreBoard *GetBoard();
};

#endif //PROJECT1BEDBUG_GAMELIB_GAMEOBJECT_H
