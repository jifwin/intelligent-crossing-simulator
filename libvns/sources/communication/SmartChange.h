//
// Created by user on 21.05.16.
//

#ifndef INTELLIGENT_CROSSING_SIMULATOR_SMARTCHANGE_H
#define INTELLIGENT_CROSSING_SIMULATOR_SMARTCHANGE_H

#include "core.h"

namespace vns {
    class SmartChange {
    private:
        Light currentLight;
        Light nextLight;
        float timeToChange;

    public:
        SmartChange(Light currentLight, Light nextLight, float timeToChange);
        Light getCurrentLight() {return currentLight;}
        Light getNextLight() {return nextLight;}
        float getTimeToChange() {return timeToChange;}
    };
}
#endif
