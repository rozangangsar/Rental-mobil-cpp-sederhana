# Makefile untuk Aplikasi Rental Mobil
# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Target executable
TARGET = rental

# Object files
OBJS = main.o Car.o Renter.o RentalManager.o User.o AuthenticationManager.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build successful! Run with: ./$(TARGET)"

# Compile main.cpp
main.o: main.cpp RentalManager.h AuthenticationManager.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Compile Car.cpp
Car.o: Car.cpp Car.h
	$(CXX) $(CXXFLAGS) -c Car.cpp

# Compile Renter.cpp
Renter.o: Renter.cpp Renter.h
	$(CXX) $(CXXFLAGS) -c Renter.cpp

# Compile RentalManager.cpp
RentalManager.o: RentalManager.cpp RentalManager.h Car.h Renter.h
	$(CXX) $(CXXFLAGS) -c RentalManager.cpp

# Compile User.cpp
User.o: User.cpp User.h
	$(CXX) $(CXXFLAGS) -c User.cpp

# Compile AuthenticationManager.cpp
AuthenticationManager.o: AuthenticationManager.cpp AuthenticationManager.h User.h
	$(CXX) $(CXXFLAGS) -c AuthenticationManager.cpp

# Clean up object files and executable
clean:
	rm -f $(OBJS) $(TARGET)
	@echo "Clean successful!"

# Run the program
run: $(TARGET)
	./$(TARGET)

# Rebuild
rebuild: clean all

.PHONY: all clean run rebuild
