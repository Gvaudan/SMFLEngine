//
// Created by dyoubi on 26/04/2018.
//

#include "C_TestStateMachine.hh"

void C_TestStateMachine::set_entitie(C_TestEntitie *p_entity) {
    m_entity = p_entity;
}

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

void C_TestStateMachine::render() {
    C_BaseStateMachine::render();
}

void C_TestStateMachine::handleInput() {
    C_BaseStateMachine::handleInput();
}

C_TestEntitieState *C_TestStateMachine::get_current_state() {
    return (C_TestEntitieState *) C_BaseStateMachine::get_current_state();
}

void C_TestStateMachine::update_state(sf::Event &p_event) {
    C_BaseStateMachine::update_state(p_event);
}
