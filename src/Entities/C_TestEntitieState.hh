//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TESTENTITIESTATE_HH
#define INC_2DGAMEFRAMEWORK_C_TESTENTITIESTATE_HH

#include "../State/C_BaseState.hh"

class C_TestEntitie;

class C_TestEntitieState : public C_BaseState {
public:
  C_TestEntitieState();

  explicit C_TestEntitieState(C_TestEntitie *p_entitie);

  void handleInput() override;

  virtual C_TestEntitieState *handle_input();

  virtual C_TestEntitieState *handle_input(C_TestEntitie &p_entitie);

  void update() override;

  virtual void update(C_TestEntitie &p_entitie, sf::Time p_eleapsed_time);

  void update(sf::Time p_eleapsed_time) override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) override;

  void on_start() override;

  C_BaseState *on_exit() override;

protected:
  void init_actions() override;

private:
  C_TestEntitie *m_entitie;
};


#endif //INC_2DGAMEFRAMEWORK_C_TESTENTITIESTATE_HH
