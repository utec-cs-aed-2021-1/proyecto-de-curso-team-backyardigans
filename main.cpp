#include <iostream>

#include "Tester/tester.h"
//#include "Parser/parser.h"
#include "graph.h"
#include "DirectedGraph.h"
using namespace std;

int main(int argc, char *argv[]) {
    std::cout << "================================================" << std::endl;
    std::cout << "MENU GRAPH TESTER" << std::endl;
    std::cout << "================================================" << std::endl;
    test_undirected_graph();




    //Tester::executeExamples();
    //Tester::executeParser();
    
    return EXIT_SUCCESS;
}