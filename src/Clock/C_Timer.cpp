//
// Created by David on 22/04/2018.
//

#include "C_Timer.hh"

void C_Timer::start() {
  m_is_started = true;
  m_is_paused = false;
  m_start_ticks = m_clock.getElapsedTime();
}

void C_Timer::pause() {
  if (!m_is_paused && m_is_started) {
    m_is_paused = true;
    m_pause_ticks = m_clock.getElapsedTime() - m_start_ticks;
  }
}

void C_Timer::unpause() {
  if (m_is_started && m_is_paused) {
    m_is_paused = false;
    m_start_ticks = m_clock.getElapsedTime() - m_pause_ticks;
    m_pause_ticks = sf::Time::Zero;
  }
}

sf::Time C_Timer::restart() {

  m_is_started = true;
  m_is_paused = false;
  
  m_pause_ticks = m_start_ticks = m_clock.restart();
  return m_start_ticks;
}

bool C_Timer::is_started() {
  return m_is_started;
}

bool C_Timer::is_paused() {
  return m_is_paused;
}

sf::Time C_Timer::get_time() {
  return m_clock.getElapsedTime() - m_start_ticks;
}

void C_Timer::stop() {
  m_is_started = false;
  m_is_paused = false;
  m_pause_ticks = m_start_ticks = sf::Time::Zero;
}
