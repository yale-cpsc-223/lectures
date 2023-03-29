CXX = g++
CXXFLAGS = -std=c++17 -pedantic -Wall -Werror -g

SRCS = $(wildcard *.cpp)
OBJS = $(SRCS:.cpp=.o)
BINS = main

.PHONY: clean all

all: $(BINS)

$(BINS): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(BINS) $(OBJS)
