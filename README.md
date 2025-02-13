# MultithreadWebserver
Implementation of mutithreaded webserver in c++


Server.cpp
    - Will be the entrypoint for the application
    - We init the server with metadata like port and IP by instantiate TcpServer class
    - We call the listen method to begin listing for traffic

TcpServer.cpp
    - Contains implementation of class 
    - Constructor inits the server
    - Must have request queue
    - Listen will listen for incoming request and add to queue
    - Handle will itterate over queue and check for incoming request




CXX = g++
CXXFLAGS = -std=c++17

TARGET = TcpServer

SOURCE = TcpServer.cpp Server.cpp
OBJECTS = TcpServer.o Server.o


$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean: 
	rm -r $(TARGET)