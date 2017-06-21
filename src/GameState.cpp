#include "GameState.h"
#include "GameObject.h"
#include "TextureManager.h"

#include <iostream>

void GameState::update(){
	for(auto gameObject : m_gameObjects){
		gameObject->update();
	}

	for(auto gameObject : m_BombsPlayer2){
		gameObject->update();
	}
}

void GameState::render(){
	for(auto gameObject : m_gameObjects){
		gameObject->draw();
	}

	for(auto gameObject : m_BombsPlayer2){
		gameObject->draw();
	}
}

bool GameState::onExit(){
	can_update = false;
	for(auto gameObject : m_gameObjects){
		gameObject->clean();
	}

	for(auto gameObject : m_BombsPlayer2){
		gameObject->clean();
	}
	
	for(auto s : m_textureIDList){
		TextureManager::Instance().clearFromTextureMap(s);
	}

	m_gameObjects.clear();

	return true;
}
