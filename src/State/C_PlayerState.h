//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_PLAYERSTATE_H
#define INC_2DGAMEFRAMEWORK_C_PLAYERSTATE_H


#include "C_BaseState.hh"

class C_PlayerState : public C_BaseState {
public:
    void handleInput() override;

    void update() override;

    void render() override;

    void on_start() override;

    void on_exit() override;
};

#endif //INC_2DGAMEFRAMEWORK_C_PLAYERSTATE_H
