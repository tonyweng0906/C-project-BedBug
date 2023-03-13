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
#include "GameObject.h"


// forward reference for object visitor
class ObjectVisitor;

/**
 * Class to hold game objects
 */
class PlayArea
{
private:

	/// All of the game objects that make up the game
	std::vector<std::shared_ptr<GameObject> > mObjects;

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

};

#endif //PROJECT1BEDBUG_GAMELIB_PLAYAREA_H
