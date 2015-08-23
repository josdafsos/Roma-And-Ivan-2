#ifndef __KOALA_H__
#define __KOALA_H__

#include "cocos2d.h"

class Koala
{
public:

	enum Direction
	{
		DIRECTION_LEFT = 1,
		DIRECTION_RIGHT,
		DIRECTION_NONE
	};

	Koala(cocos2d::Layer *layer);
	~Koala(){}

	void jump();
	void move();

	Direction getDirection() { return direction_; }
	void setDirection(Direction direction) { direction_ = direction; }

	bool getIsJimp() { return isJump_;  }
	void setIsJump(bool isJump) { isJump_ = isJump; }

private:


	cocos2d::Size visibleSize;
	cocos2d::Vec2 origin;

	cocos2d::Sprite *koala_;

	Direction direction_;
	bool isJump_;

};

#endif // __KOALA_H__