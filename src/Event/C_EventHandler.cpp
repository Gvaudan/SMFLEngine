//
// Created by David on 22/04/2018.
//

#include <boost/log/trivial.hpp>
#include "C_EventHandler.hh"
#include "../State/C_GameStateMachine.h"
#include "../Entities/C_TestStateMachine.hh"
#include "../Entities/C_TestEntitie.hh"

void C_EventHandler::process_event(sf::Event &event, sf::Window *window, C_Player &player) {

  for (unsigned int index = 0; index < sf::Joystick::getButtonCount(0); ++index) {
    if (sf::Joystick::isButtonPressed(0, (index))) {
      BOOST_LOG_TRIVIAL(info) << "Joystick button " << std::to_string(index) << " is pressed";
    }
  }

  sf::Joystick::update();
//  BOOST_LOG_TRIVIAL(info) << "LeftStick X : " << std::to_string(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::X))
//                      << " - Y axis : " << std::to_string(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Y));

//  BOOST_LOG_TRIVIAL(info) << " Triggers Z axis : "
//                          << std::to_string(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::Z));
//  BOOST_LOG_TRIVIAL(info) << " Triggers U axis : "
//                          << std::to_string(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::U));
//  BOOST_LOG_TRIVIAL(info) << " Cross X : " << std::to_string(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovX))
//  << " - Cross Y: " << std::to_string(sf::Joystick::getAxisPosition(0, sf::Joystick::Axis::PovY));

  C_GameStateMachine::get_instance()->clear_state_event();
  player.clear_state_event();

  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window->close();
    C_GameStateMachine::get_instance()->update_state_event(event);
    player.update_state_event(event);
  }
  C_GameStateMachine::get_instance()->handleInput();
  player.handle_input();
}