#include <Geode/Geode.hpp>

#include <Geode/modify/LoadingLayer.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include <Geode/modify/GameManager.hpp>
#include <Geode/modify/GameStatsManager.hpp>

using namespace geode::prelude;

// LOADING LAYER
class $modify(LoadingLayerH, LoadingLayer) {
public:
    $override const char* getLoadingString() {
        const char* ret =
            "Mod developed by ItzZyann\n"
            "All rights reserved :D";

        return ret; 
    }

    $override bool init(bool pLoadDef) {
        if(!LoadingLayer::init(pLoadDef))
        return false;

        auto logo = (CCSprite*)(this->getChildren()->objectAtIndex(1));
        logo->setPositionY( logo->getPositionY() + 10);

        auto zyann = CCLabelBMFont::create(
            "ItzZyann Server",
            "goldFont.fnt"
        );

        zyann->setScale(.9);
        zyann->setPosition(
            logo->getPositionX() + 120,
            logo->getPositionY() - 40
        );

        addChild(zyann, 100);

        return true;
    }
};