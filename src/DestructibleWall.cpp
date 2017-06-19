#include "DestructibleWall.h"
#include "Game.h"

DestructibleWall::DestructibleWall(){
	Game::Instance().addDestructibleWall(this);
}

void DestructibleWall::update(){
	
}

void DestructibleWall::draw(){
	SDLGameObject::draw();
}

void DestructibleWall::clean(){
	SDLGameObject::clean();
}

void DestructibleWall::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
}