#include "Bomb.h"
#include "Game.h"
#include <iostream>
#include "Timer.h"
#include "Explosion.h"

using namespace std;

Bomb::Bomb(){
	time_to_live = 150;
	bornTime = Timer::Instance().step();
	//Game::Instance().addGameObject(this);
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
			int x = -21*4;
			int y = -25 * 4;
			for(int i = 0; i < 9; i++){
				Explosion *exp1 = explosionCreator.create(this->getPosition().getX() + x, 
					this->getPosition().getY());
				x+=21;
			}
			

			for(int i = 0; i < 9; i++){
				Explosion *exp1 = explosionCreator.create(this->getPosition().getX(), 
					this->getPosition().getY() + y);
				y+=21;
			}
		}
	}

}

void Bomb::draw(){
	SDLGameObject::draw();
}

void Bomb::clean(){
	SDLGameObject::clean();
}