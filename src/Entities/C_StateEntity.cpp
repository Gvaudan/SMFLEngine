//
// Created by David on 29/04/2018.
//

#include "C_StateEntity.hh"


C_StateEntity::C_StateEntity() = default;

C_StateEntity::C_StateEntity(C_BaseState *p_state) {
  push_state(p_state);
}

void C_StateEntity::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (!m_state_list.empty()) {
    m_state_list.back()->draw(target, states);
  }
}

void C_StateEntity::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {
}

void C_StateEntity::set_current_state(C_BaseState *p_state) {
  change_state(p_state);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////