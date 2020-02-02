#pragma once

#ifndef __BULLET__
#define __BULLET__

#include <vector>

#include "DisplayObject.h"



class Bullet : public DisplayObject
{
public:
	Bullet();
	~Bullet();
	
	void draw() override;
	void update() override;
	void clean() override;

	//setter
	void setSpeed(float newSpeed);
	//getter
	float getSpeed();
	void checkBounds();
	
private:
	
	
	
	float m_speed;
	
};




#endif

