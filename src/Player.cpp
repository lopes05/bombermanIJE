#include "Player.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Game.h"
#include "Physics.h"
#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

using namespace std;

Player::Player() : SDLGameObject(){
	//TextureManager::Instance().load("assets/clash2.png", "bullet", Game::Instance().getRenderer());
	TextureManager::Instance().load("assets/bombas.png", "bomba", Game::Instance().getRenderer());
	TextureManager::Instance().load("assets/explosion.png", "exp", Game::Instance().getRenderer());
	TextureManager::Instance().load("assets/bombermanup.png", "bup", Game::Instance().getRenderer());
	TextureManager::Instance().load("assets/bombermanside.png", "bside", Game::Instance().getRenderer());
	//Game::Instance().addGameObject(this);
	Game::Instance().setPlayer(this);
}

void Player::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update(){
	m_currentFrame = int(((SDL_GetTicks() / 300) % m_numFrames));


	handleInput();

	if(m_velocity == Vector2D(0, 0)){
		m_currentFrame = 0;
	}

	SDLGameObject::update();
}

void Player::clean(){
	SDLGameObject::clean();
}

void Player::handleInput(){
	move();
	useSkill();
	
}

void Player::move(){
	Vector2D movement(0, 0);

	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_W)){
		movement += Vector2D(0, -1);
	}

	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_S)){
		movement += Vector2D(0, +1);
	}

	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_D)){
		movement += Vector2D(1, 0);
	}


	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_A)){
		movement += Vector2D(-1, 0);
	}

	if(movement.getY() == 0){
		if(movement.getX() > 0){
			m_textureID = "bside";
		}
		else if(movement.getX()< 0){
			m_textureID = "bside";
		}
		else{
			m_textureID = "helicopter";
		}
	}
	else{
		if(movement.getY() > 0){
			m_textureID = "helicopter";
		}
		else{
			m_textureID = "bup";
		}
	}

	movement = movement.norm();

	m_velocity = movement;
	
	for(auto &x: Game::Instance().getGameObjs())
		if(Physics::Instance().checkCollision(dynamic_cast<SDLGameObject*>(this),
			dynamic_cast<SDLGameObject*>(x))){
			m_velocity = Physics::Instance().getNormal(dynamic_cast<SDLGameObject*>(this),
					dynamic_cast<SDLGameObject*>(x));
		}

	m_velocity = m_velocity.norm();
	m_position += m_velocity;

}

void Player::useSkill(){
	
	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_X, 1000)){
		Bomb *bomb = bCreator.create();
		bomb->load(new LoaderParams(m_position.getX() + 5, m_position.getY() + 5, 21, 25, "bomba",
			10));
		Game::Instance().getStateMachine()->currentState()->addGameObject(bomb);
		cout << "Bomba criada" << endl;
	}
}
