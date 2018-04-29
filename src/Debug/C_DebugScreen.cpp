//
// Created by David on 29/04/2018.
//

#include "C_DebugScreen.hh"
#include "C_JoyAxisValue.hh"

C_DebugScreen::C_DebugScreen() {
  C_JoyAxisValue *left_stick = new C_JoyAxisValue(sf::Joystick::Axis::X, sf::Joystick::Axis::Y, "LeftStick");
  C_JoyAxisValue *right_stick = new C_JoyAxisValue(sf::Joystick::Axis::U, sf::Joystick::Axis::R, "RightStick");

  left_stick->setPosition(sf::Vector2f(10, 10));
  right_stick->setPosition(sf::Vector2f(10, 30));

  m_text_list.push_back(left_stick);
  m_text_list.push_back(right_stick);
};

void C_DebugScreen::updateCurrent(sf::Time dt) {
  if (!m_text_list.empty()) {
    for (auto it = m_text_list.begin(); it < m_text_list.end(); ++it) {
      auto item = it.base();
      (*item)->update(dt);
    }
  }
}

void C_DebugScreen::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  if (!m_text_list.empty()) {
    for (auto it = m_text_list.begin(); it < m_text_list.end(); ++it) {
      auto item = it.base();
      (*item)->draw(target, states);
    }
  }
}

void C_DebugScreen::drawCurrent(sf::RenderTarget &target, sf::RenderStates states) const {

}