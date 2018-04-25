//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_ENTITY_HH
#define INC_2DGAMEFRAMEWORK_C_ENTITY_HH

#include "C_SceneNode.hh"

class C_Entity : public C_SceneNode {
public:
  void setVelocity(sf::Vector2f velocity);

  void setVelocity(float vx, float vy);

  sf::Vector2f getVelocity() const;

private:
  virtual void updateCurrent(sf::Time dt);

private:
  sf::Vector2f mVelocity;
};


#endif //INC_2DGAMEFRAMEWORK_C_ENTITY_HH
