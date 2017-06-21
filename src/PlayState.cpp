#include "PlayState.h"
#include "GameState.h"
#include "GameObject.h"
#include "TextureManager.h"
#include "Game.h"
#include "Player.h"
#include "PauseState.h"
#include "InputHandler.h"
#include "Enemy.h"
#include "GameOverState.h"
#include "SDLGameObject.h"
#include "StateParser.h"
#include "Level.h"
#include "LevelParser.h"

#include <string>
#include <iostream>

using namespace std;

const string PlayState::s_playID = "PLAY";

Level *pLevel = NULL;

void PlayState::update(){
	//if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_ESCAPE)){
	//	Game::Instance().getStateMachine()->pushState(new PauseState());
	//}

	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_P))
		Game::Instance().getStateMachine()->pushState(new PauseState());

	GameState::update();
	if(pLevel != NULL)
		pLevel->update();

	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_Q)){
		Game::Instance().getStateMachine()->pushState(new GameOverState());
	}
}

void PlayState::render(){

	if(pLevel != NULL){
		pLevel->render();
	}


	GameState::render();
}

bool PlayState::onEnter(){	
	//StateParser stateParser;
	//stateParser.parseState("test.xml", s_playID, &m_gameObjects, &m_textureIDList);

	LevelParser levelParser;
	pLevel = levelParser.parseLevel("assets/mapadoidao.tmx");

	cout <<	"Entering PlayState" << endl;
	return true;
}

bool PlayState::onExit(){
	GameState::onExit();

	TextureManager::Instance().clearFromTextureMap("helicopter");

	for(auto gameObj : m_gameObjects){
		Game::Instance().getStateMachine()->currentState()->removeGameObject(gameObj);
	}

	for(auto gameObj : m_BombsPlayer2){
		Game::Instance().getStateMachine()->currentState()->removeGameObject(gameObj);
	}

	cout << "Exiting PlayState" << endl;	
	return true;
}
