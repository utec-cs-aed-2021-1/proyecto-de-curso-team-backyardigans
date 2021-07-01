LIBS := ../Graph/

CXX := g++
CXX_GENERIC_FLAGS := -w
CXX_INCLUDE := -I $(LIBS)
CXX_ALL := $(CXX) $(CXX_GENERIC_FLAGS) $(CXX_INCLUDE)

tests-main.o: tests-main.cpp
	$(CXX_ALL) -c tests-main.cpp

build: tests-main.o
	$(CXX_ALL) -o tests.out tests-main.o tests-undirected-graph.cpp 

run: build
	./tests.out
