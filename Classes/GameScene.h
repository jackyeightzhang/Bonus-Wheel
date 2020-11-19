//
// GameScene.h
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 18 Nov 2020
// Date last modified: 19 Nov 2020
//

#ifndef __GAME_SCENE_H__
#define __GAME_SCENE_H__

#include "cocos2d.h"

class Game : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    // helper functions for initializing scene
    virtual cocos2d::Vector<cocos2d::Sprite*> initPrizes(const cocos2d::Vec2& origin,
                                                         const cocos2d::Size& visibleSize,
                                                         const float& wheelScale);
    virtual cocos2d::Vector<cocos2d::Label*> initAmounts(const cocos2d::Vec2& origin,
                                                         const cocos2d::Size& visibleSize,
                                                         const float& wheelScale);
    virtual bool initPlayButton(const cocos2d::Vec2& origin, const cocos2d::Size& visibleSize);
    virtual bool initWheel(const cocos2d::Vec2& origin, const cocos2d::Size& visibleSize);

    virtual bool init();
    virtual bool initSpin();


    // a callback method for when Play is pressed
    void spinSceneCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(Game);
};

#endif // __GAME_SCENE_H__
