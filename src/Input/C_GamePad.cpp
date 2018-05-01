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
  init();
}

C_GamePad::C_GamePad(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  m_id = p_id;
  m_model = t_gamepad_model::XBOXONE;
  m_dead_zone = 30.f;

  if (!sf::Joystick::isConnected(m_id)) {
    BOOST_LOG_TRIVIAL(warning) << "Caution the gamepad is not connect";
  }
  init();
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

  thor::JoystickAxis *LStick_left = new thor::JoystickAxis(0, sf::Joystick::X, (-m_dead_zone), false);
  thor::JoystickAxis *LStick_right = new thor::JoystickAxis(0, sf::Joystick::X, m_dead_zone, true);
  thor::JoystickAxis *LStick_up = new thor::JoystickAxis(0, sf::Joystick::Y, -m_dead_zone, false);
  thor::JoystickAxis *LStick_down = new thor::JoystickAxis(0, sf::Joystick::Y, m_dead_zone, true);

  m_LStick.m_treshold = m_dead_zone;
  m_LStick.m_axis_x = sf::Joystick::X;
  m_LStick.m_axis_y = sf::Joystick::Y;

  m_LStick.m_left = LStick_left;
  m_LStick.m_right = LStick_right;
  m_LStick.m_up = LStick_up;
  m_LStick.m_down = LStick_down;

  //---

  thor::JoystickAxis *RStick_left = new thor::JoystickAxis(0, sf::Joystick::Axis::U, -m_dead_zone, false);
  thor::JoystickAxis *RStick_right = new thor::JoystickAxis(0, sf::Joystick::Axis::U, m_dead_zone, true);
  thor::JoystickAxis *RStick_up = new thor::JoystickAxis(0, sf::Joystick::Axis::R, -m_dead_zone, false);
  thor::JoystickAxis *RStick_down = new thor::JoystickAxis(0, sf::Joystick::Axis::R, m_dead_zone, true);

  m_RStick.m_treshold = m_dead_zone;
  m_RStick.m_axis_x = sf::Joystick::U;
  m_RStick.m_axis_y = sf::Joystick::R;

  m_RStick.m_left = RStick_left;
  m_RStick.m_right = RStick_right;
  m_RStick.m_up = RStick_up;
  m_RStick.m_down = RStick_down;

  return true;
}

bool C_GamePad::init(pt::ptree &p_ptree) {
  return false;
}

void C_GamePad::on_disconnect() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  m_is_connected = false;
}

void C_GamePad::on_connect() {
  BOOST_LOG_TRIVIAL(info) << __PRETTY_FUNCTION__;
  m_is_connected = true;
}

const std::string &C_GamePad::get_owner_id() const {
  return owner_id;
}

const std::string &C_GamePad::get_name() const {
  return m_name;
}

unsigned int C_GamePad::get_id() const {
  return m_id;
}

bool C_GamePad::get_is_connected() const {
  return m_is_connected;
}

t_gamepad_model C_GamePad::get_model() const {
  return m_model;
}

float C_GamePad::get_dead_zone() const {
  return m_dead_zone;
}

const thor::ActionMap<std::string> &C_GamePad::get_action_map() const {
  return m_action_map;
}

unsigned int C_GamePad::get_A() const {
  return m_A;
}

unsigned int C_GamePad::get_B() const {
  return m_B;
}

unsigned int C_GamePad::get_X() const {
  return m_X;
}

unsigned int C_GamePad::get_Y() const {
  return m_Y;
}

unsigned int C_GamePad::get_start() const {
  return m_start;
}

unsigned int C_GamePad::get_select() const {
  return m_select;
}

unsigned int C_GamePad::get_LB() const {
  return m_LB;
}

unsigned int C_GamePad::get_RB() const {
  return m_RB;
}

C_GamePad::~C_GamePad() {
BOOST_LOG_TRIVIAL(warning) << __PRETTY_FUNCTION__;
}
