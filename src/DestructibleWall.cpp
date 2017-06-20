#include "DestructibleWall.h"
#include "Game.h"

DestructibleWall::DestructibleWall(){
	is_Visible = true;
}

void DestructibleWall::update(){
	m_textureID = "dstWall";
}

void DestructibleWall::draw(){
	if(is_Visible){
		SDLGameObject::draw();
	}
}

void DestructibleWall::clean(){
	SDLGameObject::clean();
}

void DestructibleWall::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
}