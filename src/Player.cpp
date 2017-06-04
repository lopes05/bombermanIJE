#include "Player.h"
#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "InputHandler.h"
#include "Game.h"

#include <string>
#include <SDL2/SDL.h>
#include <iostream>
#include <cmath>

using namespace std;

Player::Player() : SDLGameObject(){
	//TextureManager::Instance().load("assets/clash2.png", "bullet", Game::Instance().getRenderer());
}

void Player::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
}

void Player::draw(){
	SDLGameObject::draw();
}

void Player::update(){
	m_currentFrame = int(((SDL_GetTicks() / 300) % 6));


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

	movement = movement.norm();

	m_velocity = movement;
	m_position += m_velocity;
}

void Player::useSkill(){
	
	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_X, 100)){
		
	}
}
