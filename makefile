
ifeq "$(OS)" ""
    OS = $(shell uname -s)
endif

CC = g++
DIALECT = -std=c++14
DEBUG = -g
CFLAGS = $(DEBUG) -Wno-deprecated $(DIALECT)
LDFLAGS=

ifeq "$(OS)" "Darwin"
    LFLAGS = -framework OpenGL -framework GLUT
else
    LFLAGS = -lGL -lGLU -lglut
endif

EXEC = battle
SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)
	
all : $(EXEC)	

battle: $(OBJS)
	$(CC) $(CFLAGS) $(LFLAGS) $(LDFLAGS) -o $@ $^

%.o: %.cpp 
	$(CC) -c $(CFLAGS) -o $@ $<
	
%.d : %.cpp 
	@set -e; rm -f $@; $(CC) -MM $(CFLAGS) $(LFLAGS) $< > ˜$@; sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < ˜$@ > $@; rm -f ˜$@
	
.PHONY: clean	
        
clean:
	rm -f $(EXEC) $(OBJS)
