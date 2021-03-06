//
// Created by user on 19.05.16.
//

#ifndef INTELLIGENT_CROSSING_SIMULATOR_SMARTNETWORKMODULE_H //todo: change
#define INTELLIGENT_CROSSING_SIMULATOR_SMARTNETWORKMODULE_H

#include "core.h"
#include "lock.h"
#include "networkmodule.h"
#include "hashtable.h"
#include "SmartData.h"
#include "trafficlightcontroller.h"
#include <string>
#include <list>

namespace vns {
    class SmartNetworkModule {

    private:
            std::list<Vehicle *> vehicles;
            RoadNetwork* roadNetwork;
        //todo: list of crossings

    public:
        SmartNetworkModule(RoadNetwork* roadNetwork);
        void onVehicleCreated(Simulator* sim, Vehicle * vehicle);
        void onVehicleRemoved(Simulator* sim, Vehicle * vehicle);
        void send(TrafficLightController * sender, Vehicle * receiver, SmartData * data);
        void onSimulationStep(Simulator* sim);

    };
}


#endif //INTELLIGENT_CROSSING_SIMULATOR_SMARTNETWORKMODULE_H
