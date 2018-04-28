//
// Created by dyoubi on 26/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_TestStateMachine.hh"

void C_TestStateMachine::push_state(C_TestEntitieState *p_state) {
  C_BaseStateMachine::push_state(p_state);
}

void C_TestStateMachine::change_state(C_TestEntitieState *p_state) {
  C_BaseStateMachine::change_state(p_state);
}

void C_TestStateMachine::pop_state() {
  C_BaseStateMachine::pop_state();
}

void C_TestStateMachine::update() {
  C_BaseStateMachine::update();
}


void C_TestStateMachine::update(sf::Time dt) {
  C_BaseStateMachine::update(dt);
}

void C_TestStateMachine::update(C_TestEntitie &entitie, sf::Time dt) {

  //Do stuff with entitie;

  C_BaseStateMachine::update(dt);
}

void C_TestStateMachine::draw(sf::RenderTarget &target, sf::RenderStates &states) {

  C_BaseStateMachine::draw(target, states);
}


void C_TestStateMachine::draw(C_TestEntitie &entitie, sf::RenderTarget &target, sf::RenderStates &states) {

  //Do stuff with entitie...

  C_BaseStateMachine::draw(target, states);
}


void C_TestStateMachine::handleInput() {
  C_BaseStateMachine::handleInput();
}


C_TestEntitieState *C_TestStateMachine::handle_state_input(C_TestEntitie &entitie) {
  //Do stuff with entitie;

  if (!m_state_list.empty()) {
    auto state = (C_TestEntitieState*)m_state_list.back();
    return state->handle_input(entitie);
  }
  return nullptr;
}

C_TestEntitieState *C_TestStateMachine::get_current_state() {
  return (C_TestEntitieState *) C_BaseStateMachine::get_current_state();
}

void C_TestStateMachine::update_state_event(sf::Event &p_event) {
  C_BaseStateMachine::update_state_event(p_event);
}