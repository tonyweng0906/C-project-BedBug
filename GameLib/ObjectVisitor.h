/**
 * @file ObjectVisitor.h
 * @author Xin Weng
 *
 *
 */

#ifndef PROJECT1BEDBUG_GAMELIB_OBJECTVISITOR_H
#define PROJECT1BEDBUG_GAMELIB_OBJECTVISITOR_H

class Bug;
class FatGarbage;
class FatNull;
class GameObject;
class BugGarbage;
class BugNull;
class BugRedundancy;
class Feature;
class Program;

/// class for the Visitor
class ObjectVisitor
{
protected:
	/**
	 * Constructor
	 * Ensures this is an abstract class
	 */
	ObjectVisitor() {};

public:
	virtual ~ObjectVisitor() {}

	/**
	 * Visit a Bug object
	 * @param bug Bug we are visiting
	 */
	virtual void VisitBug(Bug * bug) {}

	/**
	* Visit a FatGarbage object
	* @param fatGarbage FatGarbage we are visiting
	*/
	virtual void VisitFatGarbage(FatGarbage * fatBug) {}

	/**
	* Visit a FatNull object
	* @param fatNull FatNull we are visiting
	*/
	virtual void VisitFatNull(FatNull * fatBug) {}

	/**
	* Visit a BugGarbage object
	* @param bugGarbage BugGarbage we are visiting
	*/
	virtual void VisitBugGarbage(BugGarbage * bugGarbage) {}

	/**
	* Visit a BugNull object
	* @param bugNull BugNull we are visiting
	*/
	virtual void VisitBugNull(BugNull * bugNull) {}

	/**
	* Visit a BugRedundancy object
	* @param bugRedundancy BugRedundancy we are visiting
	*/
	virtual void VisitBugRedundancy(BugRedundancy * bugRedundancy) {}

	/**
	* Visit a Feature object
	* @param feature Feature we are visiting
	*/
	virtual void VisitFeature(Feature * feature) {}

	/**
	* Visit a project object
	* @param program Program we are visiting
	*/
	virtual void VisitProgram(Program * program) {}

	/**
	* Visit a  object
	* @param program Program we are visiting
	*/
	virtual void VisitObject(GameObject * gameObject) {}
};

#endif //PROJECT1BEDBUG_GAMELIB_OBJECTVISITOR_H
