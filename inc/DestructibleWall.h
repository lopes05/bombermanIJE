#ifndef DESTRUCTIBLE_WALL_H
#define DESTRUCTIBLE_WALL_H

#include "ColliderWall.h"
#include "BaseCreator.h"

class DestructibleWall : public ColliderWall{

public:
	DestructibleWall();

	virtual void clean();
	virtual void load(const LoaderParams* pParams);
	virtual void update();
	virtual void draw();

};


class DestructibleWallCreator : public BaseCreator{
	GameObject* createGameObject() const{
		ColliderWall* wall = new ColliderWall();

		Game::Instance().addGameObject(wall);		
		return wall;
	}
};

#endif