//
// Created by David on 22/04/2018.
//

#include "C_BaseStateMachine.hh"

void C_BaseStateMachine::push_state(C_BaseState *p_state) {
    printf("%s : START\n", __PRETTY_FUNCTION__);
    m_state_list.push_back(p_state);
    m_state_list.back()->on_start();
}

void C_BaseStateMachine::change_state(C_BaseState *p_state) {
    printf("%s : START\n", __PRETTY_FUNCTION__);

    if (!m_state_list.empty()) {
        if (m_state_list.back()->get_state_id() == p_state->get_state_id()) {
            return;
        }
        m_state_list.back()->on_exit();
        delete m_state_list.back();
        m_state_list.pop_back();
    }
    m_state_list.push_back(p_state);
    m_state_list.back()->on_start();
}

void C_BaseStateMachine::pop_state() {
    printf("%s : START\n", __PRETTY_FUNCTION__);

    if (!m_state_list.empty()) {
        m_state_list.back()->on_exit();
        delete m_state_list.back();
        m_state_list.pop_back();
    }
}

void C_BaseStateMachine::update() {
    if (!m_state_list.empty()) {
        m_state_list.back()->update();
    }

}

void C_BaseStateMachine::render() {
    if (!m_state_list.empty()) {
        m_state_list.back()->render();
    }


}

void C_BaseStateMachine::handleInput() {
    if (!m_state_list.empty()) {
        m_state_list.back()->handleInput();
    }
}