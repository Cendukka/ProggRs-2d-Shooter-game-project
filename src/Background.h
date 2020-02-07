#pragma once
#ifndef __BACKGROUND__
#define __BACKGROUND__
#include "DisplayObject.h"


class Background : public DisplayObject
{
	Background();
	~Background();


public:
	void draw() override;
	void update() override;
	void clean() override;

	
private:
};

#endif /* Defined background*/