//
// Created by David on 29/04/2018.
//

#include "C_GamePad.hh"

ControllerBind::C_GamePad::C_GamePad() {

}

void ControllerBind::C_GamePad::bind_inputs() {

}

const ControllerBind::t_gamepad_stick &ControllerBind::C_GamePad::get_LStick() const {
  return m_LStick;
}

const ControllerBind::t_gamepad_stick &ControllerBind::C_GamePad::get_RStick() const {
  return m_RStick;
}

const ControllerBind::t_gamepad_stick &ControllerBind::C_GamePad::get_DPad() const {
  return m_DPad;
}
