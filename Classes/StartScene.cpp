//
// StartScene.cpp
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 18 Nov 2020
// Date last modified: 18 Nov 2020
//

#include "StartScene.h"

USING_NS_CC;

Scene* Start::createScene() {
    return Start::create();
}

static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

bool Start::init() {

    // 1. initialize Scene supercslass
    if(!Scene::init()) {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    // 2. add a menu button, which is clicked to go to end scene and application
    auto playButtonMenuItem = MenuItemImage::create("spin_button.png",
                                                 "spin_button.png",
                                                 CC_CALLBACK_1(Start::menuCloseCallback,this)
                                                );
    playButtonMenuItem->setScale(playButtonMenuItem->getContentSize().width / visibleSize.width,
                                 playButtonMenuItem->getContentSize().height / visibleSize.height);

    // check to see if play button does not load correctly
    if (playButtonMenuItem == nullptr ||
        playButtonMenuItem->getContentSize().width <= 0 ||
        playButtonMenuItem->getContentSize().height <= 0) {
        problemLoading("'spin_button'");
    } else {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5;
        playButtonMenuItem->setPosition(Vec2(x,y));
    }

    // adding all the menu items to menu
    auto menu = Menu::create(playButtonMenuItem, NULL);
    menu->setPosition(Vec2::ZERO);

    // adding all the objects into the scene
    this->addChild(menu);

    return true;
}

void Start::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    //EventCustom customEndEvent("game_scene_close_event");
    //_eventDispatcher->dispatchEvent(&customEndEvent);

}