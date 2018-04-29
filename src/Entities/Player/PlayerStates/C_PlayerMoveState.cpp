//
// Created by David on 29/04/2018.
//

#include "C_PlayerMoveState.hh"
#include "C_PlayerNeutralState.hh"
#include "../C_Player.hh"
#include "C_PlayerJumpState.hh"

#include <boost/log/trivial.hpp>

C_PlayerMoveState::C_PlayerMoveState() {
  m_state_id = "PlayerMoveState";
  init_action();
}

C_PlayerStateBase *C_PlayerMoveState::handle_input(C_Player &p_player) {

  if (m_action_map.isActive("StopMove")) {
    return new C_PlayerNeutralState();
  }

  if (m_action_map.isActive("MoveLeft")) {
  }

  if (m_action_map.isActive("MoveRight")) {
  }

  if (m_action_map.isActive("Jump")) {
    return new C_PlayerJumpState();
  }

  return nullptr;
}

void C_PlayerMoveState::init_action() {

  thor::JoystickAxis left_stick_x(0, sf::Joystick::X, 15.0f, false);
  thor::JoystickAxis left_stick_y(0, sf::Joystick::Y, 15.0f, false);

  thor::Action on_joystick_move = (thor::Action(left_stick_x) || thor::Action(left_stick_y));

  thor::Action stop_move = thor::Action(sf::Keyboard::Left, thor::Action::ReleaseOnce)
                           || thor::Action(sf::Keyboard::Right, thor::Action::ReleaseOnce)
                           || thor::Action(sf::Keyboard::Up, thor::Action::ReleaseOnce)
                           || thor::Action(sf::Keyboard::Down, thor::Action::ReleaseOnce)
                           || thor::Action(left_stick_x)
                           || thor::Action(left_stick_y);

  m_action_map["StopMove"] = stop_move;

  thor::Action move_left(sf::Keyboard::Left, thor::Action::Hold);
  m_action_map["MoveLeft"] = move_left;

  thor::Action move_right(sf::Keyboard::Right, thor::Action::Hold);
  m_action_map["MoveRight"] = move_right;


  thor::Action move_jump(sf::Keyboard::Space, thor::Action::PressOnce);
  m_action_map["Jump"] = move_jump;

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