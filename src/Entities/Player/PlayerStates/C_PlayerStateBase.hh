//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_PLAYERSTATEBASE_HH
#define INC_2DGAMEFRAMEWORK_C_PLAYERSTATEBASE_HH

#include "../../../State/C_BaseState.hh"
#include "../Input/C_InputHandler.hh"

class C_Player;

class C_PlayerStateBase : public C_BaseState {
public:
  virtual C_PlayerStateBase *handle_input(C_Player &p_player) = 0;

  virtual void init_action() = 0;

protected:
  ControllerBind::C_GamePad *m_gamepad;
};


#endif //INC_2DGAMEFRAMEWORK_C_PLAYERSTATEBASE_HH
