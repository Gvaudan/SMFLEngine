//
// Created by David on 22/04/2018.
//

#include "C_TestEntitie.hh"
#include <SFML/Window.hpp>

C_TestEntitie::C_TestEntitie() : m_rectangle(sf::Vector2f(120, 50)) {
    m_rectangle.setFillColor(sf::Color(100, 250, 50));
}

void C_TestEntitie::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_rectangle);
}

void C_TestEntitie::on_move_left() {
    this->move(-1, 0);
}

void C_TestEntitie::on_move_right() {
    this->move(1, 0);
}

void C_TestEntitie::on_move_up() {
    this->move(0, 1);

}

void C_TestEntitie::on_move_down() {
    this->move(0, -1);
}

C_PlayerState *C_TestEntitie::get_current_state() const {
    return m_current_state;
}

void C_TestEntitie::set_current_state(C_PlayerState *m_current_state) {
    C_TestEntitie::m_current_state = m_current_state;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
C_TestEntitie *C_TestEntityCreator::C_CreateEntity() const {
    auto created_entitie = new C_TestEntitie();

    return created_entitie;
}
