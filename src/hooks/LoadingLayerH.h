#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/LoadingLayer.hpp>

using namespace geode::prelude;

class $modify(LoadingLayerH, LoadingLayer) {
public:
    $override bool init(bool pLoadDefault);
    $override const char* getLoadingString();

    void initializeGDPS();
};