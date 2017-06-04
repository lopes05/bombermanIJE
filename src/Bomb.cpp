#include "Bomb.h"
#include "Game.h"
#include <iostream>
#include "Timer.h"
#include "Explosion.h"

using namespace std;

Bomb::Bomb(){
	time_to_live = 150;
	bornTime = Timer::Instance().step();
}

void Bomb::load(const LoaderParams *pParams){
	SDLGameObject::load(pParams);
}

void Bomb::update(){
	
	if(time_to_live > 0){
		time_to_live -= 1;
		m_currentFrame = int(((SDL_GetTicks() / 300) % 3));
	}
	else{
		m_currentFrame = 5;

		if(Timer::Instance().step() >= bornTime + time_to_live){
			Vector2D aux = m_position;
			Game::Instance().getStateMachine()->currentState()->removeGameObject(this);
			
			cout << "Bomba explodiu" << endl;


		}
	}

}

void Bomb::draw(){
	SDLGameObject::draw();
}

void Bomb::clean(){
	SDLGameObject::clean();
}