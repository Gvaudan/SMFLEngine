//
// Created by dyoubi on 26/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_InGameState.h"

void C_InGameState::handleInput() {
  if (m_action_map.isActive("jump")) {
    BOOST_LOG_TRIVIAL(info) << "game jump";
  }

  if (m_action_map.isActive("exit")) {
    BOOST_LOG_TRIVIAL(info) << "game exit";
  }
  m_action_map.clearEvents();
}

void C_InGameState::update() {
}


void C_InGameState::update(sf::Time p_eleapsed_time) {

}


void C_InGameState::draw(sf::RenderTarget &target, sf::RenderStates states) {

}

void C_InGameState::on_start() {
  BOOST_LOG_TRIVIAL(trace) << __PRETTY_FUNCTION__;
}

C_BaseState * C_InGameState::on_exit() {
  BOOST_LOG_TRIVIAL(trace) << __PRETTY_FUNCTION__;
}

C_InGameState::C_InGameState() {
  m_state_id = "InGameState";
  thor::Action exit = thor::Action(sf::Keyboard::LControl, thor::Action::Hold)
                      && thor::Action(sf::Keyboard::Q, thor::Action::Hold);

  thor::Action space(sf::Keyboard::Space, thor::Action::PressOnce);

  thor::Action toggleFPS(sf::Keyboard::F1, thor::Action::Hold);

  m_action_map["jump"] = space;
  m_action_map["exit"] = exit;
  m_action_map["toggleFPS"] = toggleFPS;
}

C_BaseState *C_InGameState::update_state(sf::Time p_eleapsed_time, C_Entity &p_entity) {
  return nullptr;
}

void C_InGameState::draw_state(sf::RenderTarget &p_target, sf::RenderStates p_states, C_Entity &p_entity) {

}

void C_InGameState::build_animiations() {

}
