//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_BASESTATEMACHINE_HH
#define INC_2DGAMEFRAMEWORK_BASESTATEMACHINE_HH

#include "C_BaseState.hh"
#include <vector>
class C_BaseStateMachine {
public:
  virtual void push_state(C_BaseState *p_state);

  virtual void change_state(C_BaseState *p_state);

  virtual void change_state(std::vector<C_BaseState *> p_vector_state, C_BaseState *p_state);

  virtual void change_state(std::vector<C_BaseState *> *p_vector_state, C_BaseState *p_state);

  virtual void change_game_state(C_BaseState *p_state);

  virtual void change_object_state(uint32_t p_id, C_BaseState *p_state);

  virtual void pop_state();

  virtual C_BaseState *get_player_state();

  virtual void update();

  virtual void render();

  virtual void handleInput();

  static void build_instance();

  void push_object(void *p_object);

  void pop_object(uint32_t p_id);

  void set_object_state(uint32_t  p_id, C_BaseState *p_state);

  C_BaseState *get_object_state(uint32_t  p_id);

protected:
  std::vector<C_BaseState *> m_state_list;
};


#endif //INC_2DGAMEFRAMEWORK_BASESTATEMACHINE_HH
