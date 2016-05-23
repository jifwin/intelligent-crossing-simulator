//
// Created by user on 21.05.16.
//

#include "SmartData.h"

namespace vns {
    SmartData::SmartData(vns::Vec junctionPosition, float timeToNextGreen, float timeToNextRed) {
        this->junctionPosition = junctionPosition;
        this->timeToNextGreen = timeToNextGreen;
        this->timeToNextRed = timeToNextRed;
    }
}