#pragma once

#ifndef __ENEMY_BULLET__
#define __ENEMY_BULLET__

#include <vector>

#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Comet.h"


class EnemyBullet : public DisplayObject
{
public:
	EnemyBullet();
	~EnemyBullet();

	void draw() override;
	void update() override;
	void clean() override;

	void setActive(bool active);
	bool isActive();

	void fire(glm::vec2 position);
	void fire(glm::vec2 position, float ySpeed);
	//setter
	void setSpeed(float newSpeed);
	//getter
	float getSpeed();
	void checkBounds();
	void reset();

private:

	Uint8 m_alpha;
	bool m_isActive;
	float m_xSpeed;
	float m_ySpeed;

};




#endif
