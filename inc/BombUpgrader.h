#ifndef BOMBUPGRADER_H
#define BOMBUPGRADER_H

#include "SDLGameObject.h"
#include "BaseCreator.h"

class BombUpgrader : public SDLGameObject{

public:
	BombUpgrader();
	void load(const LoaderParams* pParams);
	void draw();
	void update();
	void clean();

	void setVisible(bool value){
		visible = value;
	}
private:
	bool visible;

};

class BombUpgraderCreator : public BaseCreator{
	GameObject* createGameObject() const{
		return new BombUpgrader();
	}
};
#endif