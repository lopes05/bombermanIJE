#ifndef ENEMY_H
#define ENEMY_H

#include "SDLGameObject.h"
#include "LoaderParams.h"
#include "BaseCreator.h"
#include "Bomb.h"
#include <string>
#include <SDL2/SDL.h>

class Enemy : public SDLGameObject{
public:
	Enemy();

	void load(const LoaderParams* pParams);

	void draw();
	void update();
	void clean();
	void useSkill();
	void move();

private:
	enum BossHealth{
		FULL = 1,
		MEDIUM = 2,
		LOW = 3,
		DEAD = 4
	};

	int m_totalHealth;
	int m_actualHealth;
	int m_state;
	BombCreator bCreator;
};

class EnemyCreator : public BaseCreator{
	GameObject* createGameObject() const{
		return new Enemy();
	}
};

#endif
