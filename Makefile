CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = pokedex
SRCS = main.cpp HashMap.cpp load_pokemon.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(TARGET)

re: clean all