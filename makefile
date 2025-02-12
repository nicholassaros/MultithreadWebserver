
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