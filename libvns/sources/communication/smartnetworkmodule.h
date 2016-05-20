//
// Created by user on 19.05.16.
//

#ifndef INTELLIGENT_CROSSING_SIMULATOR_SMARTNETWORKMODULE_H //todo: change
#define INTELLIGENT_CROSSING_SIMULATOR_SMARTNETWORKMODULE_H
#include "string.h"

namespace vns {
    class SmartNetworkModule {

    private:
            List<Vehicle *> vehicles;
        //todo: list of crossings

    public:
        void onVehicleCreated(Vehicle * vehicle);
        void send(TrafficLightController * sender, std::string data);
        void step();

    };
}


#endif //INTELLIGENT_CROSSING_SIMULATOR_SMARTNETWORKMODULE_H
