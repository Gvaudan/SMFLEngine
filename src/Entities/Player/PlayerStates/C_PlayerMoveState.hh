//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_PLAYERMOVESTATE_HH
#define INC_2DGAMEFRAMEWORK_C_PLAYERMOVESTATE_HH

#include "C_PlayerStateBase.hh"

class C_PlayerMoveState  : public C_PlayerStateBase{
public:

  C_PlayerMoveState();

  C_PlayerStateBase *handle_input(C_Player &p_player) override;


  void handleInput() override;

  void update() override;

  void update(sf::Time p_eleapsed_time) override;

  C_BaseState *update_state(sf::Time p_eleapsed_time, C_Entity &p_entity) override;

  void draw_state(sf::RenderTarget &p_target, sf::RenderStates p_states, C_Entity &p_entity) override;

  void draw(sf::RenderTarget &target, sf::RenderStates states) override;

  void on_start() override;

  C_BaseState *on_exit() override;

protected:
  void build_animiations() override;

private:
  void init_action() override;
  sf::Vector2f m_move_vector;
};


#endif //INC_2DGAMEFRAMEWORK_C_PLAYERMOVESTATE_HH
