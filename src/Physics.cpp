#include "Physics.h"

bool Physics::checkCollision(SDLGameObject* p1, SDLGameObject* p2){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX();
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY();
	bottomA = p1->getPosition().getY() + p1->getHeight();

	leftB = p2->getPosition().getX();
	rightB = p2->getPosition().getX() + p2->getWidth();
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight();

	if(bottomA <= topB) return false;
	if(topA >= bottomB) return false;
	if(rightA <= leftB) return false;
	if(leftA >= rightB) return false;

	return true;
}

bool Physics::checkWallCollision(SDLGameObject* p1, SDLGameObject* p2){
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	leftA = p1->getPosition().getX() + 2;
	rightA = p1->getPosition().getX() + p1->getWidth();
	topA = p1->getPosition().getY() + 10;
	bottomA = p1->getPosition().getY() + p1->getHeight() - 5;

	leftB = p2->getPosition().getX() + 5;
	rightB = p2->getPosition().getX() + p2->getWidth() + 2;
	topB = p2->getPosition().getY();
	bottomB = p2->getPosition().getY() + p2->getHeight() - 10;

	if(bottomA < topB) return false;
	if(topA >= bottomB) return false;
	if(rightA <= leftB) return false;
	if(leftA >= rightB) return false;

	return true;
}

Vector2D Physics::getNormal(SDLGameObject* p1, SDLGameObject* p2){
	
	Vector2D res = p1->getPosition() - p2->getPosition();
	
	return res.norm();
}