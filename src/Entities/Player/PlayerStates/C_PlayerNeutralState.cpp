//
// Created by David on 29/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_PlayerNeutralState.hh"

#include "C_PlayerMoveState.hh"
#include "C_PlayerJumpState.hh"

C_PlayerNeutralState::C_PlayerNeutralState() {
  m_state_id = "PlayerNeutralState";
  init_action();
}

void C_PlayerNeutralState::init_action() {
  thor::Action on_move = (thor::Action(sf::Keyboard::Left, thor::Action::Hold)
                          || thor::Action(sf::Keyboard::Right, thor::Action::Hold)
                          || thor::Action(sf::Keyboard::Up, thor::Action::Hold)
                          || thor::Action(sf::Keyboard::Down, thor::Action::Hold));
  m_action_map["OnMove"] = on_move;

  thor::Action on_jump(sf::Keyboard::Space, thor::Action::Hold);
  m_action_map["OnJump"] = on_jump;
}

C_PlayerStateBase *C_PlayerNeutralState::handle_input(C_Player &p_player) {

  if (m_action_map.isActive("OnMove")) {
    return (C_PlayerStateBase *)
        new C_PlayerMoveState();
  }
  if (m_action_map.isActive("OnJump")) {
    return (C_PlayerStateBase *) new C_PlayerJumpState();
  }

  return nullptr;
}

void C_PlayerNeutralState::handleInput() {

}

void C_PlayerNeutralState::update() {

}

void C_PlayerNeutralState::update(sf::Time p_eleapsed_time) {

}


C_BaseState *C_PlayerNeutralState::update_state(sf::Time p_eleapsed_time, C_Entity &p_entity) {
  return nullptr;
}

void C_PlayerNeutralState::draw_state(sf::RenderTarget &p_target, sf::RenderStates p_states, C_Entity &p_entity) {

}

void C_PlayerNeutralState::draw(sf::RenderTarget &target, sf::RenderStates states) {

}

void C_PlayerNeutralState::on_start() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << "Player in NeutralState";
}

C_BaseState *C_PlayerNeutralState::on_exit() {
  return nullptr;
}
