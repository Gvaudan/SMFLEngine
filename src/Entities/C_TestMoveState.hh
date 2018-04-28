//
// Created by David on 28/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TESTMOVESTATE_HH
#define INC_2DGAMEFRAMEWORK_C_TESTMOVESTATE_HH

#include "C_TestEntitieState.hh"

class C_TestMoveState : public C_TestEntitieState {
public:
  C_TestMoveState();

  explicit C_TestMoveState(C_TestEntitie *p_entitie);

  void handleInput() override;

  C_TestEntitieState *handle_input() override;

  C_TestEntitieState *handle_input(C_TestEntitie &p_entitie) override;

  void update() override;

  void update(C_TestEntitie &p_entitie, sf::Time p_eleapsed_time) override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) override;

  void on_start() override;

  C_BaseState *on_exit() override;

private:
  void init_actions() override;
};


#endif //INC_2DGAMEFRAMEWORK_C_TESTMOVESTATE_HH
