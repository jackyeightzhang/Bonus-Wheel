//
// PrizeScene.cpp
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 19 Nov 2020
// Date last modified: 19 Nov 2020
//
#include "PrizeScene.h"
#include "GameScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Prize* Prize::create(int pr, float ps) {
    Prize *pRet = new(std::nothrow) Prize();
    if (pRet && pRet->init(pr,ps))
    {
        pRet->autorelease();
        return pRet;
    }
    else
    {
        delete pRet;
        pRet = NULL;
        return NULL;
    }
}

Scene* Prize::createScene(int pr, float ps) {
    return Prize::create(pr, ps);
}

static void problemLoading(const char* filename)
{
    CCLOGERROR("Error while loading: %s\n", filename);
}

bool Prize::init(int pr, float ps) {
    // initialize Scene supercslass
    if(!Scene::init()) {
        return false;
    }

    prizeNumber = pr;
    prizeSize = ps;

    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    auto visibleSize = Director::getInstance()->getVisibleSize();

    // create button
    auto playButton = ui::Button::create("spin_button.png",
                                         "spin_button.png",
                                         "spin_button.png");

    // setting button size
    playButton->setScale(MAX(playButton->getContentSize().width / visibleSize.width,
                             playButton->getContentSize().height / visibleSize.height));
    // setting button text
    playButton->setTitleAlignment(TextHAlignment::CENTER);
    playButton->setTitleText("Claim");

    // setting button functionality
    playButton->addTouchEventListener(CC_CALLBACK_1(Prize::claimPrizeCallBack,this));
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

    Sprite* prizeSprite;
    Label* prizeAmount;

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

    prizeSprite->setContentSize(Size(prizeSize,prizeSize));
    // check if sprite initialized properly
    if (prizeSprite == nullptr ||
        prizeSprite->getContentSize().width <= 0 ||
        prizeSprite->getContentSize().height <= 0) {
        problemLoading("'prize'");
    } else {
        // set location of the anchor point
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 3;
        prizeSprite->setPosition(Vec2(x,y));
        // push the sprite above the anchor point and set the rotation around the anchor point
        // to a sector in the panel
        prizeSprite->setAnchorPoint(Vec2(0.5,-2.5));
        this->addChild(prizeSprite,0);
    }

    // check if label initalization failed
    if (prizeAmount == nullptr ||
        prizeAmount->getContentSize().width <= 0 ||
        prizeAmount->getContentSize().height <= 0) {
        problemLoading("'amounts'");
    } else {
        // setting anchor point position
        float x = origin.x + visibleSize.width / 2;
        float y = origin.y + visibleSize.height / 5 * 3;
        prizeAmount->setPosition(Vec2(x,y));
        // set the sprite to be about the anchor point and rotated around to match the wheel panel
        prizeAmount->setAnchorPoint(Vec2(0.5,-2.5));
        this->addChild(prizeAmount,1);
    }

    auto emitter = ParticleSun::create();
//    emitter->setDuration(ParticleSystem::DURATION_INFINITY);
//    emitter->setEnd

auto shiftDown = MoveBy::create(2, Vec2(0, -visibleSize.height / 3));
    auto scaleUp = ScaleBy::create(2,1.5);
    auto spawnDisplay = Spawn::create(shiftDown, scaleUp, nullptr);

    auto sequence = Sequence::create(spawnDisplay, nullptr);

    prizeSprite->runAction(sequence);
    prizeAmount->runAction(sequence);

    return true;
}

void Prize::claimPrizeCallBack(Ref* pSender) {
    auto gameScene = Game::create();
    Director::getInstance()->replaceScene(gameScene);
}