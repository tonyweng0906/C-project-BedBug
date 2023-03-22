/**
 * @file Level.cpp
 * @author saipr
 */

#include "pch.h"
#include "Level.h"
#include "Bug.h"
#include "Feature.h"

using namespace std;


Level::Level(Game* game) : mGame(game)
{
}

/**
 * loads level via xml
 * @param xmlDoc the xml file for the level to be loaded
 */
void Level::Load(wxXmlDocument xmlDoc)
{
//    auto root = xmlDoc.GetRoot();
//    root->GetAttribute(L"width", "0").ToDouble(&mWidth);
//    root->GetAttribute(L"height", "0").ToDouble(&mHeight);
//    auto child = root->GetChildren();
//    for (; child; child = child->GetNext())
//    {
//        auto name = child->GetName();
//        if (name==L"bug")
//        {
//            double bugX, bugY, bugSpeed, bugStart;
//            child->GetAttribute(L"x").ToDouble(&bugX);
//            child->GetAttribute(L"y").ToDouble(&bugY);
//            child->GetAttribute(L"speed").ToDouble(&bugSpeed);
//            child->GetAttribute(L"start").ToDouble(&bugStart);
////            shared_ptr<Bug> bug = make_shared<Bug>(mBug);
////            bug->XmlLoad(bugX, bugY, bugSpeed, bugStart);
////            mBugs.push_back(bug);
//        }
//        if (name==L"feature")
//        {
//            double featureX, featureY, featureSpeed, featureStart;
//            child->GetAttribute(L"x").ToDouble(&featureX);
//            child->GetAttribute(L"y").ToDouble(&featureY);
//            child->GetAttribute(L"speed").ToDouble(&featureSpeed);
//            child->GetAttribute(L"start").ToDouble(&featureStart);
//        }
//    }

    auto root = xmlDoc.GetRoot();
    root->GetAttribute(L"width", "0").ToDouble(&mWidth);
    root->GetAttribute(L"height", "0").ToDouble(&mHeight);
    auto child = root->GetChildren();
    for (; child; child = child->GetNext())
    {
        auto name = child->GetName();
        if (name==L"program")
        {
            auto item_child = child->GetChildren();
            for (; item_child; item_child = item_child->GetNext())
            {
                auto item_name = item_child->GetName();
                XmlItem(item_child);
            }
        }
    }
}

/**
 * XML item loader
 * @param node node being loaded
 */
void Level::XmlItem(wxXmlNode *node)
{

}