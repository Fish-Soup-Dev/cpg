CXX = g++
#CXX=aarch64-linux-gnu-g++

BUILD ?= DEBUG
CFLAGS = -std=c++20 -static
LIBS =
DEFS = 

SRCS = $(wildcard src/*.cpp)
SLIBS = $(wildcard lib/*.a)
INCDIR = ./include
SLIBDIR = ./lib
OBJDIR = ./obj/$(BUILD)
BINDIR = ./bin/$(BUILD)

OBJS = $(patsubst %.cpp, $(OBJDIR)/%.o, $(notdir $(SRCS)))

ifeq ($(OS),Windows_NT)
    MAIN = $(BINDIR)/cpg.exe
else
    MAIN = $(BINDIR)/cpg
endif

ifeq ($(BUILD),DEBUG)
    CFLAGS += -g -Wall -DDEBUG
else ifeq ($(BUILD),RELEASE)
    CFLAGS += -O2 -DNDEBUG
endif

all: $(MAIN)

$(MAIN): $(OBJS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CFLAGS) -o $@ $^ $(addprefix -I, $(INCDIR)) $(addprefix -L, $(SLIBDIR)) $(SLIBS) $(addprefix -D, $(DEFS)) $(LIBS)

$(OBJDIR)/%.o: src/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CFLAGS) -c -o $@ $< $(addprefix -D, $(DEFS)) $(addprefix -I, $(INCDIR))

clean:
	rm -rf ./obj ./bin

run: $(MAIN)
	$(MAIN)

debug: 
	@$(MAKE) BUILD=DEBUG

release:
	@$(MAKE) BUILD=RELEASE