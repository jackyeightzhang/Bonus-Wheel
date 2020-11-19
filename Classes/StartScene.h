//
// StartScene.h
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 18 Nov 2020
// Date last modified: 18 Nov 2020
//

#ifndef __START_SCENE_H__
#define __START_SCENE_H__

#include "cocos2d.h"

class Start : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    // a callback method for when Play is pressed
    void menuCloseCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(Start);
};

#endif // __START_SCENE_H__
