//
// GameScene.cpp
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 18 Nov 2020
// Date last modified: 19 Nov 2020
//

#include "GameScene.h"
#include "SpinScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* Game::createScene() {
    return Game::create();
}

static void problemLoading(const char* filename)
{
    CCLOGERROR("Error while loading: %s\n", filename);
}

bool Game::initPlayButton(const Vec2& origin, const Size& visibleSize) {
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
    playButton->addTouchEventListener(CC_CALLBACK_1(Game::spinSceneCallback,this));
    playButton->setPressedActionEnabled(true);
    playButton->setZoomScale(-0.5);

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

Vector<Sprite*> Game::initPrizes(Scene* scene, const Vec2& origin, const Size& visibleSize, const float& wheelScale) {
    // create sprites and insert into vector
    auto life30Sprite_1 = Sprite::create("heart.png");
    auto brush3Sprite_2 = Sprite::create("brush.png");
    auto gems35Sprite_3 = Sprite::create("gem.png");
    auto hammer3Sprite_4 = Sprite::create("hammer.png");
    auto coins750Sprite_5 = Sprite::create("coin.png");
    auto brush1Sprite_6 = Sprite::create("brush.png");
    auto gems75Sprite_7 = Sprite::create("gem.png");
    auto hammer1Sprite_8 = Sprite::create("hammer.png");

    Vector<Sprite*> prizes = { life30Sprite_1, brush3Sprite_2, gems35Sprite_3, hammer3Sprite_4,
                               coins750Sprite_5, brush1Sprite_6, gems75Sprite_7, hammer1Sprite_8 };


    float ROT_DEGREE = 360/16;
    float PRIZE_SIZE = wheelScale * life30Sprite_1->getContentSize().height;

    for(int i = 0; i < prizes.size(); i++) {
        auto sprite = prizes.at(i);
        sprite->setContentSize(Size(PRIZE_SIZE,PRIZE_SIZE));
        // check if sprite initialized properly
        if (sprite == nullptr ||
            sprite->getContentSize().width <= 0 ||
            sprite->getContentSize().height <= 0) {
            problemLoading("'prize'");
        } else {
            // set location of the anchor point
            float x = origin.x + visibleSize.width / 2;
            float y = origin.y + visibleSize.height / 5 * 3;
            sprite->setPosition(Vec2(x,y));
            // push the sprite above the anchor point and set the rotation around the anchor point
            // to a sector in the panel
            sprite->setAnchorPoint(Vec2(0.5,-2.5));
            sprite->setRotation( ROT_DEGREE * ( 1 + ( i * 2 ) ) );
            scene->addChild(sprite,2);
        }
    }
    return prizes;
}
Vector<Label*> Game::initAmounts(Scene* scene, const Vec2& origin, const Size& visibleSize, const float& prize_size) {
    // create prize labels
    auto life30Label_1 = Label::createWithSystemFont("30x\nmins","Arial", 9,
                                                Size(prize_size,prize_size),
                                                TextHAlignment::RIGHT,
                                                TextVAlignment::BOTTOM);
    auto brush3Label_2 = Label::createWithSystemFont("3x","Arial", 9,
                                                Size(prize_size,prize_size),
                                                TextHAlignment::RIGHT,
                                                TextVAlignment::BOTTOM);
    auto gems35Label_3 = Label::createWithSystemFont("35x","Arial", 9,
                                                Size(prize_size,prize_size),
                                                TextHAlignment::RIGHT,
                                                TextVAlignment::BOTTOM);
    auto hammer3Label_4 = Label::createWithSystemFont("3x","Arial", 9,
                                                Size(prize_size,prize_size),
                                                TextHAlignment::RIGHT,
                                                TextVAlignment::BOTTOM);
    auto coins750Label_5 = Label::createWithSystemFont("750x","Arial", 9,
                                                 Size(prize_size,prize_size),
                                                 TextHAlignment::RIGHT,
                                                 TextVAlignment::BOTTOM);
    auto brush1Label_6 = Label::createWithSystemFont("1x","Arial", 9,
                                                Size(prize_size,prize_size),
                                                TextHAlignment::RIGHT,
                                                TextVAlignment::BOTTOM);
    auto gems75Label_7 = Label::createWithSystemFont("75x","Arial", 9,
                                                Size(prize_size,prize_size),
                                                TextHAlignment::RIGHT,
                                                TextVAlignment::BOTTOM);
    auto hammer1Label_8 = Label::createWithSystemFont("1x","Arial", 9,
                                                Size(prize_size,prize_size),
                                                TextHAlignment::RIGHT,
                                                TextVAlignment::BOTTOM);

    Vector<Label*> amounts = { life30Label_1, brush3Label_2, gems35Label_3, hammer3Label_4,
                               coins750Label_5, brush1Label_6, gems75Label_7, hammer1Label_8 };

    float ROT_DEGREE = 360/16;

    for(int i = 0; i < amounts.size(); i++) {
        auto label = amounts.at(i);

        // check if label initalization failed
        if (label == nullptr ||
            label->getContentSize().width <= 0 ||
            label->getContentSize().height <= 0) {
            problemLoading("'amounts'");
        } else {
            // setting anchor point position
            float x = origin.x + visibleSize.width / 2;
            float y = origin.y + visibleSize.height / 5 * 3;
            label->setPosition(Vec2(x,y));

            // set the sprite to be about the anchor point and rotated around to match the wheel panel
            label->setAnchorPoint(Vec2(0.5,-2.5));
            label->setRotation(( ROT_DEGREE * ( 1 + ( i * 2 ) ) ) + 5 );
            scene->addChild(label,2);
        }
    }

    return amounts;
}

bool Game::initWheelMisc(Scene* scene, const cocos2d::Vec2& origin, const cocos2d::Size& visibleSize, const float& wheelScale) {
    // create wheel border node
    auto wheelBorder = Sprite::create("wheel_border.png");

    wheelBorder->setScale(wheelScale);

    // check to see if border does not load correctly
    if (wheelBorder == nullptr ||
        wheelBorder->getContentSize().width <= 0 ||
        wheelBorder->getContentSize().height <= 0) {
        problemLoading("'wheel border'");
    } else {
        // set location of border
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 3;
        wheelBorder->setPosition(Vec2(x,y));
    }

    // create wheel arrow, last because it is infront of the wheel border and wheel panel
    auto wheelArrow = Sprite::create("wheel_arrow.png");

    wheelArrow->setScale(wheelScale);

    // check to see if arrow does not load correctly
    if (wheelArrow == nullptr ||
        wheelArrow->getContentSize().width <= 0 ||
        wheelArrow->getContentSize().height <= 0) {
        problemLoading("'wheel arrow'");
    } else {
        // set location of arrow
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 4;
        wheelArrow->setPosition(Vec2(x,y));
    }

    scene->addChild(wheelBorder,3);
    scene->addChild(wheelArrow,4);

    return true;
}

bool Game::initWheel(const Vec2& origin, const cocos2d::Size& visibleSize){
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

    // add misc wheel nodes
    initWheelMisc(this, origin, visibleSize, wheelScale);

    // add prizes sprites
    Vector<Sprite*> prizes = initPrizes(this, origin, visibleSize, wheelScale);

    // add prize labels
    float prize_size = wheelScale * prizes.at(0)->getContentSize().height;
    initAmounts(this, origin, visibleSize, prize_size);

    // adding all the objects into the scene
    this->addChild(wheelPanelSprite,1);

    return true;
}

bool Game::init() {

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

void Game::spinSceneCallback(Ref* pSender)
{
    auto spinScene = Spin::create();
    Director::getInstance()->replaceScene(spinScene);
}