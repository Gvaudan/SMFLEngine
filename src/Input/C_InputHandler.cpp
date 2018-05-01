//
// Created by David on 22/04/2018.
//

#include "C_InputHandler.hh"
#include <boost/log/trivial.hpp>
#include <Thor/Resources/ResourceLoader.hpp>

void C_InputHandler::update_gamepads() {

}

void C_InputHandler::is_connected(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  m_gamepad_holder.acquire(p_id, load_gamepad(p_id), thor::Resources::Reuse).get()->on_connect();
}

void C_InputHandler::is_diconnected(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  m_gamepad_holder.acquire(p_id, load_gamepad(p_id), thor::Resources::Reuse).get()->on_disconnect();
}

void C_InputHandler::push_gamepad(std::string p_id, ControllerBind::C_GamePad *p_gamepad) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << p_id;

}

thor::ResourceLoader<ControllerBind::C_GamePad> C_InputHandler::load_gamepad(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  return thor::ResourceLoader<ControllerBind::C_GamePad>(
      [=]() { return std::unique_ptr<ControllerBind::C_GamePad>(build_gamepad(p_id)); }, std::to_string(p_id));
}

ControllerBind::C_GamePad *C_InputHandler::build_gamepad(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  return new ControllerBind::C_GamePad(p_id);
}