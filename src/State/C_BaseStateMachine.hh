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

    virtual void render();

    virtual void handleInput();

protected:
    std::vector<C_BaseState *> m_state_list;
};


#endif //INC_2DGAMEFRAMEWORK_BASESTATEMACHINE_HH
