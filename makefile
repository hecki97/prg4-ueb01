# Do not use standard g++ compiler on macOS
ifeq ($(shell uname -s),Darwin)
	CXX = /usr/local/bin/g++-9
else
	CXX = g++
endif

BIN_DIR     = bin
BUILD_DIR   = build
SRC_DIR     = src

SOURCES	 = $(shell find $(SRC_DIR) -name *.cpp)
OBJECTS	 = $(filter-out $(BUILD_DIR)/main.o, $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SOURCES)))

DEBUG     = -O0 -g
CXXFLAGS += $(addprefix -I,$(INCLUDES))
CXXFLAGS += -std=c++2a -Wextra -Wall -pedantic -Werror
CXXFLAGS += $(DEBUG)

# Address sanitizer and undefined behavior sanitizer are not supported on Windows
ifneq ($(OS),Windows_NT)
	CXXFLAGS += -fsanitize=address -fsanitize=undefined
endif

LDFLAGS  +=

.PHONY: clean

all: $(SOURCES) $(BIN_DIR)/main

$(BIN_DIR)/main: $(OBJECTS) $(BUILD_DIR)/main.o
	@mkdir -p $(BIN_DIR)
	@echo "===> LD $@"
	$(CXX) -o $@ $(CXXFLAGS) $(LDFLAGS) $+

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@echo "===> CXX $@"
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@echo "===> CLEAN"
	rm -rf $(BIN_DIR) $(BUILD_DIR)
