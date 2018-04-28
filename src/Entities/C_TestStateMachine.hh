//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TESTSTATEMACHINE_HH
#define INC_2DGAMEFRAMEWORK_C_TESTSTATEMACHINE_HH

#include "TemplateSingleton.hh"
#include "../State/C_BaseStateMachine.hh"
#include "C_TestEntitieState.hh"

class C_TestStateMachine : public C_BaseStateMachine {
public:
  void push_state(C_TestEntitieState *p_state);

  void change_state(C_TestEntitieState *p_state);

  void pop_state() override;

  void update() override;

  void update(sf::Time dt) override;

  void draw(sf::RenderTarget &target, sf::RenderStates &states) override;

  void draw(C_TestEntitie &entitie, sf::RenderTarget &target, sf::RenderStates &states);

  void handleInput() override;

  C_TestEntitieState * handle_state_input(C_TestEntitie &entitie);

  void update(C_TestEntitie &entitie, sf::Time dt);

  C_TestEntitieState *get_current_state() override;

  void update_state_event(sf::Event &p_event) override;

private:
  C_TestEntitie *m_entity;
};

#endif //INC_2DGAMEFRAMEWORK_C_TESTSTATEMACHINE_HH
