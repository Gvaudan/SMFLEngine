//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_JOYAXISVALUE_HH
#define INC_2DGAMEFRAMEWORK_C_JOYAXISVALUE_HH

#include <SFML/Window/Joystick.hpp>
#include "C_DrawableString.hh"

class C_JoyAxisValue : public C_DrawableString {
public:
  C_JoyAxisValue(sf::Joystick::Axis x_axis, sf::Joystick::Axis y_axis, std::string id);

  void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

  void update(sf::Time dt) override;

private:
  sf::Joystick::Axis m_axis_x;
  sf::Joystick::Axis m_axis_y;
public:
  const std::string &get_joystick_id() const;

private:
  std::string m_joystick_id;
};


#endif //INC_2DGAMEFRAMEWORK_C_JOYAXISVALUE_HH
