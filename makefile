CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -O2 -I.
LDLIBS = -lws2_32
TARGET = main
TARGET_DEL = main.exe
SRCS = main.cpp
all: $(TARGET) run
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDLIBS)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@
run: $(TARGET)
	$(TARGET)
clean:
	del $(TARGET_DEL) $(OBJS)
	del $(TARGET_DEL) $(OBJS)
