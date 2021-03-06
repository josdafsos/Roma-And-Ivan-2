#ifndef __MAINMENU_SCENE_H__
#define __MAINMENU_SCENE_H__


#include "cocos2d.h"

class MainMenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    
	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);

    // implement the "static create()" method manually
    CREATE_FUNC(MainMenuScene);

private:
	void goToStartScene(cocos2d::Ref* pSeder);
};

#endif // __MAINMENU_SCENE_H__
