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

/**
 * Base class for any Object in our game.
 */
class GameObject
{
private:

	// Item location in the game
	double  mX = 0;     ///< X location for the center of the item
	double  mY = 0;     ///< Y location for the center of the item

	/// The game this object is contained in
	Game  *mGame;

	/// The item image
	std::shared_ptr<wxImage> mObjectImage;

	/// The item bitmap
	wxGraphicsBitmap mObjectBitmap;

public:
	virtual ~GameObject();

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

	bool HitTest(int x, int y);

	double DistanceTo(std::shared_ptr<GameObject> gameObject);

	/**
	 * Double Click checks if image is double clicked
	 */
	virtual void DoubleClick(){};


	virtual wxXmlNode *XmlSave(wxXmlNode *node);

	virtual void XmlLoad(wxXmlNode *node);


	/**
 	* Handle updates for animation
 	* @param elapsed The time since the last update
 	*/
	virtual void Update(double elapsed) {}

	/**
 	* Get the pointer to the Aquarium object
	 * @return Pointer to Aquarium object
 	*/
	Game *GetGame() { return mGame;  }


	virtual int GetWidth() const;

	virtual int GetHeight() const;

	/**
 	* Accept a visitor
 	 * @param visitor The visitor we accept
 	 */
	virtual void Accept(ObjectVisitor* visitor) = 0;

protected:
	GameObject(Game *game, const std::wstring & name );

	void SetMirror(bool m);

//	/// The underlying GameObject image
//	std::unique_ptr<wxImage> mGameImage;
//
//	/// The bitmap we can display for this GameObject
//	//std::unique_ptr<wxBitmap> mGameBitmap;
//	std::shared_ptr<wxBitmap> mGameBitmap;
};

#endif //PROJECT1BEDBUG_GAMELIB_GAMEOBJECT_H
