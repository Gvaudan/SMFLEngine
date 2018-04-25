//
// Created by David on 22/04/2018.
//

#include "C_TestEntitie.hh"
#include <SFML/Window.hpp>

C_TestEntitie *C_TestEntityCreator::C_CreateEntity() const {
  C_TestEntitie *created_entitie = new C_TestEntitie();

  return created_entitie;
}

C_TestEntitie::C_TestEntitie() : m_rectangle(sf::Vector2f(120, 50)) {
  m_rectangle.setFillColor(sf::Color(100, 250, 50));
}

void C_TestEntitie::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(m_rectangle);
}