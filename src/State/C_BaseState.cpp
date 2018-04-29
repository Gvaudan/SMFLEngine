//
// Created by David on 22/04/2018.
//

#include "C_BaseState.hh"

const std::string &C_BaseState::get_state_id() const {
  return m_state_id;
}

thor::ActionMap<std::string> &C_BaseState::get_action_map() {
  return m_action_map;
}

void C_BaseState::push_action(std::string p_name, thor::Action p_action) {
  m_action_map[p_name] = std::move(p_action);
}

bool C_BaseState::is_cancelable() const {
  return m_is_cancelable;
}

bool C_BaseState::is_reloadable() const {
  return m_is_reloadable;
}

void C_BaseState::push_event(sf::Event &p_event) {
  m_action_map.pushEvent(p_event);
}

void C_BaseState::init_actions() {

}

void C_BaseState::clean_event() {
  m_action_map.clearEvents();
}
