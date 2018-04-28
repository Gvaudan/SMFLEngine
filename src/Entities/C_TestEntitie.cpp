//
// Created by David on 22/04/2018.
//

#include "C_TestEntitieState.hh"
#include <SFML/Window.hpp>
#include <boost/log/trivial.hpp>

#include "C_TestEntitieState.hh"
#include "C_TestEntitie.hh"

C_TestEntitie::C_TestEntitie() : m_rectangle(sf::Vector2f(120, 50)) {
  m_rectangle.setFillColor(sf::Color(100, 250, 50));
  push_state(new C_TestEntitieState);
}

C_TestEntitie::C_TestEntitie(C_TestEntitieState *p_current_state) {
  push_state(p_current_state);
  m_rectangle.setFillColor(sf::Color(100, 250, 50));
}

void C_TestEntitie::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(m_rectangle);
}

void C_TestEntitie::on_move_left() {
  float move = m_laste_time.asSeconds() * 100;
  BOOST_LOG_TRIVIAL(trace) << std::to_string(move);
  this->move(-move, 0);
}

void C_TestEntitie::on_move_right() {
  float move = m_laste_time.asSeconds() * 100;
  BOOST_LOG_TRIVIAL(trace) << std::to_string(move);
  this->move(move, 0);
}

void C_TestEntitie::on_move_up() {
  float move = m_laste_time.asSeconds() * 2;
  this->move(0, move);

}

void C_TestEntitie::on_move_down() {
  float move = m_laste_time.asSeconds() * 2;
  this->move(0, -move);
}

C_TestEntitieState *C_TestEntitie::get_current_state() const {

  if (m_state_list.empty())
    return nullptr;
  return (C_TestEntitieState *) m_state_list.back();
}

void C_TestEntitie::set_current_state(C_TestEntitieState *m_current_state) {
  C_TestEntitie::m_current_state = m_current_state;
}

void C_TestEntitie::update(sf::Time dt) {
  C_SceneNode::update(dt);
  m_laste_time = dt;
  m_rectangle.setPosition(this->getPosition().x, this->getPosition().y);
}

void C_TestEntitie::handle_input() {
  C_TestEntitieState *new_state = handle_state_input((*this));

  if (new_state != nullptr) {
    BOOST_LOG_TRIVIAL(debug) << __PRETTY_FUNCTION__ << "new state : " << new_state->get_state_id();
    change_state(new_state);
  }
  //Do stuff...
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
C_TestEntitie *C_TestEntityCreator::C_CreateEntity() const {
  auto created_entitie = new C_TestEntitie();
  return created_entitie;
}

C_TestEntitie *C_TestEntityCreator::C_CreateEntity(C_TestEntitieState *p_state) {
  return new C_TestEntitie(p_state);
}
