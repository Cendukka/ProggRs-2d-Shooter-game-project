#pragma once
#ifndef __COMET__
#define __COMET__

#include <vector>

#include "DisplayObject.h"
#include "TextureManager.h"
#include "SoundManager.h"

class Comet:public DisplayObject
{
public:
	Comet();
	~Comet();
	void draw() override;
	void update() override;
	void clean() override;
	void move();
	void reset();
	void getDamage();
	void setActive(bool active);
	bool isActive();
private:
	float m_maxSpeed;
	double m_currentDirection;
	Uint8 m_alpha;
	bool m_isActive;
	int m_health;
	int m_angle;
};

#endif
