//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_GAMESTATEMACHINE_H
#define INC_2DGAMEFRAMEWORK_C_GAMESTATEMACHINE_H

#include "../Tools/TemplateSingleton.hh"
#include "C_BaseStateMachine.hh"

#include "C_InGameState.h"

class C_GameStateMachine :
        public TemplateSingleton<C_GameStateMachine>,
        public C_BaseStateMachine {

public:
    void push_state(C_BaseState *p_state) override;

    void change_state(C_BaseState *p_state) override;

    void pop_state() override;

    void update() override;
    void update(sf::Time p_eleapsed_time);

    void draw(sf::RenderTarget &target, sf::RenderStates &states) override;

    void handleInput() override;

    void update_state_event(sf::Event &p_event) override;
};


#endif //INC_2DGAMEFRAMEWORK_C_GAMESTATEMACHINE_H
