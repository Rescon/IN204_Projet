CXX = g++ -fopenmp
LIB = -lpthread

CXXFLAGS = -std=c++14
ifdef DEBUG
CXXFLAGS += -g -O0 -Wall -fbounds-check -pedantic -D_GLIBCXX_DEBUG
else
CXXFLAGS += -O3 -march=native -Wall
endif

LIBS = $(LIB)

ALL = main.exe

default:	help

all: $(ALL)

clean:
	@rm -fr out/*.o *.exe Result.ppm

OBJS = out/Camera.o out/Color.o out/Light.o out/Object.o out/Plane.o out/Ray.o out/Source.o out/Sphere.o out/Utils.o out/Vector.o out/main.o

out/Camera.o: src/Camera.cpp src/Camera.hpp
	$(CXX) $(CXXFLAGS) -c src/Camera.cpp -o out/Camera.o

out/Color.o: src/Color.cpp src/Color.hpp
	$(CXX) $(CXXFLAGS) -c src/Color.cpp -o out/Color.o

out/Light.o: src/Light.cpp src/Light.hpp
	$(CXX) $(CXXFLAGS) -c src/Light.cpp -o out/Light.o

out/Object.o: src/Object.cpp src/Object.hpp
	$(CXX) $(CXXFLAGS) -c src/Object.cpp -o out/Object.o

out/Plane.o: src/Plane.cpp src/Plane.hpp
	$(CXX) $(CXXFLAGS) -c src/Plane.cpp -o out/Plane.o

out/Ray.o: src/Ray.cpp src/Ray.hpp
	$(CXX) $(CXXFLAGS) -c src/Ray.cpp -o out/Ray.o

out/Source.o: src/Source.cpp src/Source.hpp
	$(CXX) $(CXXFLAGS) -c src/Source.cpp -o out/Source.o

out/Sphere.o: src/Sphere.cpp src/Sphere.hpp
	$(CXX) $(CXXFLAGS) -c src/Sphere.cpp -o out/Sphere.o

out/Utils.o: src/Utils.cpp src/Utils.hpp
	$(CXX) $(CXXFLAGS) -c src/Utils.cpp -o out/Utils.o

out/Vector.o: src/Vector.cpp src/Vector.hpp
	$(CXX) $(CXXFLAGS) -c src/Vector.cpp -o out/Vector.o

out/main.o: src/main.cpp src/Camera.hpp src/Color.hpp src/Light.hpp src/Object.hpp src/Plane.hpp src/Ray.hpp src/Source.hpp src/Sphere.hpp src/Utils.hpp src/Vector.hpp
	$(CXX) $(CXXFLAGS) -c src/main.cpp -o out/main.o

main.exe : $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o main.exe $(LIBS)

help:
	@echo "Available targets : "
	@echo "    all            : compile the executable"
	@echo "    main.exe     : compile the executable"
	@echo "Add DEBUG=yes to compile in debug"
	@echo "Configuration :"
	@echo "    CXX      :    $(CXX)"
	@echo "    CXXFLAGS :    $(CXXFLAGS)"

show:
	@echo "LIB   : $(LIB)"
	@echo "LIBS  : $(LIBS)"
