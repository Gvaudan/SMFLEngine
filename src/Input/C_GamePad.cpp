//
// Created by David on 29/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_GamePad.hh"

using namespace ControllerBind;

C_GamePad::C_GamePad() {
  m_id = 0;
  m_model = t_gamepad_model::XBOXONE;
  m_dead_zone = 30.f;

  if (!sf::Joystick::isConnected(m_id)) {
    BOOST_LOG_TRIVIAL(warning) << "Caution the gamepad is not connect";
  }

}

C_GamePad::C_GamePad(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  m_id = p_id;
  m_model = t_gamepad_model::XBOXONE;
  m_dead_zone = 30.f;

  if (!sf::Joystick::isConnected(m_id)) {
    BOOST_LOG_TRIVIAL(warning) << "Caution the gamepad is not connect";
  }
}

const t_gamepad_stick &ControllerBind::C_GamePad::get_LStick() const {
  return m_LStick;
}

const t_gamepad_stick &ControllerBind::C_GamePad::get_RStick() const {
  return m_RStick;
}

const t_gamepad_stick &ControllerBind::C_GamePad::get_DPad() const {
  return m_DPad;
}

void C_GamePad::bind_inputs(pt::ptree &p_ptree) {

}

void C_GamePad::update_inputs() {
  if (!m_is_connected && sf::Joystick::isConnected(m_id)) {
    BOOST_LOG_TRIVIAL(info) << "Gamepad connected";
    m_is_connected = true;
  }
  if (m_is_connected && !sf::Joystick::isConnected(m_id)) {
    BOOST_LOG_TRIVIAL(warning) << "Gamepad disconnected";
    m_is_connected = false;
  }
}

bool C_GamePad::init() {

  thor::JoystickAxis LStick_left(0, sf::Joystick::X, (-m_dead_zone), false);
  thor::JoystickAxis LStick_right(0, sf::Joystick::X, m_dead_zone, true);
  thor::JoystickAxis LStick_up(0, sf::Joystick::Y, -m_dead_zone, false);
  thor::JoystickAxis LStick_down(0, sf::Joystick::Y, m_dead_zone, true);

  m_LStick.m_treshold = m_dead_zone;
  m_LStick.m_axis_x = sf::Joystick::X;
  m_LStick.m_axis_y = sf::Joystick::Y;

  m_LStick.m_left = &LStick_left;
  m_LStick.m_right = &LStick_right;
  m_LStick.m_up = &LStick_up;
  m_LStick.m_down = &LStick_down;

  //---

  thor::JoystickAxis RStick_left(0, sf::Joystick::Axis::U, -m_dead_zone, false);
  thor::JoystickAxis RStick_right(0, sf::Joystick::Axis::U, m_dead_zone, true);
  thor::JoystickAxis RStick_up(0, sf::Joystick::Axis::R, -m_dead_zone, false);
  thor::JoystickAxis RStick_down(0, sf::Joystick::Axis::R, m_dead_zone, true);

  m_LStick.m_treshold = m_dead_zone;
  m_LStick.m_axis_x = sf::Joystick::X;
  m_LStick.m_axis_y = sf::Joystick::Y;

  m_LStick.m_left = &RStick_left;
  m_LStick.m_right = &RStick_right;
  m_LStick.m_up = &RStick_up;
  m_LStick.m_down = &RStick_down;

  return true;
}

bool C_GamePad::init(pt::ptree &p_ptree) {
  return false;
}

void C_GamePad::on_disconnect() {
  m_is_connected = false;
}

void C_GamePad::on_connect() {
  m_is_connected = true;
}
