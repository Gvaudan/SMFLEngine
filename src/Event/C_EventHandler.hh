//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_EVENTHANDLER_HH
#define INC_2DGAMEFRAMEWORK_EVENTHANDLER_HH

#include "TemplateSingleton.hh"
#include "../Entities/C_TestEntitieState.hh"
#include <SFML/Window.hpp>

class C_EventHandler : public TemplateSingleton<C_EventHandler>{
public:
  void process_event(sf::Event &event, sf::Window *window, C_TestEntitie &player);
};


#endif //INC_2DGAMEFRAMEWORK_EVENTHANDLER_HH
