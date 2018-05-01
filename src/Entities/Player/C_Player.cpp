//
// Created by David on 29/04/2018.
//

#include "C_Player.hh"
#include "PlayerStates/C_PlayerStateBase.hh"
#include "PlayerStates/C_PlayerNeutralState.hh"

C_Player::C_Player() {
  m_rectangle.setFillColor(sf::Color(250, 50, 50));
  m_rectangle.setSize(sf::Vector2f(100, 50));
  change_state(new C_PlayerNeutralState());
  m_id = "player";
}

void C_Player::draw(sf::RenderTarget &p_target, sf::RenderStates p_states) const {
  //C_StateEntity::draw(p_target, p_states);
  p_target.draw(m_rectangle);
}

void C_Player::drawCurrent(sf::RenderTarget &p_target, sf::RenderStates p_states) const {
  C_StateEntity::drawCurrent(p_target, p_states);
}

void C_Player::handle_input() {
  if (!m_state_list.empty()) {
    auto current_state = (C_PlayerStateBase *) m_state_list.back();
    auto new_state = current_state->handle_input((*this));
    if (new_state != nullptr) {
      change_state(new_state);
    }
    m_state_list.back()->get_action_map().clearEvents();
  }
}

void C_Player::update(sf::Time dt) {
  C_SceneNode::update(dt);
  if (!m_state_list.empty()) {
    auto current_state = (C_PlayerStateBase *) m_state_list.back();
    auto new_state = current_state->update_state(dt, (*this));
    if (new_state != nullptr) {
      change_state(new_state);
    }
  }
}

C_BaseState *C_Player::handle_state_input(C_Entity &p_entitie) {
  return nullptr;
}