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
        SmartData(vns::Vec junctionPosition, int timeToNextGreen, int timeToNextRed);
    };
}
#endif //INTELLIGENT_CROSSING_SIMULATOR_SMARTDATA_H
