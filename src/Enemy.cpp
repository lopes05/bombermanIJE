#include "Enemy.h"
#include "InputHandler.h"
#include "Game.h"
#include "Bomb.h"
#include <iostream>
#include <string>
#include "Physics.h"
#include "BombUpgrader.h"

using namespace std;

Enemy::Enemy() : SDLGameObject(){
	setBonus(1);
	m_totalHealth = 1000;
	m_actualHealth = m_totalHealth;
	m_state = FULL;
	Game::Instance().setPlayer2(this);
	TextureManager::Instance().load("assets/destWall.png", "destWall", 
		Game::Instance().getRenderer());
	TextureManager::Instance().load("assets/bomber2side.png", "bomber2side", 
		Game::Instance().getRenderer());
	TextureManager::Instance().load("assets/bomber2up.png", "bomber2up", 
		Game::Instance().getRenderer());

	TextureManager::Instance().load("assets/player1wins.png", "player1wins", 
		Game::Instance().getRenderer());
		
}

void Enemy::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);

	}

void Enemy::update(){
	m_currentFrame = int(((SDL_GetTicks() / 300) % m_numFrames));
	move();
	useSkill();

	if(m_velocity == Vector2D(0, 0)){
		m_currentFrame = 0;
	}


	increaseExplosionSize();
	SDLGameObject::update();

}

void Enemy::clean(){
	SDLGameObject::clean();
}

void Enemy::draw(){
	SDLGameObject::draw();
}

void Enemy::move(){
		Vector2D movement(0, 0);

	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_UP)){
		movement += Vector2D(0, -1.5);
	}

	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_DOWN)){
		movement += Vector2D(0, +1.5);
	}

	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_RIGHT)){
		movement += Vector2D(1.5, 0);
	}


	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_LEFT)){
		movement += Vector2D(-1.5, 0);
	}

	if(movement.getY() == 0){
		if(movement.getX() > 0){
			m_textureID = "bomber2side";
		}
		else if(movement.getX()< 0){
			m_textureID = "bomber2side";
		}
		else{
			m_textureID = "bomber2";
		}
	}
	else{
		if(movement.getY() > 0){
			m_textureID = "bomber2";
		}
		else{
			m_textureID = "bomber2up";
		}
	}

	movement = movement.norm();

	m_velocity = movement;
	
	for(auto &x: Game::Instance().getGameObjs())
		if(Physics::Instance().checkWallCollision(dynamic_cast<SDLGameObject*>(this),
			dynamic_cast<SDLGameObject*>(x))){
			m_velocity = Physics::Instance().getNormal(dynamic_cast<SDLGameObject*>(this),
					dynamic_cast<SDLGameObject*>(x));
		}

	for(auto &x: Game::Instance().getDestructibleWalls())
		if(Physics::Instance().checkWallCollision(dynamic_cast<SDLGameObject*>(this),
			dynamic_cast<SDLGameObject*>(x))){
			m_velocity = Physics::Instance().getNormal(dynamic_cast<SDLGameObject*>(this),
					dynamic_cast<SDLGameObject*>(x));
		}

	m_velocity = m_velocity.norm();
	m_position += m_velocity;

}


void Enemy::useSkill(){
	
	if(InputHandler::Instance().isKeyDown(SDL_SCANCODE_L, 1000)){
		Bomb *bomb = bCreator.create();
		bomb->load(new LoaderParams(m_position.getX() + 5, m_position.getY() + 5, 21, 25, "bomba",
			10));
		Game::Instance().getStateMachine()->currentState()->addPlayer2Bomb(bomb);
		cout << "Bomba criada" << endl;
	}
}

void Enemy::increaseExplosionSize(){
	for(auto &x: Game::Instance().getStateMachine()->currentState()->getUpgraders())
		if(Physics::Instance().checkWallCollision(dynamic_cast<SDLGameObject*>(this),
			dynamic_cast<SDLGameObject*>(x))){
			setBonus(getBonus() + 1);
			dynamic_cast<BombUpgrader*>(x)->setVisible(false);
			Game::Instance().getStateMachine()->currentState()->removeUpgrader(x);
			cout << "Player 2 got an item." << endl;
		}
}
