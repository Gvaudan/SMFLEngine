//
// Created by David on 22/04/2018.
//

#include <boost/log/trivial.hpp>
#include "../Input/C_InputHandler.hh"
#include "C_EventHandler.hh"
#include "../State/C_GameStateMachine.h"
#include "../Entities/C_TestStateMachine.hh"
#include "../Entities/C_TestEntitie.hh"

void C_EventHandler::process_event(sf::Event &event, sf::Window *window, C_Player &player) {

  C_GameStateMachine::get_instance()->clear_state_event();
  player.clear_state_event();

  while (window->pollEvent(event)) {
    if (event.type == sf::Event::Closed)
      window->close();

    if (event.type == sf::Event::JoystickConnected) {
      C_InputHandler::get_instance()->is_connected(event.joystickConnect.joystickId);
    }
    if (event.type == sf::Event::JoystickDisconnected) {
      C_InputHandler::get_instance()->is_diconnected(event.joystickConnect.joystickId);
    }

    C_GameStateMachine::get_instance()->update_state_event(event);
    player.update_state_event(event);
  }

  C_GameStateMachine::get_instance()->handleInput();
  player.handle_input();
}