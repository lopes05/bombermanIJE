#include "BombUpgrader.h"
#include "TextureManager.h"
#include "Game.h"
#include "iostream"

using namespace std;
BombUpgrader::BombUpgrader(){
	TextureManager::Instance().load("assets/upgrader.png", "bombupgrader", Game::Instance().getRenderer());
	Game::Instance().getStateMachine()->currentState()->addUpgrader(this);
	setVisible(true);
}

void BombUpgrader::load(const LoaderParams* pParams){
	SDLGameObject::load(pParams);
}

void BombUpgrader::update(){
	m_textureID = "exp";
}

void BombUpgrader::clean(){
	SDLGameObject::clean();
}

void BombUpgrader::draw(){
	if(visible)
		SDLGameObject::draw();
}