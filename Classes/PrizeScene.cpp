//
// PrizeScene.cpp
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 19 Nov 2020
// Date last modified: 19 Nov 2020
//
#include "PrizeScene.h"

USING_NS_CC;

Scene* Prize::createScene(int pr, float ps) {
    auto prizeScene = Prize::create();
    return prizeScene;
}

bool Prize::init() {
    // initialize Scene supercslass
    if(!Scene::init()) {
        return false;
    }

    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();


    Sprite* prizeSprite;
    Label* prizeAmount;

    prizeNumber = 2;
    prizeSize = 120;
    switch(prizeNumber) {
        case 0 :
            prizeSprite = Sprite::create("heart.png");
            prizeAmount = Label::createWithSystemFont("30x\nmins","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
        case 1:
            prizeSprite = Sprite::create("brush.png");
            prizeAmount = Label::createWithSystemFont("3x","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
        case 2:
            prizeSprite = Sprite::create("gem.png");
            prizeAmount = Label::createWithSystemFont("35x","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
        case 3:
            prizeSprite = Sprite::create("hammer.png");
            prizeAmount = Label::createWithSystemFont("3x","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
        case 4:
            prizeSprite = Sprite::create("coin.png");
            prizeAmount = Label::createWithSystemFont("750x","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
        case 5:
            prizeSprite = Sprite::create("brush.png");
            prizeAmount = Label::createWithSystemFont("1x","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
        case 6:
            prizeSprite = Sprite::create("gem.png");
            prizeAmount = Label::createWithSystemFont("75x","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
        case 7:
            prizeSprite = Sprite::create("hammer.png");
            prizeAmount = Label::createWithSystemFont("1x","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
        default:
            prizeSprite = Sprite::create("heart.png");
            prizeAmount = Label::createWithSystemFont("30x\nmins","Arial", 9,
                                                      Size(prizeSize,prizeSize),
                                                      TextHAlignment::RIGHT,
                                                      TextVAlignment::BOTTOM);
            break;
    }

    CCLOG("this is the prize passed to prize scene: %i", prizeNumber+1);

    //    auto prizeScene = Prize::create();
//    Director::getInstance()->pushScene(prizeScene);
    //
//    auto shiftDown = MoveBy::create(2, Vec2(0, visibleSize.height / 2));
//    auto scaleUp = ScaleBy::create(2,2);
//    auto spawnDisplay = Spawn::create(shiftDown, scaleUp, nullptr);
//    this->removeAllChildren();
//    this->addChild(prizes.at(prize));
//    this->addChild(amounts.at(prize));
//
//    prizes.at(prize)->runAction(spawnDisplay);
//    amounts.at(prize)->runAction(shiftDown);
//
//    auto emitter = ParticleSun::create();
//    emitter->setDuration(ParticleSystem::DURATION_INFINITY);
//    emitter->setEnd

    return true;
}