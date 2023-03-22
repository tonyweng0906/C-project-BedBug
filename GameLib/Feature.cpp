/**
 * @file Feature.cpp
 * @author Xin Weng
 */

#include "pch.h"
#include "Feature.h"
#include "Program.h"
#include "Game.h"

/// The feature sprite image
const std::wstring FeatureImageName = L"images/feature.png";

/// The splat image
const std::wstring FeatureSplatImageName = L"images/feature-splat.png";

/// Number of sprite images
const int FeatureNumSpriteImages = 7;

/**
 * Constructor
 * @param game The game we are in
 */
Feature::Feature(Game *game) : Bug(game, FeatureImageName)
{

}
