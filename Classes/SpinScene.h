//
// SpinScene.h
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 19 Nov 2020
// Date last modified: 19 Nov 2020
//

#ifndef __SPIN_SCENE_H__
#define __SPIN_SCENE_H__

#include "cocos2d.h"

class Spin : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    // helper functions for initializing scene
    virtual int prizeOutput();
    virtual float prizeRotation(int prize);

    virtual bool init();

    // a callback method for when Play is pressed
    void spinEndCallback(cocos2d::Ref* pSender);

    CREATE_FUNC(Spin);
};

#endif // __SPIN_SCENE_H__
