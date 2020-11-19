//
// StartScene.h
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 18 Nov 2020
// Date last modified: 19 Nov 2020
//

#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class Start : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    // helper functions for initializing scene
    virtual bool initPlayButton(const cocos2d::Vec2& origin, const cocos2d::Size& visibleSize);
    virtual bool initWheel(const cocos2d::Vec2& origin, const cocos2d::Size& visibleSize);

    virtual bool init();

    // a callback method for when Play is pressed
    void spinSceneCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(Start);
};

#endif // __START_SCENE_H__
