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
#include "SmartChange.h"

namespace vns {
    SmartNetworkModule::SmartNetworkModule(RoadNetwork *roadNetwork) {
        this->roadNetwork = roadNetwork;
    }

    void SmartNetworkModule::onVehicleCreated(Simulator *sim,
                                              Vehicle *vehicle) { //todo: called form simulator onVehicleCreated
        vehicles.push_back(vehicle);
    }

    void SmartNetworkModule::onVehicleRemoved(Simulator *sim,
                                              Vehicle *vehicle) { //todo: called form simulator onVehicleCreated
        vehicles.remove(vehicle);
    }

    void SmartNetworkModule::send(TrafficLightController *sender, Vehicle *receiver, SmartData *data) {
        receiver->receiveSmartData(data);
    }

    bool isInRange(Junction *sender, Vehicle *receiver) {
        const double SMART_RANGE = 250; //todo: move

        Vec senderPosition = sender->getPosition();
        Vec receiverPosition = receiver->getPosition();
        double distance = senderPosition.distanceTo(receiverPosition);
        return distance < SMART_RANGE;
    }

    void SmartNetworkModule::onSimulationStep(Simulator *sim) {
        float timeToNextRed = 0;
        float timeToNextGreen = 0;

        std::list<Vehicle *>::iterator it;
        for (it = vehicles.begin(); it != vehicles.end(); it++) {
            Vehicle *currentVehicle = *it;

            Lane *currentCarLane = currentVehicle->getLane();
            if (currentCarLane == NULL) continue;
            Junction *junction = currentCarLane->getEndJunction();
            if(junction == NULL) continue;
            Vec junctionPosition = junction->getPosition();

            if (!isInRange(junction, currentVehicle)) continue;


            //todo: check if not 0
            Light currentLightColor = currentCarLane->getTrafficLightColor(); //todo
            SmartChange * smartChange = currentCarLane->getSmartChange();

            if(smartChange == NULL) continue;

            Light currentLight = smartChange->getCurrentLight();
            Light nextLight = smartChange->getNextLight();
            float timeToChange = smartChange->getTimeToChange();
            SmartData *smartData;

            if(currentLight == vns::RedLight) {
                if(nextLight == vns::GreenLight)
                {
                    smartData = new SmartData(junctionPosition,timeToChange,timeToChange+25);
                }
                else if(nextLight == vns::RedLight){
                    smartData = new SmartData(junctionPosition,timeToChange+5,timeToChange+30);

                }
            }
            else if(currentLight == vns::YellowLight) {
                smartData = new SmartData(junctionPosition,timeToChange+25,timeToChange);

            }
            else if(currentLight == vns::GreenLight) {
                smartData = new SmartData(junctionPosition,timeToChange+30,timeToChange+5);

            }
            else {
                //todo
            }


//            if (currentLightColor == vns::RedLight) {
//                timeToNextGreen = timeToChange + 5.0;
//                timeToNextRed = timeToNextGreen + 25.0;
//            }
//            else if (currentLightColor == vns::GreenLight) {
//                timeToNextRed = timeToChange + 5.0;
//                timeToNextGreen = timeToNextRed + 25.0;
//            }
//            else if (currentLightColor == vns::YellowLight) {
//                timeToNextRed = timeToChange;
//                timeToNextGreen = timeToNextRed + 25.0;
//            }
            send(NULL, currentVehicle, smartData);
        }
    }

}