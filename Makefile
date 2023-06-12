SOURCE = $(wildcard src/*.cpp)
SOURCE += $(wildcard src/*/*.cpp)
SOURCE += $(wildcard src/*.c)
SOURCE += $(wildcard src/*/*.c)
SOURCE += $(wildcard src/*/*/*.c)
SOURCE += $(wildcard src/*/*/*/*.c)
SOURCE += $(wildcard src/*/*/*/*/*.c)
SOURCE += $(wildcard src/*/*/*/*/*/*.c)

SOURCE_LIB = $(wildcard src/vendor/*.cpp)
SOURCE_LIB += $(wildcard src/vendor/*/*.cpp)
SOURCE_LIB += $(wildcard src/vendor/*/*/*.cpp)
SOURCE_LIB += $(wildcard src/vendor/*/*/*/*.cpp)
SOURCE_LIB += $(wildcard src/vendor/*/*/*/*/*.cpp)
SOURCE_LIB += $(wildcard src/vendor/*/*/*/*/*/*.cpp)

# Variables
INCLUDE_HEADERS = -I"./src/vendor"
FLAGS = -g $(INCLUDE_HEADERS) -lGL -lGLU -lglut -lGLEW -lglfw -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor 
LINUX_BINARY = main.x86_64

# Compilers
MINGW_COMPILER = x86_64-w64-mingw32-g++
GNU_LINUX_COMPILER = g++

build_lib:
	g++ -c $(SOURCE_LIB) $(FLAGS)
	make build_linux

build_linux:
	g++ -c $(SOURCE) $(FLAGS)
	mv *.o bin
	g++ bin/*.o -o $(LINUX_BINARY) $(FLAGS)
	mv $(LINUX_BINARY) bin/linux
	./star.sh

