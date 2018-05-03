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
  build_animiations();
}

void C_PlayerNeutralState::init_action() {

  //m_gamepad = C_InputHandler::get_instance()->get_gamepad(0);

  auto gmd = C_InputHandler::get_instance()->get_gamepad(0);

  thor::JoystickAxis LStick_left(gmd->get_id(), gmd->get_LStick().m_axis_x,
								 -gmd->get_dead_zone(), false);
  thor::JoystickAxis LStick_right(gmd->get_id(), gmd->get_LStick().m_axis_x,
								  gmd->get_dead_zone(), true);
  thor::JoystickAxis LStick_up(gmd->get_id(), gmd->get_LStick().m_axis_y,
							   -gmd->get_dead_zone(), false);
  thor::JoystickAxis LStick_down(gmd->get_id(), gmd->get_LStick().m_axis_y,
								 gmd->get_dead_zone(), true);

  thor::Action left_stick_move = thor::Action(LStick_left)
	  || thor::Action(LStick_right)
	  || thor::Action(LStick_up)
	  || thor::Action(LStick_down);

  m_action_map["OnMove"] = left_stick_move;

  thor::Action move_jump(thor::JoystickButton(0, 0), thor::Action::ReleaseOnce);
  m_action_map["OnJump"] = move_jump;

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

void C_PlayerNeutralState::init_actions() {
  C_BaseState::init_actions();
  thor::FrameAnimation animation;

}

void C_PlayerNeutralState::build_animiations() {

}
