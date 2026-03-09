#include "MenuLayerH.h"

bool MenuLayerH::init() {
    if(!MenuLayer::init())
    return false;

    // for debug purposes only
    // m_showingTOS = true;

    auto dir = CCDirector::sharedDirector();
    auto winSize = dir->getWinSize();

    auto rightMenu = this->getChildByID("right-side-menu");

    // credits button
    // bcuz yes
    auto creditsSpr = CCSprite::createWithSpriteFrameName("communityCreditsBtn_001.png");
    auto creditsBtn = CCMenuItemSpriteExtra::create(creditsSpr, this, menu_selector(MenuLayerH::onCredits));
    creditsBtn->setPosition(rightMenu->convertToNodeSpace({
        dir->getScreenRight() - 30,
        winSize.height - 30
    }));

    rightMenu->addChild(creditsBtn);

    return true;
}

void MenuLayerH::onCredits(CCObject* pSender) {
    FLAlertLayer::create(nullptr, "Credits",
        "<cy>RobTop</c> - Game Owner.\n"
        "<cg>ItzZyann</c> - GDPS Owner & Mod Developer.\n"
        "<cl>Part</c> - GDPS Manager & Main Level.\n"
        "<cl>Gabriel</c> - GDPS Manager & Main Level.\n"
        "<cl>AzanixK</c> - GDPS Discord Admin.\n"
        "<co>Toxxix</c> - Additional Help.\n"
        "<co>MattChelly</c> - Additional Help.\n",
        "OK", nullptr, 350)->show();
}