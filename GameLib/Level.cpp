/**
 * @file Level.cpp
 * @author saipr
 */

#include "Level.h"
#include "pch.h"
#include "Bug.h"
#include "Feature.h"

using namespace std;


/**
 * loads level via xml
 * @param xmlDoc the xml file for the level to be loaded
 */
void Level::Load(wxXmlDocument xmlDoc)
{
    auto root = xmlDoc.GetRoot();
    root->GetAttribute(L"width", "0").ToDouble(&mWidth);
    root->GetAttribute(L"height", "0").ToDouble(&mHeight);
    auto child = root->GetChildren();
    for (; child; child = child->GetNext())
    {
        auto name = child->GetName();
        if (name==L"bug")
        {
            double bugX, bugY, bugSpeed, bugStart;
            child->GetAttribute(L"x").ToDouble(&bugX);
            child->GetAttribute(L"y").ToDouble(&bugY);
            child->GetAttribute(L"speed").ToDouble(&bugSpeed);
            child->GetAttribute(L"start").ToDouble(&bugStart);
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