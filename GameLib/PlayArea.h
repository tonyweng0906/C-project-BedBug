/**
 * @file PlayArea.h
 * @author Aron DuBois
 *
 * Class to hold game objects
 */

#ifndef PROJECT1BEDBUG_GAMELIB_PLAYAREA_H
#define PROJECT1BEDBUG_GAMELIB_PLAYAREA_H

#include <memory>
#include <vector>
#include <map>
#include "GameObject.h"
#include <wx/graphics.h>


// forward reference for object visitor
class ObjectVisitor;

/**
 * Class to hold game objects
 */
class PlayArea
{
private:

	/// All of the game objects that make up the game
	std::vector<std::shared_ptr<GameObject>> mObjects;

	/// List of all the images
	std::map<std::string,  wxGraphicsBitmap> mImages;
public:
	PlayArea();

	/**
	 * Destructor
	 */
	 virtual ~PlayArea() = default;

	 void Add(std::shared_ptr<GameObject> object);

	 std::shared_ptr<GameObject> HitTest(int x, int y);

	 void DeleteObject(std::shared_ptr<GameObject> object);

	 void Update(double elapsed);

	 void Accept(ObjectVisitor * visitor);

	 void OnDraw(wxDC* graphics);

	// Loading and saving functions go here?
	void ClearObject();

	wxGraphicsBitmap GetBitmap(std::string name);

	///Getter for the objects
	///@return vector of the object
	std::vector<std::shared_ptr<GameObject>> GetObject() {return mObjects;}

	/**
	 * reverse the order of the game objects in the play area
	 */
	 void ReverseOrder(){ std::reverse(mObjects.begin(), mObjects.end());}

};

#endif //PROJECT1BEDBUG_GAMELIB_PLAYAREA_H
