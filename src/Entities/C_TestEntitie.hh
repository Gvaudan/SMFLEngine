//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH
#define INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH

#include <SFML/Graphics/RectangleShape.hpp>
#include "../Manager/C_EntityFactory.hh"

#include "../State/C_PlayerState.h"

#include <Thor/Input.hpp>

class C_TestEntitie : public C_Entity {
public:
    C_TestEntitie();

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void on_move_left();

    void on_move_right();

    void on_move_up();

    void on_move_down();

    C_PlayerState *get_current_state() const;

    void set_current_state(C_PlayerState *m_current_state);

private:
    sf::RectangleShape m_rectangle;
    C_PlayerState *m_current_state = nullptr;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class C_TestEntityCreator : public C_BaseEntityCreator {
public:
    C_TestEntitie *C_CreateEntity() const override;
};

#endif //INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH
