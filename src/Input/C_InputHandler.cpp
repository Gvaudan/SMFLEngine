//
// Created by David on 22/04/2018.
//

#include "C_InputHandler.hh"
#include <boost/log/trivial.hpp>
#include <Thor/Resources/ResourceLoader.hpp>
#include <utility>

void C_InputHandler::update_gamepads() {
  if (!m_connected_gamepad.empty()) {
	for (auto it = m_connected_gamepad.begin(); it != m_connected_gamepad.end(); ++it) {
	  it->second.get()->update_inputs();
	}
  }
}

void C_InputHandler::is_connected(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  if (m_connected_gamepad.empty() || m_connected_gamepad.count(p_id) < 1) {
	m_connected_gamepad[p_id] = m_gamepad_holder.acquire(p_id, load_gamepad(p_id),
														 thor::Resources::Reuse);
	m_connected_gamepad[p_id].get()->on_connect();
	return;
  }
  m_connected_gamepad[p_id].get()->on_connect();
}

void C_InputHandler::is_diconnected(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);

  /*Si aucun gamepad n'est present, la cible etait connecter avant que le handler ne soit initialise*/
  if (m_connected_gamepad.empty()) {
	m_connected_gamepad[p_id] = m_gamepad_holder.acquire(p_id, load_gamepad(p_id),
														 thor::Resources::Reuse);
  }
  m_connected_gamepad[p_id].get()->on_disconnect();
}

void C_InputHandler::push_gamepad(std::string p_id, ControllerBind::C_GamePad *p_gamepad) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << p_id;
}

thor::ResourceLoader<ControllerBind::C_GamePad> C_InputHandler::load_gamepad(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  return thor::ResourceLoader<ControllerBind::C_GamePad>(
	  [=]() {
		return std::unique_ptr<ControllerBind::C_GamePad>(build_gamepad(p_id));
	  }, std::to_string(p_id));
}

ControllerBind::C_GamePad *C_InputHandler::build_gamepad(unsigned int p_id) {
  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_id);
  auto gmpd = new ControllerBind::C_GamePad(p_id);
  return gmpd;
}

void C_InputHandler::assign_gamepad(unsigned int p_gamepad, std::string p_assignation) {
  if (m_connected_gamepad.count(p_gamepad) > 0) {
	if (m_gamepad_assignation.count(p_gamepad) == 0) {
	  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : " << std::to_string(p_gamepad) << " to : "
							   << p_assignation;
	  m_gamepad_assignation[p_gamepad] = std::move(p_assignation);
	} else {
	  BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << " : allready assigned to : "
							   << m_gamepad_assignation[p_gamepad];
	}
  }
}

ControllerBind::C_GamePad *C_InputHandler::get_gamepad(unsigned int p_gamepad) {
  if (m_connected_gamepad.count(p_gamepad) > 0) {
	return m_connected_gamepad[p_gamepad].get();
  }
  m_connected_gamepad[p_gamepad] = m_gamepad_holder.acquire(p_gamepad, load_gamepad(p_gamepad),
															thor::Resources::Reuse);
  m_connected_gamepad[p_gamepad].get()->on_connect();
  return m_connected_gamepad[p_gamepad].get();
}
