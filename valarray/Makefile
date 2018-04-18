CC = g++

SRC := src
INCLUDE := include

INC = -I $(INCLUDE)

FLAGS ?= -Wall
FLAGS += -pedantic
FLAGS += -std=c++14
FLAGS += -O2

OBJDIR := obj
BINDIR := bin

TARGET = $(BINDIR)/$(notdir $(basename valarray))

SOURCES = $(wildcard $(SRC)/*.cpp)
TMPOBJ = $(patsubst %.cpp, %.o, $(notdir $(SOURCES)))
OBJECTS = $(addprefix $(OBJDIR)/, $(TMPOBJ))

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $(OBJECTS)

build:
	@mkdir -p $(OBJDIR) $(BINDIR)

$(OBJECTS): $(OBJDIR)/%.o: $(SRC)/%.cpp
	$(CC) $(FLAGS) $(INC) -c $< -o $@

full: clean build all

.PHONY: clean build all

clean:
	@echo "Cleaning target and object files..."
	@rm -rf $(TARGET) $(OBJDIR) $(BINDIR)
	@find . -type f -iname "*.gch" -delete

	@echo "All clear!"

.DEFAULT_GOAL := full
