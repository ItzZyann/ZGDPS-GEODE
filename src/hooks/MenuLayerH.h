#pragma once
#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MenuLayerH, MenuLayer) {
public:
    $override bool init();
    
    void onCredits(CCObject*);
    void onSupport(CCObject*);
};