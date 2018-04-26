//
// Created by David on 22/04/2018.
//

#include "C_EventHandler.hh"
#include "../State/C_GameStateMachine.h"
#include "../State/C_TestStateMachine.hh"

void C_EventHandler::process_event(sf::Event &event, sf::Window *window) {
    while (window->pollEvent(event)) {
        C_GameStateMachine::get_instance()->update_state(event);
        C_TestStateMachine::get_instance()->update_state(event);
        if (event.type == sf::Event::Closed)
            window->close();
    }

    C_GameStateMachine::get_instance()->handleInput();
    C_TestStateMachine::get_instance()->handleInput();
}