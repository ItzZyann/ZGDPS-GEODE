#include "LoadingLayerH.h"
#include <km7dev.server_api/include/ServerAPIEvents.hpp>

bool LoadingLayerH::init(bool pLoadDefault) {
    if(!LoadingLayer::init(pLoadDefault))
    return false;

    auto logo = (CCSprite*)(this->getChildren()->objectAtIndex(1));
    logo->setPositionY( logo->getPositionY() + 10);

    // gdps logo
    // or label rather
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
    
    // initialize the
    // gdps
    initializeGDPS();
    
    return true;
}

const char* LoadingLayerH::getLoadingString() {
    const char* ret =
        "Mod developed by ItzZyann\n"
        "All rights reserved :D";

    return ret; 
}

void LoadingLayerH::initializeGDPS() {
    ServerAPIEvents::registerServer("https://zyanngd.ps.fhgdps.com/", 10);
}