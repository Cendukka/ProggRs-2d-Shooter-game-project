#pragma once

#ifndef __MISSILE__
#define __MISSILE__

#include <vector>
#include "DisplayObject.h"
#include <SDL_hints.h>
#include "Comet.h"

//enum MissilePosition
//{
//	TOP,
//	MIDDLE,
//	BOTTOM
//};

class Missile : public DisplayObject
{
public:
	Missile();
	~Missile();

	void draw() override;
	void update() override;
	void clean() override;

	void setActive(bool active);
	bool isActive();

	void fire(glm::vec2 position);
	void fire(glm::vec2 position, glm::vec2 destination);
	//void fire(glm::vec2 position, MissilePosition missilePosition);
	//setter
	void setSpeed(float newSpeed);
	//getter
	float getSpeed();
	void checkBounds();
	void setComet(Comet* pcomet);
	void reset();

private:

	Uint8 m_alpha;
	bool m_isActive;
	Comet* m_pComet;
	float m_speed;
	glm::vec2 m_destination;

	//MissilePosition m_missilePosition;


};




#endif
