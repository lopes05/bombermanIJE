#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "GameObject.h"

#include <algorithm>
#include <string>
#include <vector>

class GameState{
public:
	virtual void update();
	virtual void render();

	virtual bool onEnter() = 0;
	virtual bool onExit();

	virtual std::string getStateID() const = 0;

	virtual ~GameState() {}

	void addGameObject(GameObject* gameObject){
		m_gameObjects.push_back(gameObject);
	}

	void removeGameObject(GameObject* gameObject){
		std::vector<GameObject*>::iterator position = std::find(m_gameObjects.begin(), m_gameObjects.end(), gameObject);
		if(position != m_gameObjects.end()){
			m_gameObjects.erase(position);
		}
	}

	void addPlayer2Bomb(GameObject* gameObject){
		m_BombsPlayer2.push_back(gameObject);
	}

	void removePlayer2Bomb(GameObject* gameObject){
		std::vector<GameObject*>::iterator position = std::find(m_BombsPlayer2.begin(), m_BombsPlayer2.end(), gameObject);
		if(position != m_BombsPlayer2.end()){
			m_BombsPlayer2.erase(position);
		}
	}

	void addUpgrader(GameObject* gameObject){
		m_upgraders.push_back(gameObject);
	}

	void removeUpgrader(GameObject* gameObject){
		std::vector<GameObject*>::iterator position = std::find(m_upgraders.begin(), m_upgraders.end(), gameObject);
		if(position != m_upgraders.end()){
			m_upgraders.erase(position);
		}
	}


	GameObject* getTail(){
		return m_gameObjects.back();
	}

	std::vector<GameObject*> getGameObjs(){
		return m_gameObjects;
	}

	std::vector<GameObject*> getPlayer2Bombs(){
		return m_BombsPlayer2;
	}

	std::vector<GameObject*> getUpgraders(){
		return m_upgraders;
	}


	bool can_update = true;
protected:
	std::vector<GameObject*> m_gameObjects;
	std::vector<GameObject*> m_BombsPlayer2;
	std::vector<GameObject*> m_upgraders;

	std::vector<GameObject*> m_tiles;
	std::vector<std::string> m_textureIDList;
	
};

#endif
