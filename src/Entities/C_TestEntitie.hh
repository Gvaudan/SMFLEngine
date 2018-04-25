//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH
#define INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH

#include <SFML/Graphics/RectangleShape.hpp>
#include "../Manager/C_EntityFactory.hh"

class C_TestEntitie : public C_Entity {
public:
  C_TestEntitie();
  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
  sf::RectangleShape m_rectangle;
};


class C_TestEntityCreator : public C_BaseEntityCreator {
public:
  C_TestEntitie *C_CreateEntity() const override;
};

#endif //INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH
