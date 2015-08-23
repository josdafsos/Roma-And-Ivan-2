#include "GameScene.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* GameScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
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

	koala_ = new Koala(this);

	ui::Button* button = ui::Button::create("Button_Normal.png", "Button_Disable.png");
	button->setAnchorPoint(Point::ZERO);
	button->setPosition(Vec2(visibleSize.width - button->getContentSize().width * 2, visibleSize.height / 4));
	button->setTitleText("Go!");
	this->addChild(button);
	
	

	return true;
}

