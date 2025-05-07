# Makefile for SmashTheMole

# Compiler and flags
CXX      = g++
CXXFLAGS = -std=c++17 -I/opt/homebrew/opt/sfml@2/include

# Linker flags for SFML (adjust paths if needed)
LDFLAGS  = -L/opt/homebrew/opt/sfml@2/lib -lsfml-graphics -lsfml-window -lsfml-system

# Source files
SOURCES  = Main.cpp Game.cpp Menu.cpp Target.cpp
OBJECTS  = $(SOURCES:.cpp=.o)
EXECUTABLE = SmashTheMole

# Default target
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXECUTABLE) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
