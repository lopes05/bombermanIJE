#include "DestructibleWall.h"
#include "Game.h"

DestructibleWall::DestructibleWall(){
	
	
}

void DestructibleWall::update(){
	m_textureID = "destWall";
	SDLGameObject::update();
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