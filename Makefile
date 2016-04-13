RM= rm -f
EXE = beaconing


all: $(EXE)

$(EXE): main.o connectionspainter.o mynetwork.o
	g++ -o $(EXE) main.o connectionspainter.o mynetwork.o -lvns -lvns-ns3 -lns3-core -lns3-network -lns3-internet -lns3-mobility -lns3-wifi

main.o: mynetwork.h myvehicle.h connectionspainter.h
	g++ -c main.cpp

connectionspainter.o: connectionspainter.h myvehicle.h
	g++ -c connectionspainter.cpp

mynetwork.o: mynetwork.h beaconapplication.h beacon.h
	g++ -c mynetwork.cpp

clean:
	$(RM) *.o *~ $(EXE)
