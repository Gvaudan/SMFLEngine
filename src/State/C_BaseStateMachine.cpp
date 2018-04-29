//
// Created by David on 22/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_BaseStateMachine.hh"

void C_BaseStateMachine::push_state(C_BaseState *p_state) {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  m_state_list.push_back(p_state);
  m_state_list.back()->on_start();
}

void C_BaseStateMachine::change_state(C_BaseState *p_state) {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  if (!m_state_list.empty()) {
    if (m_state_list.back()->get_state_id() == p_state->get_state_id()) {
      if (m_state_list.back()->is_reloadable()) { m_state_list.back()->on_start(); }
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
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : START";

  if (!m_state_list.empty()) {
    m_state_list.back()->on_exit();
    delete m_state_list.back();
    m_state_list.pop_back();

    if (!m_state_list.empty()) { m_state_list.back()->on_start(); }
  }
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : END";
}

void C_BaseStateMachine::update() {
  if (!m_state_list.empty()) {
    m_state_list.back()->update();
  }
}

void C_BaseStateMachine::update(sf::Time p_eleapsed_time) {
  if (!m_state_list.empty()) {
    m_state_list.back()->update(p_eleapsed_time);
  }
}

void C_BaseStateMachine::draw(sf::RenderTarget &target, sf::RenderStates &states) {
  if (!m_state_list.empty()) {
    m_state_list.back()->draw(target, states);
  } else {
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : NO STATE";
  }
}

void C_BaseStateMachine::handleInput() {
  if (!m_state_list.empty()) {
    m_state_list.back()->handleInput();
  } else {
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : NO STATE";
  }
}

C_BaseState *C_BaseStateMachine::get_current_state() {
  if (!m_state_list.empty()) {
    return m_state_list.back();
  }
  return nullptr;
}

void C_BaseStateMachine::update_state_event(sf::Event &p_event) {
  if (!m_state_list.empty()) {
    m_state_list.back()->push_event(p_event);
  } else {
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : NO STATE";
  }
}

void C_BaseStateMachine::clear_state_event() {
  if (!m_state_list.empty()) {
    m_state_list.back()->get_action_map().clearEvents();
  } else {
    BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__ << " : NO STATE";
  }
}
