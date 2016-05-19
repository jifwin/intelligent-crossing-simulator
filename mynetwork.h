#ifndef MYNETWORK_H_
#define MYNETWORK_H_

#include <vns/vns.h>
#include <vns/simplenetworkmodule.h>

class Data {
	public:
		Data(double t){ time = t; };
		inline double getTime(){ return time; };
	private:
		double time;
};

class MyNetwork : public vns::SimpleNetwork {
public:
	MyNetwork();
	virtual ~MyNetwork();

protected:
	void scheduleTx(vns::Vehicle* vehicle);
	void onInitialize(const vns::Simulator*,vns::Vehicle*);
	void onDataReceived(vns::Vehicle*,vns::Vehicle*, void*);
	void onSendFinish(void* data);

//	void onInitialize(const vns::Simulator *sim, vns::Vehicle *vehicle,
//                      vns::TrafficLightController *trafficLightController);
//
//	void scheduleTx(vns::TrafficLightController *trafficLightController);
//	void send(vns::TrafficLightController *trafficLightController, void* data);
//
//	void onDataReceived(vns::Vehicle *sender, vns::Vehicle *receiver, void *data);
//
//	void sendTest(vns::TrafficLightController* pController, void* pData);
};

#endif
