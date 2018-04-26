//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_TESTSTATEMACHINE_HH
#define INC_2DGAMEFRAMEWORK_C_TESTSTATEMACHINE_HH

#include "../Tools/TemplateSingleton.hh"
#include "C_BaseStateMachine.hh"

#include "../Entities/C_TestEntitieState.hh"

class C_TestStateMachine :
        public TemplateSingleton<C_TestStateMachine>,
        public C_BaseStateMachine {
public:
    void set_entitie(C_TestEntitie *p_entity);

    void push_state(C_TestEntitieState *p_state);

    void change_state(C_TestEntitieState *p_state);

    void pop_state() override;

    void update() override;

    void render() override;

    void handleInput() override;

    C_TestEntitieState *get_current_state() override;

    void update_state(sf::Event &p_event) override;

private:
    C_TestEntitie *m_entity;
};


#endif //INC_2DGAMEFRAMEWORK_C_TESTSTATEMACHINE_HH
