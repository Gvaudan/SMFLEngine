//
// Created by David on 29/04/2018.
//

#include <utility>
#include "C_JoyAxisValue.hh"

C_JoyAxisValue::C_JoyAxisValue(sf::Joystick::Axis x_axis, sf::Joystick::Axis y_axis, std::string id)
    : C_DrawableString(), m_axis_x(x_axis), m_axis_y(y_axis), m_joystick_id(std::move(id)) {
}

void C_JoyAxisValue::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  C_DrawableString::draw(target, states);
  target.draw(m_text);
}

void C_JoyAxisValue::update(sf::Time dt) {
  C_DrawableString::update(dt);

  std::string line = m_joystick_id + " : "
                     + std::to_string(sf::Joystick::getAxisPosition(0, m_axis_x)) + " X | "
                     + std::to_string(sf::Joystick::getAxisPosition(0, m_axis_y)) + " Y\n";
  m_text.setPosition(getPosition());
  m_text.setString(line);
}

const std::string &C_JoyAxisValue::get_joystick_id() const {
  return m_joystick_id;
}
