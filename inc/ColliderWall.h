#ifndef COLLIDER_WALL_H
#define COLLIDER_WALL_H

#include "SDLGameObject.h"
#include "BaseCreator.h"
#include "Game.h"

class ColliderWall : public SDLGameObject{
public:
	ColliderWall();

	virtual void clean();
	virtual void load(const LoaderParams* pParams);
	virtual void update();
	virtual void draw();
};

class ColliderWallCreator : public BaseCreator{
	GameObject* createGameObject() const{
		ColliderWall* wall = new ColliderWall();

		Game::Instance().addGameObject(wall);		
		return wall;
	}
};

#endif