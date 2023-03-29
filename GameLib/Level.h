/**
 * @file Level.h
 * @author saipr
 *
 *
 */

#ifndef PROJECT1BEDBUG_LEVEL_H
#define PROJECT1BEDBUG_LEVEL_H

#include "Bug.h"
#include "Feature.h"

class Game;

/**
 * Base class for level
 */
class Level {
private:
	/// the game
    Game *mGame;
	/// The width of the image
    double mWidth;
	/// the height of the image
    double mHeight;
	/// the Bug
    Bug *mBug;

    ///Level xml document
    wxXmlDocument mXmlDoc;

    /// items in level
    std::vector<std::shared_ptr<Bug>> mBugs;



public:
    /// Default constructor (disabled)
    Level() = delete;

    /// Copy constructor (disabled)
    Level(const Level &) = delete;

    /// Assignment operator
    void operator=(const Level &) = delete;

    /// Destructor
    ~Level(){}

    Level(Game* game);

    void Load(wxXmlDocument xmlDoc);

    void XmlItem(wxXmlNode *node);

};

#endif //PROJECT1BEDBUG_LEVEL_H
