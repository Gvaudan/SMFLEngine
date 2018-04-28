//
// Created by David on 22/04/2018.
//

#include "C_EventHandler.hh"
#include "../State/C_GameStateMachine.h"
#include "../Entities/C_TestStateMachine.hh"
#include "../Entities/C_TestEntitie.hh"

void C_EventHandler::process_event(sf::Event &event, sf::Window *window, C_TestEntitie &player) {
    while (window->pollEvent(event)) {
        C_GameStateMachine::get_instance()->update_state_event(event);
        player.update_state_event(event);
        if (event.type == sf::Event::Closed)
            window->close();
    }
    C_GameStateMachine::get_instance()->handleInput();
    player.handle_input();
}