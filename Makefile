APP:=mygl
FLAGS:=-Wall
INCLUDE:=-I./include
LIB:=-lGL -lGLEW `sdl2-config  --cflags --libs`

build:
	@g++ ${FLAGS} ${INCLUDE} -o ${APP} *.cpp *.c ${LIB}

run: build
	@./${APP}

clean:
	@rm -rf *~ ${APP}

setup:
	@sudo apt-get install -y libsdl2-dev libglew-dev libglm-dev mesa-utils
	@sudo apt-get install -y freeglut3-dev
	@sudo apt-get install -y libglfw3-dev
