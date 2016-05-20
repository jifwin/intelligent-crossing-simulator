//
// Created by user on 19.05.16.
//

#include "smartnetworkmodule.h"


namespace vns {
    class SmartNetworkModule {

    private:
        List<Vehicle *> vehicles;
        //todo: list of crossings

    public:
        void onVehicleCreated(Vehicle * vehicle){ //todo: called form simulator onVehicleCreated
            vehicles.append(vehicle);
        }
        void send(TrafficLightController * sender, Vehicle * receiver, String data) { //todo: another clasls for wrapped data
            sender->getPosition();
            sender->getNearestChange();//todo: etc

            SmartData data = new SmartData(position, czas, cos co);
            receiver.setNewData(data);

            //todo: in vehicle.setNewData
            {
                //todo: sets local field with new data and apply acceleration based on that data

            }
            //todo: schedule
        }
        void step() {
            junctions.foreach:
                vehicles.rforeach:
                    czy sa w zasiegu, jesli tak send()
        }

    };
}