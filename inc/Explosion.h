#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "SDLGameObject.h"

class Explosion : public SDLGameObject{
public:
	Explosion();
	~Explosion() {}
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();

	Uint32 getTTL(){
		return time_to_live;
	}
private:
	Uint32 time_to_live;
	Uint32 bornTime;
};

class ExplosionCreator{
public:
	Explosion *create(){
		return new Explosion();
	}
};

#endif