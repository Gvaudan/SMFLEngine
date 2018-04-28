//
// Created by David on 28/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_TestMoveState.hh"
#include "C_TestEntitie.hh"

C_TestMoveState::C_TestMoveState() {
  init_actions();
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  m_state_id = "TestMoveState";
}

C_TestMoveState::C_TestMoveState(C_TestEntitie *p_entitie) {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  init_actions();
  m_state_id = "TestMoveState";
}

void C_TestMoveState::handleInput() {
  C_TestEntitieState::handleInput();
}

C_TestEntitieState *C_TestMoveState::handle_input() {
  return nullptr;
}

C_TestEntitieState *C_TestMoveState::handle_input(C_TestEntitie &p_entitie) {

  if (m_action_map.isActive("StopMove")) {
    return new C_TestEntitieState();
  }

  if (m_action_map.isActive("MoveLeft")) {
    p_entitie.on_move_left();
  }

  if (m_action_map.isActive("MoveRight")) {
    p_entitie.on_move_right();
  }
  return nullptr;
}

void C_TestMoveState::update() {
  C_TestEntitieState::update();
}

void C_TestMoveState::update(C_TestEntitie &p_entitie, sf::Time p_eleapsed_time) {
  C_TestEntitieState::update(p_entitie, p_eleapsed_time);
}

void C_TestMoveState::draw(sf::RenderTarget &target, sf::RenderStates states) {
  C_TestEntitieState::draw(target, states);
}

void C_TestMoveState::on_start() {
  //C_TestEntitieState::on_start();
  BOOST_LOG_TRIVIAL(info) << "TestSprint is moving";
}

C_BaseState *C_TestMoveState::on_exit() {
  C_TestEntitieState::on_exit();
  return new C_TestEntitieState();
}

void C_TestMoveState::init_actions() {
  thor::Action stop_move = thor::Action(sf::Keyboard::Left, thor::Action::ReleaseOnce)
                           || thor::Action(sf::Keyboard::Right, thor::Action::ReleaseOnce);
  m_action_map["StopMove"] = stop_move;

  thor::Action move_left(sf::Keyboard::Left, thor::Action::Hold);
  m_action_map["MoveLeft"] = move_left;

  thor::Action move_right(sf::Keyboard::Right, thor::Action::Hold);
  m_action_map["MoveRight"] = move_right;
}