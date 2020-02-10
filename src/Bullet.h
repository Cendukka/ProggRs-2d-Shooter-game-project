#pragma once

#ifndef __BULLET__
#define __BULLET__

#include <vector>

#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Comet.h"


class Bullet : public DisplayObject
{
public:
	Bullet();
	~Bullet();

	void draw() override;
	void update() override;
	void clean() override;

	void setActive(bool active);
	bool isActive();

	void fire(glm::vec2 position);
	//setter
	void setSpeed(float newSpeed);
	//getter
	float getSpeed();
	void checkBounds();
	void setComet(Comet* pcomet);

private:

	Uint8 m_alpha;
	bool m_isActive;
	Comet* m_pComet;
	float m_speed;

};




#endif
