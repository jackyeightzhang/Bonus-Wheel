//
// StartScene.cpp
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 18 Nov 2020
// Date last modified: 19 Nov 2020
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

bool Start::initPlayButton(const Vec2& origin, const Size& visibleSize) {
    // create button
    auto playButton = ui::Button::create("spin_button.png",
                                                 "spin_button.png",
                                                 "spin_button.png");

    // setting button size
    playButton->setScale(MAX(playButton->getContentSize().width / visibleSize.width,
                             playButton->getContentSize().height / visibleSize.height));
    // setting button text
    playButton->setTitleAlignment(TextHAlignment::CENTER);
    playButton->setTitleText("Play On");

    // setting button functionality
    playButton->addTouchEventListener(CC_CALLBACK_1(Start::spinSceneCallback,this));
//    playButton->setPressedActionEnabled(true);
//    playButton->setZoomScale(-0.5);

    // check to see if play button does not load correctly
    if (playButton == nullptr ||
        playButton->getContentSize().width <= 0 ||
        playButton->getContentSize().height <= 0) {
        problemLoading("'Spin Button'");
    } else {
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 1;
        playButton->setPosition(Vec2(x,y));
    }

    this->addChild(playButton, 0);

    return true;
}

bool Start::initWheel(const Vec2& origin, const cocos2d::Size& visibleSize){
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
            sprite->setRotation( ROT_DEGREE * ( 1 + ( i * 2 ) ) );
            this->addChild(sprite,2);
        }
    }

    // 7. adding labels to all the prize sprites
    auto life30Label_1 = Label::createWithSystemFont("30x\nmins","Arial", 9, Size(PRIZE_SIZE,PRIZE_SIZE),TextHAlignment::RIGHT,TextVAlignment::BOTTOM);
    auto brush3Label_2 = Label::createWithSystemFont("3x","Arial", 9, Size(PRIZE_SIZE,PRIZE_SIZE),TextHAlignment::RIGHT,TextVAlignment::BOTTOM);
    auto gems35Label_3 = Label::createWithSystemFont("35x","Arial", 9, Size(PRIZE_SIZE,PRIZE_SIZE),TextHAlignment::RIGHT,TextVAlignment::BOTTOM);
    auto hammer3Label_4 = Label::createWithSystemFont("3x","Arial", 9, Size(PRIZE_SIZE,PRIZE_SIZE),TextHAlignment::RIGHT,TextVAlignment::BOTTOM);
    auto coins750Label_5 = Label::createWithSystemFont("750x","Arial", 9, Size(PRIZE_SIZE,PRIZE_SIZE),TextHAlignment::RIGHT,TextVAlignment::BOTTOM);
    auto brush1Label_6 = Label::createWithSystemFont("1x","Arial", 9, Size(PRIZE_SIZE,PRIZE_SIZE),TextHAlignment::RIGHT,TextVAlignment::BOTTOM);
    auto gems75Label_7 = Label::createWithSystemFont("75x","Arial", 9, Size(PRIZE_SIZE,PRIZE_SIZE),TextHAlignment::RIGHT,TextVAlignment::BOTTOM);
    auto hammer1Label_8 = Label::createWithSystemFont("1x","Arial", 9, Size(PRIZE_SIZE,PRIZE_SIZE),TextHAlignment::RIGHT,TextVAlignment::BOTTOM);

    Vector<Label*> amounts = {
            life30Label_1,
            brush3Label_2,
            gems35Label_3,
            hammer3Label_4,
            coins750Label_5,
            brush1Label_6,
            gems75Label_7,
            hammer1Label_8
    };

    for(int i = 0; i < amounts.size(); i++) {
        auto label = amounts.at(i);
        label->setContentSize(Size(PRIZE_SIZE,PRIZE_SIZE));

        if (label == nullptr ||
            label->getContentSize().width <= 0 ||
            label->getContentSize().height <= 0) {
            problemLoading("'amounts'");
        } else {
            float x = origin.x + visibleSize.width / 2;
            float y = origin.y + visibleSize.height / 5 * 3;
            label->setPosition(Vec2(x,y));
            label->setAnchorPoint(Vec2(0.5,-2.5));
            label->setRotation(( ROT_DEGREE * ( 1 + ( i * 2 ) ) ) + 4 );
            this->addChild(label,2);
        }
    }

    // adding all the objects into the scene
    this->addChild(wheelPanelSprite,1);
    this->addChild(wheelBorder,3);
    this->addChild(wheelArrow,4);
    return true;
}

bool Start::init() {

    // 1. initialize Scene supercslass
    if(!Scene::init()) {
        return false;
    }


    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // 2. add play button
    initPlayButton(origin, visibleSize);

    // 3. add wheel sprite
    initWheel(origin, visibleSize);

    return true;
}

void Start::spinSceneCallback(Ref* pSender)
{
    // auto spinScene =
    // Director::getInstance()->replaceScene();
}