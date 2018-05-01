//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_INPUTHANDLER_HH
#define INC_2DGAMEFRAMEWORK_INPUTHANDLER_HH

#include "C_GamePad.hh"

#include <TemplateSingleton.hh>
#include <map>
#include <Thor/Resources.hpp>

class C_InputHandler : public TemplateSingleton<C_InputHandler> {
public:
  void update_gamepads();

  void is_connected(unsigned int p_id);

  void is_diconnected(unsigned int p_id);

private:
  void push_gamepad(std::string p_id, ControllerBind::C_GamePad *p_gamepad);

  thor::ResourceLoader<ControllerBind::C_GamePad> load_gamepad(unsigned int p_id);

  thor::ResourceHolder<ControllerBind::C_GamePad, unsigned int, thor::Resources::RefCounted> m_gamepad_holder;
  std::map<std::string, unsigned int> m_gamepad_assignation;

  ControllerBind::C_GamePad *build_gamepad(unsigned int p_id);
};


#endif //INC_2DGAMEFRAMEWORK_INPUTHANDLER_HH
