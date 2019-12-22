CXX=g++
CXXFLAGS=-std=c++11

SRC:=$(*.cpp)
all: TestCell TestSeq MaxSubRange ryu7_driver

TestCell: TestCell.o Cell.o
	$(CXX) $(CXXFLAGS) -o TestCell TestCell.o Cell.o

TestSeq: TestSeq.o Cell.o
	$(CXX) $(CXXFLAGS) -o TestSeq TestSeq.o Cell.o

MaxSubRange: MaxSubRange.o Cell.o
	$(CXX) $(CXXFLAGS) -o MaxSubRange MaxSubRange.o Cell.o

ryu7_driver: ryu7_driver.o
	$(CXX) $(CXXFLAGS) -o ryu7_driver ryu7_driver.o Cell.o

Cell.o: Cell.cpp
	$(CXX) $(CXXFLAGS) -c Cell.cpp

TestCell.o: TestCell.cpp
	$(CXX) $(CXXFLAGS) -c TestCell.cpp

TestSeq.o: TestSeq.cpp
	$(CXX) $(CXXFLAGS) -c TestSeq.cpp

MaxSubRange.o: MaxSubRange.cpp
	$(CXX) $(CXXFLAGS) -c MaxSubRange.cpp

ryu7_driver.o: ryu7_driver.cpp
	$(CXX) $(CXXFLAGS) -c ryu7_driver.cpp

clean:
	rm *.o TestCell TestSeq MaxSubRange ryu7_driver
