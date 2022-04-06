LIBS := ../Graph/

TESTS_SRC := $(shell find . -type f -name '*.cpp')
TESTS_OUT := ./tests.out

CXX := g++
CXX_GENERIC_FLAGS := -w
CXX_INCLUDE := -I $(LIBS)
CXX_ALL := $(CXX) $(CXX_GENERIC_FLAGS) $(CXX_INCLUDE)

tests-main.o: tests-main.cpp
	$(CXX_ALL) -c tests-main.cpp

./%.o: ./%.cpp
	$(CXX_ALL) -c -o $@ $<

build: $(patsubst %.cpp,%.o,$(TESTS_SRC))
	$(CXX_ALL) -o $(TESTS_OUT) $^

run: build 
	$(TESTS_OUT)
