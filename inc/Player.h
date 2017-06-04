#ifndef PLAYER_H
#define PLAYER_H

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "BaseCreator.h"
#include "SkillManager.h"
#include "Timer.h"
#include <vector>
#include <string>
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
private:
	void handleInput();
	bool isFirstSkill = true;
	void move();
	void useSkill();
};

class PlayerCreator : public BaseCreator{
	GameObject* createGameObject() const{
		return new Player();
	}
};

#endif
