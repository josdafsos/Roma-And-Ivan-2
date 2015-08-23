#include "Koala.h"

USING_NS_CC;

Koala::Koala(Layer *layer)
{
	//�� ��� �� ���� ��������� ��� ������� �������?
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	direction_ = DIRECTION_NONE;
	isJump_ = false;

	koala_ = Sprite::create("koala_idle.png");
	koala_->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 4 + origin.y));

	layer->addChild(koala_, 10);
}

void Koala::move()
{
	//�������� �� ����������� 
	if (direction_ == DIRECTION_RIGHT)
	{
		auto koalaAction = MoveBy::create(1, Vec2(1, 0));
		koala_->runAction(koalaAction);
	}
	else if (direction_ == DIRECTION_LEFT)
	{
		auto koalaAction = MoveBy::create(1, Vec2(-1, 0));
		koala_->runAction(koalaAction);
	}
	direction_ = DIRECTION_NONE;

	//�������� �� ���������
	if (isJump_ = true)
	{

	}
	isJump_ = false;
	//�������� ���� ������� ������������������ �������� 
}

