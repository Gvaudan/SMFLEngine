//
// Created by David on 29/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_PlayerJumpState.hh"
#include "C_PlayerNeutralState.hh"


C_PlayerJumpState::C_PlayerJumpState() { m_state_id = "PlayerJumpState"; }


C_PlayerStateBase *C_PlayerJumpState::handle_input(C_Player &p_player) {
  return new C_PlayerNeutralState();
}

void C_PlayerJumpState::init_action() {

}

void C_PlayerJumpState::handleInput() {

}

void C_PlayerJumpState::update() {

}

void C_PlayerJumpState::update(sf::Time p_eleapsed_time) {

}

C_BaseState *C_PlayerJumpState::update_state(sf::Time p_eleapsed_time, C_Entity &p_entity) {
  return nullptr;
}

void C_PlayerJumpState::draw_state(sf::RenderTarget &p_target, sf::RenderStates p_states, C_Entity &p_entity) {

}


void C_PlayerJumpState::draw(sf::RenderTarget &target, sf::RenderStates states) {

}

void C_PlayerJumpState::on_start() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << "Player is Jumping";

}

C_BaseState *C_PlayerJumpState::on_exit() {
  return nullptr;
}

void C_PlayerJumpState::build_animiations() {

}
