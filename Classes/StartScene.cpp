//
// StartScene.cpp
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 18 Nov 2020
// Date last modified: 18 Nov 2020
//

#include "StartScene.h"
#include "ui/CocosGUI.h"

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
    // auto playButtonMenuItem = MenuItemImage::create("spin_button.png", "spin_button.png", CC_CALLBACK_1());
    auto playButtonMenuItem = ui::Button::create("spin_button.png",
                                                          "spin_button.png",
                                                          "spin_button.png");
    playButtonMenuItem->setTitleAlignment(TextHAlignment::CENTER);
    playButtonMenuItem->setTitleText("Play On");
//    playButtonMenuItem->setPressedActionEnabled(true);
//    playButtonMenuItem->setZoomScale(-0.5);
    playButtonMenuItem->addTouchEventListener(CC_CALLBACK_1(Start::menuCloseCallback,this));
    playButtonMenuItem->setScale(MAX(playButtonMenuItem->getContentSize().width / visibleSize.width,
                                     playButtonMenuItem->getContentSize().height / visibleSize.height));


    // check to see if play button does not load correctly
    if (playButtonMenuItem == nullptr ||
        playButtonMenuItem->getContentSize().width <= 0 ||
        playButtonMenuItem->getContentSize().height <= 0) {
        problemLoading("'Spin Button'");
    } else {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 1;
        playButtonMenuItem->setPosition(Vec2(x,y));
    }

    // adding all the menu items to menu
//    auto menu = Menu::create(playButtonMenuItem, NULL);
//    menu->setPosition(Vec2::ZERO);

    // 3. add wheel panel sprite
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

    // 6. adding all the prize sprites
    auto life30Sprite_1 = Sprite::create("heart.png");
    auto brush3Sprite_2 = Sprite::create("brush.png");
    auto gems35Sprite_3 = Sprite::create("gem.png");
    auto hammer3Sprite_4 = Sprite::create("hammer.png");
    auto coins750Sprite_5 = Sprite::create("coin.png");
    auto brush1Sprite_6 = Sprite::create("brush.png");
    auto gems75Sprite_7 = Sprite::create("gem.png");
    auto hammer1Sprite_8 = Sprite::create("hammer.png");

    Vector<Sprite*> prizes = {
                              life30Sprite_1,
                              brush3Sprite_2,
                              gems35Sprite_3,
                              hammer3Sprite_4,
                              coins750Sprite_5,
                              brush1Sprite_6,
                              gems75Sprite_7,
                              hammer1Sprite_8
                              };

    float ROT_DEGREE = 360/16;
    float PRIZE_SIZE = wheelScale * life30Sprite_1->getContentSize().height;
    for(int i = 0; i < prizes.size(); i++) {
        auto sprite = prizes.at(i);
        sprite->setContentSize(Size(PRIZE_SIZE,PRIZE_SIZE));

        if (sprite == nullptr ||
            sprite->getContentSize().width <= 0 ||
            sprite->getContentSize().height <= 0) {
            problemLoading("'prize'");
        } else {
            float x = origin.x + visibleSize.width / 2;
            float y = origin.y + visibleSize.height / 5 * 3;
            sprite->setPosition(Vec2(x,y));
            sprite->setAnchorPoint(Vec2(0.5,-2.5));
            sprite->setRotation(ROT_DEGREE * ( 1 + ( i * 2 ) ) );
            this->addChild(sprite,2);
        }
    }

    // adding all the objects into the scene
    this->addChild(playButtonMenuItem,0);
    this->addChild(wheelPanelSprite,1);
    this->addChild(wheelBorder,3);
    this->addChild(wheelArrow,4);
    return true;
}

void Start::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    EventCustom customEndEvent("game_scene_close_event");
    _eventDispatcher->dispatchEvent(&customEndEvent);

}