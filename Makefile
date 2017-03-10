#sudo apt-get install libglm-dev
#sudo apt-get install libglew-dev 

CC = g++
#DEBUG = -g
CFLAGS = $(DEBUG) -Wno-deprecated -std=c++11
LDFLAGS = $(DEBUG) -lm -lGL -lGLU -lglut -lGLEW
#LDFLAGS = $(DEBUG) -framework OpenGL -framework GLUT
EXEC = Battle
SRCS = Battle.cpp Pokemon.cpp

Battle: 
	$(CC) $(SRCS) $(CFLAGS) $(LDFLAGS) -o $@ 
	
.PHONY: clean	
        
clean:
	rm -f $(EXEC)