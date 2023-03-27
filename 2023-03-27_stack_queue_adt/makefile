CXX = g++
CXXFLAGS = -std=c++17 -pedantic -Wall -Werror -g

LS_SRCS=linked_stack.cpp
LQ_SRCS=linked_queue.cpp
CQ_SRCS=circular_queue.cpp

LS_OBJS=$(LS_SRCS:.cpp=.o)
LQ_OBJS=$(LQ_SRCS:.cpp=.o)
CQ_OBJS=$(CQ_SRCS:.cpp=.o)

BINS = linked_stack linked_queue circular_queue

.PHONY: clean all

all: $(BINS)

linked_stack: $(LS_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

linked_queue: $(LQ_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

circular_queue: $(CQ_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(S_OBJS) $(Q_OBJS)

