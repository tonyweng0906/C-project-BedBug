/**
 * @file BugCounterVisitor.h
 * @author Aron DuBois
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGCOUNTERVISITOR_H
#define PROJECT1BEDBUG_GAMELIB_BUGCOUNTERVISITOR_H

#include "ObjectVisitor.h"

class BugCounterVisitor : public ObjectVisitor
{
private:
	/// Bug Counter
	int mNumBugs = 0;

public:

	/**
	* Get the number of bugs
	* @return number of bugs
	*/
	int GetNumBugs() {return mNumBugs;}

	/**
	* visit a BugGarbage object
	* @param BugGarbage object we are visiting
	*/
	void VisitBugGarbage(BugGarbage* bug) override{ mNumBugs++;}

	/**
	* visit a BugNull object
	* @param BugNull object we are visiting
	*/
	void VisitBugNull(BugNull* bug) override{ mNumBugs++;}

	/**
	* visit a BugRedundancy object
	* @param BugRedundancy object we are visiting
	*/
	void VisitBugRedundancy(BugRedundancy* bug) override{ mNumBugs++;}

	/**
	* visit a FatGarbage object
	* @param FatGarbage object we are visiting
	*/
	void VisitFatGarbage(FatGarbage* bug) override{ mNumBugs++;}

	/**
	* visit a FatNull object
	* @param FatNull object we are visiting
	*/
	void VisitFatNull(FatNull* bug) override{ mNumBugs++;}

	/**
	* visit a Feature object
	* @param Feature object we are visiting
	*/
	void VisitFeature(Feature* bug) override{ mNumBugs++;}

};

#endif //PROJECT1BEDBUG_GAMELIB_BUGCOUNTERVISITOR_H
