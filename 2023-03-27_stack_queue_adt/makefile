CXX = g++
CXXFLAGS = -std=c++17 -pedantic -Wall -Werror -g

LS_SRCS=linked_stack.cpp
LQ_SRCS=linked_queue.cpp
CQ_SRCS=circular_queue.cpp

LS_OBJS=$(LS_SRCS:.cpp=.o)
LQ_OBJS=$(LQ_SRCS:.cpp=.o)
CQ_OBJS=$(CQ_SRCS:.cpp=.o)

BINS = main_ls main_lq main_cq parser

.PHONY: clean all

all: $(BINS)

main_ls: main_ls.o $(LS_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main_lq: main_lq.o $(LQ_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main_cq: main_cq.o $(CQ_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

parser: parser.o $(LS_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	$(RM) $(BINS) *.o

