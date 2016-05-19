#include "mynetwork.h"
#include "myvehicle.h"

MyNetwork::MyNetwork() : vns::SimpleNetwork() {

}

MyNetwork::~MyNetwork() {

}

void MyNetwork::onInitialize(const vns::Simulator* sim,vns::Vehicle* vehicle) {
	double t = getSimulationTime()+1.0;
	scheduleTx(vehicle);
}

void MyNetwork::scheduleTx(vns::Vehicle* vehicle){
	double t = getSimulationTime();
	Data* data = new Data(t);
	send(vehicle,data);
	getScheduler()->schedule(t+1.0,&MyNetwork::scheduleTx,this,vehicle);
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

