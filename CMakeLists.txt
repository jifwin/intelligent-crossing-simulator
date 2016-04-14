cmake_minimum_required(VERSION 3.5)
project(intelligent_crossing_simulator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

link_libraries(
        vns
        vns-ns3
        ns3-core
        ns3-network
        ns3-internet
        ns3-mobility
        ns3-wifi
)

set(SOURCE_FILES
    beacon.h
    beaconapplication.h
    connectionspainter.cpp
    connectionspainter.h
    info
    main.cpp
    Makefile
    mynetwork.cpp
    mynetwork.h
    myvehicle.h
    README.md)

add_executable(intelligent_crossing_simulator ${SOURCE_FILES})