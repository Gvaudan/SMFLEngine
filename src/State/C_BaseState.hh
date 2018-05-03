//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_BASESTATE_HH
#define INC_2DGAMEFRAMEWORK_BASESTATE_HH


#include "../Input/C_InputHandler.hh"
#include <Thor/Input.hpp>
#include <Thor/Animations.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>


class C_Entity;

class C_BaseState {
public:
  virtual void handleInput() = 0;

  virtual void update() = 0;

  virtual void update(sf::Time p_eleapsed_time) = 0;

  virtual C_BaseState *update_state(sf::Time p_eleapsed_time, C_Entity &p_entity) = 0;
  
  virtual void draw_state(sf::RenderTarget &p_target, sf::RenderStates p_states, C_Entity &p_entity) = 0;

  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) = 0;

  virtual void on_start() = 0;

  virtual C_BaseState *on_exit() = 0;

  virtual const std::string &get_state_id() const;

  void push_action(std::string p_name, thor::Action p_action);

  void push_event(sf::Event &p_event);

  void clean_event();

  bool is_cancelable() const;

  bool is_reloadable() const;

  thor::ActionMap<std::string> &get_action_map();

protected:
  virtual void init_actions();
  virtual void build_animiations() = 0;
  bool m_is_cancelable = true;
  bool m_is_reloadable = true;

  std::string m_state_id;
  thor::ActionMap<std::string> m_action_map;
  thor::Animator<C_BaseState, std::string> *m_animator;
  std::set<thor::FrameAnimation> m_animations;
};

#endif //INC_2DGAMEFRAMEWORK_BASESTATE_HH