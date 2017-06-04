#include "Bomb.h"
#include "Game.h"
#include <iostream>
#include "Timer.h"

using namespace std;

Explosion::Explosion(){
	time_to_live = 20;
	bornTime = Timer::Instance().step();
}

void Explosion::load(const LoaderParams *pParams){
	SDLGameObject::load(pParams);
}

void Explosion::update(){
	
	if(time_to_live > 0){
		time_to_live -= 1;
		m_currentFrame = 6;
	}
	else{
		m_currentFrame = 6;

		if(Timer::Instance().step() >= bornTime + time_to_live){
			Game::Instance().getStateMachine()->currentState()->removeGameObject(this);
			cout << "Explosion end" << endl;
		}
	}

}

void Explosion::draw(){
	SDLGameObject::draw();
}

void Explosion::clean(){
	SDLGameObject::clean();
}