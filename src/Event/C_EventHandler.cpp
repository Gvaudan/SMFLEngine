//
// Created by David on 22/04/2018.
//

#include "C_EventHandler.hh"

void C_EventHandler::process_event(sf::Event &event, sf::Window *window) {
  while (window->pollEvent(event)) {
    //TODO : Implémenter la gestion des evenement de jeu.
    //TODO : Déclancher un evenement de fermeture
    if (event.type == sf::Event::Closed)
      window->close();
  }
}
