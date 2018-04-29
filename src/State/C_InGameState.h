//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_INGAMESTATE_H
#define INC_2DGAMEFRAMEWORK_C_INGAMESTATE_H

#include <SFML/Graphics/RenderTarget.hpp>
#include "C_BaseState.hh"

class C_InGameState : public C_BaseState {
public:
  C_InGameState();

  void handleInput() override;

  void update() override;

  void update(sf::Time p_eleapsed_time) override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) override;

  void on_start() override;

  C_BaseState *update_state(sf::Time p_eleapsed_time, C_Entity &p_entity) override;

  void draw_state(sf::RenderTarget &p_target, sf::RenderStates p_states, C_Entity &p_entity) override;

  C_BaseState *on_exit() override;
};


#endif //INC_2DGAMEFRAMEWORK_C_INGAMESTATE_H
