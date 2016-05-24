//
// Created by user on 21.05.16.
//

#include "SmartChange.h"

namespace vns {
    SmartChange::SmartChange(Light currentLight, Light nextLight, float timeToChange)  {
        this->nextLight = nextLight;
        this->currentLight = currentLight;
        this->timeToChange = timeToChange;
    }
}