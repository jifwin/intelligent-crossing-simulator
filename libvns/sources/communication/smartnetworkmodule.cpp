//
// Created by user on 19.05.16.
//

#include "smartnetworkmodule.h"
#include "simulator.h"
#include "vehicle.h"
#include <string>
#include "trafficlightcontroller.h"
#include <list>

namespace vns {
        SmartNetworkModule::SmartNetworkModule(RoadNetwork *roadNetwork) {
            this->roadNetwork = roadNetwork;
        }

        void SmartNetworkModule::onVehicleCreated(Simulator* sim, Vehicle * vehicle){ //todo: called form simulator onVehicleCreated
            vehicles.push_back(vehicle);
        }
        void SmartNetworkModule::send(TrafficLightController * sender, Vehicle * receiver, std::string data) { //todo: another clasls for wrapped data
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

            int debug = 1;
            //todo: iterator
            Vehicle * vehicle = vehicles.front(); //todo: tepmorarly, use send function to call for each vehicle
            std::string smartData = "smart data content"; //todo: create seperate class for wrapping a lot of lights data
            send(NULL, vehicle, smartData);
        }

}