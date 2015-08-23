#include "MainMenuScene.h"
#include "GameScene.h"
#include "Definitions.h"

USING_NS_CC;

Scene* MainMenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MainMenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainMenuScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    //adding background. Разобратьболее сложные случаи для разных экранов
	auto background = Sprite::create("background.png");
	background->setAnchorPoint(Point::ZERO);
	background->setPosition(Point::ZERO);
	this->addChild(background, -1);

	//adding menu items. In future will added an array from labeles. add label position
	auto startLabel = LabelTTF::create("Start", "Marker Felt.ttf", 32);
	auto startMenuItem = MenuItemLabel::create(startLabel, CC_CALLBACK_1(MainMenuScene::goToStartScene, this));
	startMenuItem->setPosition(Point((visibleSize.width + startMenuItem->getContentSize().width) / 2, visibleSize.height - (startMenuItem->getContentSize().height * 2)));

	auto quitLabel = LabelTTF::create("Quit", "Marker Felt.ttf", 32);
	auto quitItem = MenuItemLabel::create(quitLabel, CC_CALLBACK_1(MainMenuScene::menuCloseCallback, this));
	quitItem->setPosition(Point((visibleSize.width + quitItem->getContentSize().width) / 2, quitItem->getContentSize().height * 2));

	//add items in menu
	auto menu = Menu::create(startMenuItem, quitItem, NULL);
	menu->setPosition(Point::ZERO);
	this->addChild(menu, 1);

    return true;
}

void MainMenuScene::goToStartScene(Ref* pSender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_SCENES_TIME, scene));
}

void MainMenuScene::menuCloseCallback(Ref* pSender)
{
    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
