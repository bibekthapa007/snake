OBJS = snake.o
CXX = g++
CXXFLAGS = -Wall -std=c++11
LDLIBS =  -lsfml-audio -lsfml-window -lsfml-system -lsfml-graphics

LDFLAGS = -L/usr/lib/SFML/lib

game: $(OBJS)
	$(CXX) -o snake $(OBJS) $(LDLIBS) $(LDFLAGS)

clean:
	$(RM) snake $(OBJS)