//
// Created by David on 22/04/2018.
//

#include "C_Entity.hh"

void C_Entity::setVelocity(sf::Vector2f velocity) {
  mVelocity = velocity;
}

void C_Entity::setVelocity(float vx, float vy) {
  mVelocity.x = vx;
  mVelocity.y = vy;
}

sf::Vector2f C_Entity::getVelocity() const {
  return mVelocity;
}

void C_Entity::updateCurrent(sf::Time dt) {
  move(mVelocity * dt.asSeconds());
}