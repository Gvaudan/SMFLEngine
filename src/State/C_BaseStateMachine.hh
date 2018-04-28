//
// Created by David on 22/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_BASESTATEMACHINE_HH
#define INC_2DGAMEFRAMEWORK_BASESTATEMACHINE_HH

#include "C_BaseState.hh"
#include <vector>

class C_BaseStateMachine {
public:
    virtual void push_state(C_BaseState *p_state);

    virtual void change_state(C_BaseState *p_state);

    virtual void pop_state();

    virtual void update();

    virtual void update(sf::Time p_eleapsed_time);

    virtual void draw(sf::RenderTarget &target, sf::RenderStates &states);

    virtual void handleInput();

    virtual C_BaseState *get_current_state();

    virtual void update_state_event(sf::Event &p_event);

protected:
    std::vector<C_BaseState *> m_state_list;
};


#endif //INC_2DGAMEFRAMEWORK_BASESTATEMACHINE_HH
