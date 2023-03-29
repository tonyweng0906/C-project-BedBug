/**
 * @file BugCounterVisitor.h
 * @author Aron DuBois
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_BUGCOUNTERVISITOR_H
#define PROJECT1BEDBUG_GAMELIB_BUGCOUNTERVISITOR_H

#include "ObjectVisitor.h"
/**
 * Visitor class for bug counting
 */
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


	void VisitBugGarbage(BugGarbage* bug) override;


	void VisitBugNull(BugNull* bug) override;


	void VisitBugRedundancy(BugRedundancy* bug) override;


	void VisitFatGarbage(FatGarbage* bug) override;


	void VisitFatNull(FatNull* bug) override;


	void VisitFeature(Feature* bug) override;

	void VisitBugMulti(BugMulti* bug) override;

};

#endif //PROJECT1BEDBUG_GAMELIB_BUGCOUNTERVISITOR_H
