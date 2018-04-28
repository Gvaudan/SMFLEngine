//
// Created by David on 29/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_STATEENTITY_HH
#define INC_2DGAMEFRAMEWORK_C_STATEENTITY_HH

#include "../Manager/C_EntityFactory.hh"
#include "../State/C_BaseStateMachine.hh"

#include <SFML/Graphics/RectangleShape.hpp>
#include <Thor/Input.hpp>

class C_StateEntity : public C_Entity, public C_BaseStateMachine {
public:
  C_StateEntity();

  explicit C_StateEntity(C_BaseState *p_state);

  void draw(sf::RenderTarget &p_target, sf::RenderStates p_states) const override;

  void drawCurrent(sf::RenderTarget &p_target, sf::RenderStates p_states) const override;

  virtual C_BaseState *handle_state_input(C_Entity &p_entitie) = 0;

  void set_current_state(C_BaseState *p_state);
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class C_StateEntityCreator : public C_BaseEntityCreator {
public:
  virtual C_StateEntity *CreateEntity() const;

  C_StateEntity *C_CreateEntity(C_BaseState *p_state);
};
#endif //INC_2DGAMEFRAMEWORK_C_STATEENTITY_HH
