#ifndef PHYSICS_H
#define PHYSICS_H

#include "SDLGameObject.h"
#include "Vector2D.h"

class Physics{
	public:
		static Physics& Instance(){
			static Physics instance;

			return instance;
		}

		Physics(Physics const&) = delete;
		void operator=(Physics const&) = delete;

		bool checkCollision(SDLGameObject* p1, SDLGameObject* p2);
		Vector2D getNormal(SDLGameObject* p1, SDLGameObject* p2);

	private:
		Physics(){}


};

#endif