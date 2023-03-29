/**
 * @file BugCounterVisitor.cpp
 * @author Aron DuBois
 */

#include "pch.h"
#include "BugCounterVisitor.h"
#include "BugGarbage.h"
#include "BugNull.h"
#include "BugRedundancy.h"
#include "Feature.h"
#include "FatGarbage.h"
#include "FatNull.h"
#include "BugMulti.h"

/**
* visit a BugGarbage object
* @param bug object we are visiting
*/
void BugCounterVisitor::VisitBugGarbage(BugGarbage *bug)
{
	if(!bug->GetSplat())
	{
		mNumBugs++;
	}
}

/**
* visit a BugNull object
* @param bug object we are visiting
*/
void BugCounterVisitor::VisitBugNull(BugNull *bug)
{
	if(!bug->GetSplat())
	{
		mNumBugs++;
	}
}

/**
* visit a BugRedundancy object
* @param bug object we are visiting
*/
void BugCounterVisitor::VisitBugRedundancy(BugRedundancy *bug)
{
	if(!bug->GetSplat())
	{
		mNumBugs++;
	}
}

/**
* visit a FatGarbage object
* @param bug object we are visiting
*/
void BugCounterVisitor::VisitFatGarbage(FatGarbage *bug)
{
	if(!bug->GetSplat())
	{
		mNumBugs++;
	}
}

/**
* visit a FatNull object
* @param bug object we are visiting
*/
void BugCounterVisitor::VisitFatNull(FatNull *bug)
{
	if(!bug->GetSplat())
	{
		mNumBugs++;
	}
}

/**
* visit a Feature object
* @param bug feature object we are visiting
*/
void BugCounterVisitor::VisitFeature(Feature *bug)
{
	if(!bug->GetSplat())
	{
		mNumBugs++;
	}
}

/**
* visit a multi bug oject
* @param bug object we are visiting
*/
void BugCounterVisitor::VisitBugMulti(BugMulti *bug)
{
	if(!bug->GetSplat())
	{
		mNumBugs++;
	}
}






