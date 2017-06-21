//Run Away (Term 2 Coursework)
//
//Entity.cpp
//
//Created by Adam M Bader 19.03.2017

#include "Entity.h"

Entity::Entity(float &x, float &y, float w, float h, float _health, float _points) : inGameObjects(x, y, w, h)
{
}

Entity::~Entity() {

}

void Entity::draw() {

}

void Entity::Health(float h) {

}
void Entity::Points(float p) {

}

void Entity::collisionResponse(inGameObjects *other) {
}

void Entity::Damage(float d) {
}

