#ifndef COLLIDER_WALL_H
#define COLLIDER_WALL_H

#include "SDLGameObject.h"
#include "BaseCreator.h"
#include "Game.h"

class ColliderWall : public SDLGameObject{
public:
	ColliderWall();

	void clean();
	void load(const LoaderParams* pParams);
	void update();
	void draw();
};

class ColliderWallCreator : public BaseCreator{
	GameObject* createGameObject() const{
		ColliderWall* wall = new ColliderWall();

		Game::Instance().addGameObject(wall);		
		return wall;
	}
};

#endif