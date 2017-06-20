#include "Bomb.h"
#include "Game.h"
#include <iostream>
#include "Timer.h"
#include "Physics.h"
#include "GameOverState.h"
#include <unistd.h>
#include "DestructibleWall.h"

using namespace std;

Explosion::Explosion(int x, int y){
	time_to_live = 20;
	bornTime = Timer::Instance().step();
	this->load(new LoaderParams(x, y,
				 21, 25, "exp", 10));
	Game::Instance().getStateMachine()->currentState()->addGameObject(this);
			
}

void Explosion::load(const LoaderParams *pParams){
	SDLGameObject::load(pParams);
}

void Explosion::update(){
	
	if(time_to_live > 0){
		time_to_live -= 1;
		m_currentFrame = 1;
	}
	else{
		m_currentFrame = 1;

		if(Timer::Instance().step() >= bornTime + time_to_live){
			Game::Instance().getStateMachine()->currentState()->removeGameObject(this);
			cout << "Explosion end" << endl;
		}
	}

	if(Physics::Instance().checkWallCollision(dynamic_cast<SDLGameObject*>(this), 
		dynamic_cast<SDLGameObject*>(Game::Instance().getPlayer()))){
		cout << "GG! PLAYER 2 WINS" << endl;
		Game::Instance().getStateMachine()->changeState(new GameOverState());
	}

	if(Physics::Instance().checkWallCollision(dynamic_cast<SDLGameObject*>(this), 
		dynamic_cast<SDLGameObject*>(Game::Instance().getPlayer2()))){
		cout << "GG! PLAYER 1 WINS" << endl;
		Game::Instance().getStateMachine()->changeState(new GameOverState());
	}

	removeExplosionFixedWall();
	removeDestructibleWall();


}

void Explosion::removeExplosionFixedWall(){
	for(auto &x: Game::Instance().getGameObjs())
		if(Physics::Instance().checkWallCollision(dynamic_cast<SDLGameObject*>(this),
			dynamic_cast<SDLGameObject*>(x))){
			Game::Instance().getStateMachine()->currentState()->removeGameObject(this);
		}
}

void Explosion::removeDestructibleWall(){
	for(auto &x: Game::Instance().getDestructibleWalls())
		if(Physics::Instance().checkCollision(dynamic_cast<SDLGameObject*>(this),
			dynamic_cast<SDLGameObject*>(x))){
			Game::Instance().removeDestructibleWall(x);
			Game::Instance().getStateMachine()->currentState()->removeGameObject(this);
			cout << "Removed a destructible wall" << endl;
			dynamic_cast<DestructibleWall*>(x)->setVisible(false);
		}
}

void Explosion::draw(){
	SDLGameObject::draw();
}

void Explosion::clean(){
	SDLGameObject::clean();
}