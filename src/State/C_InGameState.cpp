//
// Created by dyoubi on 26/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_InGameState.h"

void C_InGameState::handleInput() {
    if (m_action_map.isActive("jump")) {
        BOOST_LOG_TRIVIAL(info) << "game jump";
    }

    if(m_action_map.isActive("exit")){
        BOOST_LOG_TRIVIAL(info) << "game exit";
    }
    m_action_map.clearEvents();
}

void C_InGameState::update() {
}

void C_InGameState::render() {

}

void C_InGameState::on_start() {
    BOOST_LOG_TRIVIAL(trace) << __PRETTY_FUNCTION__;
}

void C_InGameState::on_exit() {
    BOOST_LOG_TRIVIAL(trace) << __PRETTY_FUNCTION__;
}

C_InGameState::C_InGameState() {
    m_state_id = "InGameState";
    thor::Action exit = thor::Action(sf::Keyboard::LControl, thor::Action::Hold)
                        && thor::Action(sf::Keyboard::Q, thor::Action::Hold);

    thor::Action space(sf::Keyboard::Space, thor::Action::PressOnce);

    m_action_map["jump"] = space;
    m_action_map["exit"] = exit;
}
