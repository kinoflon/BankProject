# Compiler
CXX = g++
# Compiler flags
CXXFLAGS = -std=c++11 -Wall
# Output executable name
TARGET = banking

# Source files
SRCS = Account.cpp ANZ.cpp Bank.cpp CommBank.cpp Customer.cpp main.cpp NAB.cpp Person.cpp Westpac.cpp

# Header files
HDRS = Account.h ANZ.h Bank.h CommBank.h Customer.h NAB.h Person.h Westpac.h

# Object files
OBJS = $(SRCS:.cpp=.o)

# Compile the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	
# Compile source files to object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up compiled files
clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)
