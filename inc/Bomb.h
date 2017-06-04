#ifndef BOMB_H
#define BOMB_H

#include "SDLGameObject.h"
#include "Explosion.h"

class Bomb : public SDLGameObject{

public:
	Bomb();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();

	Uint32 getTimeToLive() { return time_to_live;}

private:
	Uint32 time_to_live;
	bool still_exists;
	Uint32 bornTime;
	ExplosionCreator explosionCreator;

};

class BombCreator{
public:
	Bomb* create(){
		return new Bomb();
	}
};

#endif