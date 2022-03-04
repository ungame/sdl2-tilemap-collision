CC = g++
SRC_DIR = src
SRC_FILES = ${shell where /R ${SRC_DIR} *.cpp}
COMPILE_FLAGS = -c -std=c++14 -m64 -g -Wall
INCLUDE_PATHS = -I include
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2
BUILD_DIR = build

clear:
	- rmdir /q /s ${BUILD_DIR}

all: clear
	${CC} ${SRC_FILES} ${COMPILE_FLAGS} ${INCLUDE_PATHS}
	mkdir ${BUILD_DIR}
	move *.o ${BUILD_DIR}
	${CC} ${BUILD_DIR}/*.o -o ${BUILD_DIR}/main ${LINKER_FLAGS}

run:
	build/main.exe