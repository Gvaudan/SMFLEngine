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

void C_PlayerMoveState::init_action() {

  thor::JoystickAxis LStick_left(0, sf::Joystick::X, (-25.f), false);
  thor::JoystickAxis LStick_right(0, sf::Joystick::X, 25.f, true);
  thor::JoystickAxis LStick_up(0, sf::Joystick::Y, -25.f, false);
  thor::JoystickAxis LStick_down(0, sf::Joystick::Y, 25.f, true);


  thor::Action left_stick_move = thor::Action(LStick_left)
                                 || thor::Action(LStick_right)
                                 || thor::Action(LStick_up)
                                 || thor::Action(LStick_down);

  thor::Action on_LStick_left(LStick_left);
  thor::Action on_LStick_right(LStick_right);
  thor::Action on_LStick_up(LStick_up);
  thor::Action on_LStick_down(LStick_down);

  thor::Action left_sitck_move = on_LStick_left
                                 || on_LStick_right
                                 || on_LStick_up
                                 || on_LStick_down;

  thor::Action left_stick_stop = !on_LStick_left
                                 && !on_LStick_right
                                 && !on_LStick_up
                                 && !on_LStick_down;

  m_action_map["StopMove"] = left_stick_stop;

  thor::Action move_left(sf::Keyboard::Left, thor::Action::Hold);
  m_action_map["MoveLeft"] = on_LStick_left;

  thor::Action move_right(sf::Keyboard::Right, thor::Action::Hold);
  m_action_map["MoveRight"] = on_LStick_right;


  thor::Action move_jump(thor::JoystickButton(0, 0), thor::Action::ReleaseOnce);
  m_action_map["Jump"] = move_jump;

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