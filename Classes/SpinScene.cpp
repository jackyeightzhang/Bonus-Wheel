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
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
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

    // 4. add wheel border sprite
    auto wheelBorder = Sprite::create("wheel_border.png");

    wheelBorder->setScale(wheelScale);

    // check to see if play button does not load correctly
    if (wheelBorder == nullptr ||
        wheelBorder->getContentSize().width <= 0 ||
        wheelBorder->getContentSize().height <= 0) {
        problemLoading("'wheel border'");
    } else {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 3;
        wheelBorder->setPosition(Vec2(x,y));
    }

    // 5. add wheel arrow, last because it is infront of the wheel border and
    auto wheelArrow = Sprite::create("wheel_arrow.png");

    wheelArrow->setScale(wheelScale);

    // check to see if play button does not load correctly
    if (wheelArrow == nullptr ||
        wheelArrow->getContentSize().width <= 0 ||
        wheelArrow->getContentSize().height <= 0) {
        problemLoading("'wheel arrow'");
    } else {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 4;
        wheelArrow->setPosition(Vec2(x,y));
    }

    // 6. add prizes sprites
    Vector<Sprite*> prizes = Game::initPrizes(this, origin, visibleSize,wheelScale);

    // 7. add prize labels
    Vector<Label*> amounts = Game::initAmounts(this, origin, visibleSize,wheelScale * prizes.at(0)->getContentSize().height );

    // adding all the objects into the scene
    this->addChild(wheelPanelSprite,1);
    this->addChild(wheelBorder,3);
    this->addChild(wheelArrow,4);

    // 8. spin wheel
    auto delay = DelayTime::create(1);

    return true;

}