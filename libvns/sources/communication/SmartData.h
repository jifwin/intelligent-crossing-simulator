//
// Created by user on 21.05.16.
//

#ifndef INTELLIGENT_CROSSING_SIMULATOR_SMARTDATA_H
#define INTELLIGENT_CROSSING_SIMULATOR_SMARTDATA_H

#include "vec.h"

namespace vns {
    class SmartData {

    private:
        vns::Vec junctionPosition;
        float timeToNextGreen;
        float timeToNextRed;

    public:
        SmartData(vns::Vec junctionPosition, float timeToNextGreen, float timeToNextRed);
        vns::Vec getJunctionPosition() { return junctionPosition; }
        float getTimeToNextGreen() { return timeToNextGreen; }
        float getTimeToNextRed() { return timeToNextRed; }
    };
}
#endif //INTELLIGENT_CROSSING_SIMULATOR_SMARTDATA_H
