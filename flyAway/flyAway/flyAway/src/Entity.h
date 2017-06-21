//Run Away (Term 2 Coursework)
//
//Entity.h
//
//Created by Adam M Bader 19.03.2017

#ifndef Entity_h
#define Entity_h

#include "inGameObjects.h"

class Entity : public inGameObjects
{
protected:

	float w, h;

public:
	Entity(float &x, float &y, float w, float h, float _health, float _points);
	~Entity();

	virtual void draw() = 0;


	void Damage(float d);

	// increase health
	void Health(float h);
	void Points(float p);
	virtual void collisionResponse(inGameObjects *other) = 0;

};

#endif /* Entity_hpp */