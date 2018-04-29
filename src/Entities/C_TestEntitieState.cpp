//
// Created by dyoubi on 26/04/2018.
//

#include "C_TestEntitieState.hh"
#include "C_TestEntitie.hh"
#include <boost/log/trivial.hpp>

C_TestEntitieState::C_TestEntitieState() {
  m_state_id = "TestEntitieState";
  init_actions();
}

C_TestEntitieState::C_TestEntitieState(C_TestEntitie *p_entitie) {
  m_state_id = "TestEntitieState";
  init_actions();
}

void C_TestEntitieState::handleInput() {
  if (m_action_map.isActive("MoveLeft")) {
    m_entitie->on_move_left();
  }

  if (m_action_map.isActive("MoveRight")) {
    m_entitie->on_move_right();
  }
  m_action_map.clearEvents();
}

C_TestEntitieState *C_TestEntitieState::handle_input(C_TestEntitie &p_entitie) {
  if (m_action_map.isActive("OnMove")) {
    return new C_TestMoveState();
  }
  m_action_map.clearEvents();
  return nullptr;
}

void C_TestEntitieState::update() {

}

void C_TestEntitieState::update(C_TestEntitie &p_entitie, sf::Time p_eleapsed_time) {
}

void C_TestEntitieState::draw(sf::RenderTarget &target, sf::RenderStates states) {

}

void C_TestEntitieState::on_start() {
  BOOST_LOG_TRIVIAL(info) << "TestSprint is hiddle";
}

C_BaseState *C_TestEntitieState::on_exit() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
}

void C_TestEntitieState::init_actions() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  C_BaseState::init_actions();

  thor::Action on_move = (thor::Action(sf::Keyboard::Left, thor::Action::Hold)
                          || thor::Action(sf::Keyboard::Right, thor::Action::Hold)
                          || thor::Action(sf::Keyboard::Up, thor::Action::Hold)
                          || thor::Action(sf::Keyboard::Down, thor::Action::Hold));

  m_action_map["OnMove"] = on_move;
}

void C_TestEntitieState::update(sf::Time p_eleapsed_time) {}

C_TestEntitieState *C_TestEntitieState::handle_input() {
  return nullptr;
}

C_BaseState *C_TestEntitieState::update_state(sf::Time p_eleapsed_time, C_Entity &p_entity) {
  return nullptr;
}

void C_TestEntitieState::draw_state(sf::RenderTarget &p_target, sf::RenderStates p_states, C_Entity &p_entity) {

}
