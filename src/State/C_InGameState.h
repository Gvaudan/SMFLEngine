//
// Created by dyoubi on 26/04/2018.
//

#ifndef INC_2DGAMEFRAMEWORK_C_INGAMESTATE_H
#define INC_2DGAMEFRAMEWORK_C_INGAMESTATE_H

#include "C_BaseState.hh"

class C_InGameState  : public C_BaseState{
public:
    C_InGameState();

    void handleInput() override;

    void update() override;

    void render() override;

    void on_start() override;

    void on_exit() override;
};


#endif //INC_2DGAMEFRAMEWORK_C_INGAMESTATE_H
