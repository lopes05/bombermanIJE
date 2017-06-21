#ifndef PLAYER_H
#define PLAYER_H

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "BaseCreator.h"
#include "Timer.h"
#include <vector>
#include <string>
#include "Bomb.h"
#include <SDL2/SDL.h>

class Player : public SDLGameObject{
public:
	Player();

	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();
	typedef uint8_t*(*Callback) ();
	uint8_t* pixelColors;


	int getBonus(){
		return m_bonus;
	}

	void setBonus(int x){
		m_bonus = x;
	}

	void increaseExplosionSize();
	
private:
	void handleInput();
	bool isFirstSkill = true;
	void move();
	void useSkill();
	int m_bonus;
	BombCreator bCreator;
};

class PlayerCreator : public BaseCreator{
	GameObject* createGameObject() const{
		return new Player();
	}
};

#endif
