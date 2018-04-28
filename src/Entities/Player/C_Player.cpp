//
// Created by David on 29/04/2018.
//

#include "C_Player.hh"

void C_Player::draw(sf::RenderTarget &p_target, sf::RenderStates p_states) const {
  C_StateEntity::draw(p_target, p_states);
}

void C_Player::drawCurrent(sf::RenderTarget &p_target, sf::RenderStates p_states) const {
  C_StateEntity::drawCurrent(p_target, p_states);
}

C_BaseState *C_Player::handle_state_input(C_Entity &p_entitie) {
  return nullptr;
}

void C_Player::update(sf::Time dt) {
  C_SceneNode::update(dt);
}
