#include "mynetwork.h"
#include "myvehicle.h"

MyNetwork::MyNetwork() : vns::SimpleNetwork() {

}

MyNetwork::~MyNetwork() {

}

void MyNetwork::onInitialize(const vns::Simulator* sim,vns::Vehicle* vehicle, vns::TrafficLightController* trafficLightController) {
	double t = getSimulationTime()+1.0;
	scheduleTx(trafficLightController);
}

void MyNetwork::scheduleTx(vns::TrafficLightController* trafficLightController){
	double t = getSimulationTime();
	Data* data = new Data(t);
	sendTest(trafficLightController, data);
	getScheduler()->schedule(t+1.0,&MyNetwork::scheduleTx,this,trafficLightController);
}

void MyNetwork::onDataReceived(vns::Vehicle* sender,vns::Vehicle* receiver, void* data){
	double t = ((Data*)data)->getTime();
	MyVehicle* v = dynamic_cast<MyVehicle*>(receiver);
	if (v == 0) return;
	v->addConnection(sender->getID(), sender->getPosition(), t);
}

void MyNetwork::onSendFinish(void* data){
	Data* d = (Data*)data;
	delete d;
}

// basic function to see if it works
void MyNetwork::sendTest(vns::TrafficLightController* pController, void* pData) {
	std::cout << "abc";
}

// this function supposed to be good; not working yet
//void MyNetwork::send(vns::TrafficLightController* sender,void* data){
//	vns::HashTable<uint64, vns::Vehicle*>::Iterator it(onBoardUnits);
////	vns::Vec pos;
////	inline vns::Vec getPosition() const { return pos; }
//	vns::Vec pos = sender->getPosition();
//	while( it.isValid() ) {
//		vns::Vehicle* vehicle = it.value();
//		if(pos.distanceToLessThan(vehicle->getPosition(),communicationRange)){
//			onDataReceived(sender,vehicle,data);
//		}
//		it.next();
//	}
//	onSendFinish(data);
//};

