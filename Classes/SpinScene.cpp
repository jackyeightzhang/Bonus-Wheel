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

int Spin::prizeOutput() {
    // generate a random number between 1-100
    int randomNumber = random(1,100);

    // prize 1
    if(randomNumber <= 20) {
        return 0;
    // prize 2
    } else if(randomNumber <= 30) {
        return 1;
    // prize 3
    } else if(randomNumber <= 40) {
        return 2;
    // prize 4
    } else if(randomNumber <= 50) {
        return 3;
    // prize 5
    } else if(randomNumber <= 55) {
        return 4;
    // prize 6
    } else if(randomNumber <= 75) {
        return 5;
    // prize 7
    } else if(randomNumber <= 80) {
        return 6;
    //prize 8
    } else {
        return 7;
    }
}

float Spin::prizeRotation(int prize) {
    // spin 5 times for the fancy effect, then add an extra spin
    float ROT_DEGREE = 360/16;
    CCLOGINFO("I should get prize %i", prize+1);
    return (5 * 360) + (360 - (ROT_DEGREE * (1 + (prize * 2) ) ) );
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
    int prize = prizeOutput();
    auto spinAction = RotateBy::create(5,prizeRotation(prize));
    // auto easedSpin = EaseOutElastic::create();
    auto delay1Sec = DelayTime::create(1);

    wheelPanelSprite->runAction(spinAction);
    for(int i = 0; i < prizes.size(); i++) {
        prizes.at(i)->runAction(spinAction->clone());
    }
    for(int j = 0; j < amounts.size(); j++) {
        amounts.at(j)->runAction(spinAction->clone());
    }
    return true;

}