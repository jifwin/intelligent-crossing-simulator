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
        float timeToGreen = 60.0;
        SmartNetworkModule::SmartNetworkModule(RoadNetwork *roadNetwork) {
            this->roadNetwork = roadNetwork;
        }

        void SmartNetworkModule::onVehicleCreated(Simulator* sim, Vehicle * vehicle){ //todo: called form simulator onVehicleCreated
            vehicles.push_back(vehicle);
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

            vns::Vector<Junction*> junctions = roadNetwork->getAllJunctions();
            //todo: iterate over junctions
//            Junction* firstJunction = junctions.at(0);
            Junction* firstJunction = junctions.front();
            Vec position = firstJunction->getPosition(); //todo: this is how to get vector of junction position
            int debug = 1;
            //todo: iterator

            std::list<Vehicle*>::iterator iterator;
            SmartData* smartData = new SmartData(position, timeToGreen, timeToGreen); //todo time to red!
            timeToGreen -= 0.033;//todo: refactor

            for(iterator = vehicles.begin(); iterator != vehicles.end(); ++iterator) {
                Vehicle *veh = *iterator;
                send(NULL, veh, smartData);
            }
            Vehicle * vehicle = vehicles.front(); //todod: tepmorarly, use send function to call for each vehicle

            Lane* currentCarLane = vehicle->getCurrentLane();
//            currentCarLane->getTimeToNextChange(); //todo


                    //notatka:
//                    z tego co pamietam to traffic light controller USTAWIA na Lane obecne swiatlo
//            mozna by to rozszerzyc do czegos takiego ze ustawia obecne swiatlo
//            oraz czasy do nastepnego siwatla itp
//            zaraz to znajde


//            int timeToRed = 6;
//            float endStopTime = sim->time + stops.getDuration();

        }

}