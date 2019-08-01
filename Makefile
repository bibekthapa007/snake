OBJS = main.o Snake.o Food.o  BaseObject.o
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDLIBS =  -lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics
# IFLAGS = -I./**
LDFLAGS = -L/usr/lib/SFML/lib 

game: $(OBJS)
	$(CXX)  -o main $(OBJS) $(LDLIBS) $(LDFLAGS) ${IFLAGS} ${CXXFLAGS}

clean:
	$(RM) main $(OBJS)