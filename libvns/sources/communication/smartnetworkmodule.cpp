//
// Created by user on 19.05.16.
//

#include "smartnetworkmodule.h"
#include "simulator.h"
#include "vehicle.h"
#include "SmartData.h"
#include <string>
#include "trafficlightcontroller.h"
#include <list>
#include "fixedtimetrafficlightcontroller.h"
#include "lane.h"

namespace vns {
    SmartNetworkModule::SmartNetworkModule(RoadNetwork *roadNetwork) {
        this->roadNetwork = roadNetwork;
    }

    void SmartNetworkModule::onVehicleCreated(Simulator *sim,
                                              Vehicle *vehicle) { //todo: called form simulator onVehicleCreated
        vehicles.push_back(vehicle);
    }

    void SmartNetworkModule::send(TrafficLightController *sender, Vehicle *receiver, SmartData *data) {
        receiver->receiveSmartData(data);
    }

    void SmartNetworkModule::onSimulationStep(Simulator *sim) {
        float timeToNextRed = 0;
        float timeToNextGreen = 0;

        vns::Vector<Junction *> junctions = roadNetwork->getAllJunctions();
        for (int i = 0; i < junctions.size(); i++) {
            Junction *junction = junctions.at(i);
            Vec junctionPosition = junction->getPosition();

            std::list<Vehicle *>::iterator it;
            for (it = vehicles.begin(); it != vehicles.end(); it++) {
                Vehicle *currentVehicle = *it;

                Lane *currentCarLane = currentVehicle->getLane();
                //todo: check if not 0
                Light currentLightColor = currentCarLane->getTrafficLightColor(); //todo
                float timeToChange = currentCarLane->getLightChangeTime();

                if (currentLightColor == vns::RedLight) {
                    timeToNextGreen = timeToChange + 5.0;
                    timeToNextRed = timeToNextGreen + 25.0;
                    SmartData *smartData = new SmartData(junctionPosition, timeToNextGreen, timeToNextRed);
                    send(NULL, currentVehicle, smartData);
                }
                else if (currentLightColor == vns::GreenLight) {
                    timeToNextRed = timeToChange + 5.0;
                    timeToNextGreen = timeToNextRed + 25.0;
                    SmartData *smartData = new SmartData(junctionPosition, timeToNextGreen, timeToNextRed);
                    send(NULL, currentVehicle, smartData);
                }
                else if (currentLightColor == vns::YellowLight) {
                    //todo: rethink
                }
            }
        }
    }

}