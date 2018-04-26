//
// Created by dyoubi on 26/04/2018.
//

#include "C_TestEntitieState.hh"
#include <boost/log/trivial.hpp>

void C_TestEntitieState::handleInput() {
    if (m_action_map.isActive("MoveLeft")) {
        BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << ": MoveLeft";
        m_entitie->on_move_left();
    }

    if (m_action_map.isActive("MoveRight")) {
        BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << ": MoveRight";
        m_entitie->on_move_right();
    }
    m_action_map.clearEvents();
}

void C_TestEntitieState::update() {

}

void C_TestEntitieState::render() {

}

void C_TestEntitieState::on_start() {
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
}

void C_TestEntitieState::on_exit() {
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
}

C_TestEntitieState::C_TestEntitieState() {
    m_state_id = "TestEntitieState";
    init_actions();
}

C_TestEntitieState::C_TestEntitieState(C_TestEntitie *p_entitie) :
        m_entitie(p_entitie) {
    m_state_id = "TestEntitieState";
    init_actions();
}

void C_TestEntitieState::init_actions() {
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
    C_BaseState::init_actions();

    thor::Action move_left(sf::Keyboard::Q, thor::Action::Hold);
    m_action_map["MoveLeft"] = move_left;

    thor::Action move_right(sf::Keyboard::D, thor::Action::Hold);
    m_action_map["MoveRight"] = move_right;

}
