/**
 * @file LevelLoader.h
 * @author saipr
 *
 *
 */

#ifndef PROJECT1BEDBUG_LEVELLOADER_H
#define PROJECT1BEDBUG_LEVELLOADER_H

#include "Level.h"

/**
 * Base class for level loader
 */
class LevelLoader {
private:
    /// order list
    std::vector<std::shared_ptr<Level>> mOrder;

public:

};

#endif //PROJECT1BEDBUG_LEVELLOADER_H
