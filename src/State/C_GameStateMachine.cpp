//
// Created by dyoubi on 26/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_GameStateMachine.h"

void C_GameStateMachine::push_state(C_BaseState *p_state) {
    C_BaseStateMachine::push_state(p_state);
}

void C_GameStateMachine::change_state(C_BaseState *p_state) {
    C_BaseStateMachine::change_state(p_state);
}

void C_GameStateMachine::pop_state() {
    C_BaseStateMachine::pop_state();
}

void C_GameStateMachine::update() {
    C_BaseStateMachine::update();
}

void C_GameStateMachine::render() {
    C_BaseStateMachine::render();
}

void C_GameStateMachine::handleInput() {
    C_BaseStateMachine::handleInput();
}

void C_GameStateMachine::update_state(sf::Event &p_event) {
    C_BaseStateMachine::update_state(p_event);
}
