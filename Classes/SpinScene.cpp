//
// SpinScene.cpp
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 19 Nov 2020
// Date last modified: 19 Nov 2020
//

#include "SpinScene.h"
#include "GameScene.h"

USING_NS_CC;

Scene* Spin::createScene() {
    return Spin::create();
}

static void problemLoading(const char* filename)
{
    CCLOGERROR("Error while loading: %s\n", filename);
}

bool Spin::init() {

    // 1. initialize Scene supercslass
    if(!Scene::init()) {
        return false;
    }

    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();

    auto wheelPanelSprite = Sprite::create("wheel_sections_8.png");

    float wheelScale = MAX(wheelPanelSprite->getContentSize().width / visibleSize.width,
                           wheelPanelSprite->getContentSize().height / visibleSize.height);

    wheelPanelSprite->setScale(wheelScale);

    // check to see if play button does not load correctly
    if (wheelPanelSprite == nullptr ||
        wheelPanelSprite->getContentSize().width <= 0 ||
        wheelPanelSprite->getContentSize().height <= 0) {
        problemLoading("'wheel panel'");
    } else {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 3;
        wheelPanelSprite->setPosition(Vec2(x,y));
    }

    this->addChild(wheelPanelSprite,1);

    // add misc wheel nodes
    Game::initWheelMisc(this, origin, visibleSize, wheelScale);
    // add prizes sprites
    Vector<Sprite*> prizes = Game::initPrizes(this, origin, visibleSize, wheelScale);

    // add prize labels
    float prize_size = wheelScale * prizes.at(0)->getContentSize().height;
    Vector<Label*> amounts = Game::initAmounts(this, origin, visibleSize, prize_size);



    // spin wheel
    auto delay = DelayTime::create(1);

    CCLOG("SPINNING");
    return true;

}