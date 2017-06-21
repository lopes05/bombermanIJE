#ifndef BOMBPLAYER2_H
#define BOMBPLAYER2_H

#include "SDLGameObject.h"
#include "Explosion.h"
#include "Bomb.h"

class BombPlayer2 : public Bomb{

public:
	BombPlayer2();
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

class BombPlayer2Creator{
public:
	BombPlayer2* create(){
		return new BombPlayer2();
	}
};

#endif