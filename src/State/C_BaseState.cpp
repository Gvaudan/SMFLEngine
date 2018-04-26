//
// Created by David on 22/04/2018.
//

#include <utility>
#include "C_BaseState.hh"

const std::string &C_BaseState::get_state_id() const {
  return m_state_id;
}

const thor::ActionMap<std::string> &C_BaseState::get_action_map() const {
    return m_action_map;
}

void C_BaseState::push_action(std::string p_name, thor::Action p_action) {
    m_action_map[p_name] = std::move(p_action);
}
