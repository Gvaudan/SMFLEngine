//
// Created by David on 29/04/2018.
//

#include "C_PlayerMoveState.hh"
#include "C_PlayerNeutralState.hh"
#include <boost/log/trivial.hpp>

C_PlayerMoveState::C_PlayerMoveState() {
  m_state_id = "PlayerMoveState";
  init_action();
}

C_PlayerStateBase *C_PlayerMoveState::handle_input(C_Player &p_player) {

  if (m_action_map.isActive("StopMove")) {
    return new C_PlayerNeutralState();
  }
  return nullptr;
}

void C_PlayerMoveState::init_action() {

  thor::Action stop_move = thor::Action(sf::Keyboard::Left, thor::Action::ReleaseOnce)
                           || thor::Action(sf::Keyboard::Right, thor::Action::ReleaseOnce)
                           || thor::Action(sf::Keyboard::Up, thor::Action::ReleaseOnce)
                           || thor::Action(sf::Keyboard::Down, thor::Action::ReleaseOnce);
  m_action_map["StopMove"] = stop_move;
}

void C_PlayerMoveState::handleInput() {

}

void C_PlayerMoveState::update() {

}

void C_PlayerMoveState::update(sf::Time p_eleapsed_time) {

}


C_BaseState *C_PlayerMoveState::update_state(sf::Time p_eleapsed_time, C_Entity &p_entity) {
  return nullptr;
}

void C_PlayerMoveState::draw_state(sf::RenderTarget &p_target, sf::RenderStates p_states, C_Entity &p_entity) {

}

void C_PlayerMoveState::draw(sf::RenderTarget &target, sf::RenderStates states) {

}

void C_PlayerMoveState::on_start() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << "Player in MoveState";
}

C_BaseState *C_PlayerMoveState::on_exit() {
  return nullptr;
}