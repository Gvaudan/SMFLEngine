//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_PLAYER_HH
#define INC_2DGAMEFRAMEWORK_C_PLAYER_HH

#include "../C_StateEntity.hh"
#include "../Manager/C_EntityFactory.hh"

class C_Player : public C_StateEntity {
public:

  C_Player();

  void draw(sf::RenderTarget &p_target, sf::RenderStates p_states) const override;

  void drawCurrent(sf::RenderTarget &p_target, sf::RenderStates p_states) const override;

  void handle_input();

  C_BaseState *handle_state_input(C_Entity &p_entitie) override;

  void update(sf::Time dt) override;

private:
  sf::RectangleShape m_rectangle;
};

//======================================================================================================================

class C_PlayerCreator : C_BaseEntityCreator {
  C_Entity *C_CreateEntity() const override;
  ~C_PlayerCreator() override;
};

#endif //INC_2DGAMEFRAMEWORK_C_PLAYER_HH
