#include "BombPlayer2.h"
#include "Game.h"
#include <iostream>
#include "Timer.h"
#include "Explosion.h"

using namespace std;

BombPlayer2::BombPlayer2(){
	time_to_live = 150;
	bornTime = Timer::Instance().step();
	//Game::Instance().addGameObject(this);
}

void BombPlayer2::load(const LoaderParams *pParams){
	Bomb::load(pParams);
}

void BombPlayer2::update(){
	
	if(time_to_live > 0){
		time_to_live -= 1;
		m_currentFrame = int(((SDL_GetTicks() / 300) % 3));
	}
	else{
		m_currentFrame = 5;

		if(Timer::Instance().step() >= bornTime + time_to_live){
			Vector2D aux = m_position;
			
			Game::Instance().getStateMachine()->currentState()->removePlayer2Bomb(this);
			
			cout << "Bomba explodiu" << endl;
			
			int size = 9 * Game::Instance().getPlayer2()->getBonus();
			int x = -21* size / 2;
			int y = -25 * size / 2;
			
			for(int i = 0; i < size; i++){
				Explosion *exp1 = explosionCreator.create(this->getPosition().getX() + x, 
					this->getPosition().getY());
				x+=21;
			}
			

			for(int i = 0; i < size; i++){
				Explosion *exp1 = explosionCreator.create(this->getPosition().getX(), 
					this->getPosition().getY() + y);
				y+=21;
			}
		}
	}

}

void BombPlayer2::draw(){
	Bomb::draw();
}

void BombPlayer2::clean(){
	Bomb::clean();
}