//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH
#define INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH


#include "../Manager/C_EntityFactory.hh"
#include <SFML/Graphics/RectangleShape.hpp>
#include <Thor/Input.hpp>

class C_TestEntitieState;
class C_TestEntitie : public C_Entity {

public:
    C_TestEntitie();

    explicit C_TestEntitie(C_TestEntitieState *p_current_state);

    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    void update(sf::Time dt) override;

    void on_move_left();

    void on_move_right();

    void on_move_up();

    void on_move_down();

    C_TestEntitieState *get_current_state() const;

    void set_current_state(C_TestEntitieState *m_current_state);

private:
    sf::RectangleShape m_rectangle;
    C_TestEntitieState *m_current_state = nullptr;
};

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

class C_TestEntityCreator : public C_BaseEntityCreator {
public:
    C_TestEntitie *C_CreateEntity() const override;

    C_TestEntitie *C_CreateEntity(C_TestEntitieState *p_state);
};

#endif //INC_2DGAMEFRAMEWORK_C_TESTENTITIE_HH
