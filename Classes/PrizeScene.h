//
// PrizeScene.h
//
// Author: Jacky Zhang (jackyeightzhang)
// Date created: 19 Nov 2020
// Date last modified: 19 Nov 2020
//

#ifndef __PRIZE_SCENE_H__
#define __PRIZE_SCENE_H__

#include "cocos2d.h"

class Prize : public cocos2d::Scene {
public:
    static cocos2d::Scene* createScene();

    virtual bool init();

    void claimPrizeCallBack(cocos2d::Ref* pSender);

    CREATE_FUNC(Prize);

private:
    int prizeNumber;
    float prizeSize;
};

#endif // __PRIZE_SCENE_H__
