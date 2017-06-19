#ifndef GAME_H
#define GAME_H

#include "TextureManager.h"
#include "GameObject.h"
#include "GameStateMachine.h"
#include "SDLGameObject.h"
#include <SDL2/SDL.h>
#include <vector>
#include "Enemy.h"
#include "Player.h"

class Game{
public:
	
	static Game& Instance(){
		static Game game;

		return game;
	}

	Game(Game const&) = delete;
	void operator=(Game const&) = delete;

	bool init(const char*, int, int, int, int, bool);

	void render();
	void update();
	void handleEvents();
	void clean();
	void draw();
	void quit();

	SDL_Renderer* getRenderer(){
		return m_pRenderer;
	}

	bool running() { return m_bRunning; }
	GameStateMachine* getStateMachine(){
		return m_pGameStateMachine;
	}

	int getGameWidth() const{
		return m_gameWidth;
	}

	int getGameHeight() const {
		return m_gameHeight;
	}

	void addGameObject(SDLGameObject *obj){
		m_gameObjects.push_back(obj);
	}

	std::vector<SDLGameObject*> getGameObjs(){
		return m_gameObjects;
	}

	void setPlayer(Player* player){
		this->player = player;
	}

	Player* getPlayer(){
		return this->player;
	}


	void setPlayer2(Enemy* player){
		this->player2 = player;
	}

	Enemy* getPlayer2(){
		return this->player2;
	}

private:
	Game() {}

	int m_gameWidth;
	int m_gameHeight;

	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;

	GameObject* m_go;
	Player* player;
	Enemy* player2;
	GameObject* m_enemy;

	std::vector<SDLGameObject*> m_gameObjects;

	int m_currentFrame;
	bool m_bRunning;

	GameStateMachine *m_pGameStateMachine;
};

#endif
