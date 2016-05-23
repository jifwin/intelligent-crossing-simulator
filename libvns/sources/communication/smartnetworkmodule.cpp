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

        void SmartNetworkModule::onVehicleCreated(Simulator* sim, Vehicle * vehicle){ //todo: called form simulator onVehicleCreated
            vehicles->insert(vehicle->getID(),vehicle);
        }
        void SmartNetworkModule::send(TrafficLightController * sender, Vehicle * receiver, SmartData * data) {
//            sender->getPosition(); //todo
//            sender->getNearestChange();//todo: etc

            //SmartData data = new SmartData(position, czas, cos co);
            //receiver.setNewData(data);
            receiver->receiveSmartData(data);
        }
        void SmartNetworkModule::onSimulationStep(Simulator *sim) {
            //todo: foreach junction
            //todo: foreach vehicle
            //todo: check range and send
            float timeToNextRed = 0;
            float timeToNextGreen = 0;

            vns::Vector<Junction*> junctions = roadNetwork->getAllJunctions();
            //todo: iterate over junctions
            Junction* firstJunction = junctions.at(0);
            Vec position = firstJunction->getPosition(); //todo: this is how to get vector of junction position
            int debug = 1;
            //todo: iterator

            vns::HashTable<uint64, Vehicle*>::Iterator it(vehicles);
            while( it.isValid() ) {
                //Vehicle * vehicle = vehicles.front(); //todod: tepmorarly, use send function to call for each vehicle
                Vehicle* vehicle = it.value();
                Lane *currentCarLane = vehicle->getLane();
                //todo: check if not 0
                Light currentLightColor = currentCarLane->getTrafficLightColor(); //todo
                float timeToChange = currentCarLane->getLightChangeTime();


                //notatka:
//            z tego co pamietam to traffic light controller USTAWIA na Lane obecne swiatlo
//            mozna by to rozszerzyc do czegos takiego ze ustawia obecne swiatlo
//            oraz czasy do nastepnego siwatla itp
//            zaraz to znajde


                if (currentLightColor == vns::RedLight) {
                    timeToNextGreen = timeToChange + 5.0;
                    timeToNextRed = timeToNextGreen + 25.0;
                    SmartData *smartData = new SmartData(position, timeToNextGreen, timeToNextRed);
                    send(NULL, vehicle, smartData);
                }
                else if (currentLightColor == vns::GreenLight) {
                    timeToNextRed = timeToChange + 5.0;
                    timeToNextGreen = timeToNextRed + 25.0;
                    SmartData *smartData = new SmartData(position, timeToNextGreen, timeToNextRed);
                    send(NULL, vehicle, smartData);
                }
                else if (currentLightColor == vns::YellowLight) {

                }
                //SmartData* smartData = new SmartData(position, timeToNextGreen, timeToNextRed);
                //send(NULL, vehicle, smartData);
                it.next();
            }
        }

}