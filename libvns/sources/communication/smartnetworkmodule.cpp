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
        void SmartNetworkModule::onVehicleCreated(Simulator* sim, Vehicle * vehicle){ //todo: called form simulator onVehicleCreated
            vehicles.push_back(vehicle);
        }
        void SmartNetworkModule::send(TrafficLightController * sender, Vehicle * receiver, std::string data) { //todo: another clasls for wrapped data
//            sender->getPosition(); //todo
//            sender->getNearestChange();//todo: etc

            //SmartData data = new SmartData(position, czas, cos co);
            //receiver.setNewData(data);

            //todo: in vehicle.setNewData
            {
                //todo: sets local field with new data and apply acceleration based on that data

            }
            //todo: schedule
        }
        void SmartNetworkModule::step() {
          /*  junctions.foreach:
                vehicles.rforeach:
                    czy sa w zasiegu, jesli tak send()*/
        }

}