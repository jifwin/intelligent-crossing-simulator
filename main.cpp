#include "mynetwork.h"
#include "myvehicle.h"
#include "connectionspainter.h"
#include <vns/vns.h>
#include "libvns/sources/communication/smartnetworkmodule.h"
#include "libvns/sources/simulation/simulator.h"


int main(int argc, char* argv[]) {

	bool gui = true;

	vns::ManhattanMap man(1,1);
	man.setNumberOfForwardLanes(2);
	man.setNumberOfBackwardLanes(2);
	man.setRoadLength(500);

    	vns::RoadNetwork* network = man.createRoadNetwork();

	vns::TrafficLightsGenerator gen;
    	gen.generateTrafficLights(network);

	vns::Routes* routes = man.createRoutes(network,1.0,2.0,vns::CAR);
    vns::Simulator* simulator = new vns::Simulator();
	simulator->setRoadNetwork( network );

	simulator->setTrafficGenerationModel( new vns::TrafficGenerationModel(routes) );
	simulator->setVehicleFactory( new MyVehicleFactory() );

	simulator->setSmartNetworkModule(new vns::SmartNetworkModule(network));

	if(gui){
		vns::Visualizer* viewer = new vns::Visualizer( simulator );
    		viewer->setTitle("Beaconing Example");
		ConnectionsPainter* painter = new ConnectionsPainter();
		viewer->setPainter( painter );
		viewer->show();
	}else{
		simulator->run();
	}
	return 0;
}

