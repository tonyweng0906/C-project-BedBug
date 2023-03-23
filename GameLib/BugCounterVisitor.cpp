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

/**
* visit a BugGarbage object
* @param BugGarbage object we are visiting
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
* @param BugNull object we are visiting
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
* @param BugRedundancy object we are visiting
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
* @param FatGarbage object we are visiting
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
* @param FatNull object we are visiting
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
* @param Feature object we are visiting
*/
void BugCounterVisitor::VisitFeature(Feature *bug)
{
	if(!bug->GetSplat())
	{
		mNumBugs++;
	}
}



