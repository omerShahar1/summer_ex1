//omer shahar
//207689621
//omerzshahar@gmail.com

#include <iostream>
#include "Graph.hpp"
#include "Algorithms.hpp"

using namespace ariel;

void testIsConnected() {
    Graph g1;
    g1.loadGraph({
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
    });
    std::cout << "Test isConnected (should return 1): " << Algorithms::isConnected(g1) << std::endl;

    Graph g2;
    g2.loadGraph({
        {0, 1, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 1},
        {0, 0, 1, 0}
    });
    std::cout << "Test isConnected (should return 0): " << Algorithms::isConnected(g2) << std::endl;
}

void testShortestPath() {
    Graph g;
    g.loadGraph({
        {0, 10, 0, 0, 5},
        {0, 0, 1, 0, 2},
        {0, 0, 0, 4, 0},
        {7, 0, 6, 0, 0},
        {0, 3, 9, 2, 0}
    });

    std::cout << "Test shortestPath (should return '0->4->3'): " << Algorithms::shortestPath(g, 0, 3) << std::endl;

    Graph g2;
    g2.loadGraph({
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    });
    std::cout << "Test shortestPath (should return '0'): " << Algorithms::shortestPath(g2, 0, 2) << std::endl;
}

void testIsBipartite() {
    Graph g1;
    g1.loadGraph({
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    });
    std::cout << "Test isBipartite (should return 'A={0, 2}, B={1}'): " << Algorithms::isBipartite(g1) << std::endl;

    Graph g2;
    g2.loadGraph({
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    });
    std::cout << "Test isBipartite (should return '0'): " << Algorithms::isBipartite(g2) << std::endl;
}

void testIsContainsCycle() {
    Graph g1;
    g1.loadGraph({
        {0, 1, 0, 0},
        {1, 0, 1, 1},
        {0, 1, 0, 0},
        {0, 1, 0, 0}
    });
    std::cout << "Test isContainsCycle (should return 0): " << Algorithms::isContainsCycle(g1) << std::endl;

    Graph g2;
    g2.loadGraph({
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    });
    std::cout << "Test isContainsCycle (should print a cycle): " << Algorithms::isContainsCycle(g2) << std::endl;
}

void testNegativeCycle() {
    Graph g1;
    g1.loadGraph({
        {0, -1, 4, 0},
        {0, 0, 3, 2},
        {0, 0, 0, 0},
        {0, 1, 5, 0}
    });
    std::cout << "Test negativeCycle (should print no negative cycle):" << std::endl;
    Algorithms::negativeCycle(g1);

    Graph g2;
    g2.loadGraph({
        {0, 1, 0},
        {0, 0, 2},
        {0, -3, 0}
    });
    std::cout << "Test negativeCycle (should find a negative cycle):" << std::endl;
    Algorithms::negativeCycle(g2);
}









//////////////graph test///////////

void testLoadAndPrintGraph() {
    Graph g;
    g.loadGraph({
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    });

    std::cout << "Test Load and Print Graph (should return adjacency matrix):" << std::endl;
    g.printGraph();
}

void testGraphAddition() {
    Graph g1, g2;
    g1.loadGraph({
        {1, 2},
        {3, 4}
    });
    g2.loadGraph({
        {2, 3},
        {4, 5}
    });

    Graph g3 = g1 + g2;

    std::cout << "Test Graph Addition (should return 3, 5, 7, 9):" << std::endl;
    g3.printGraph();
}

void testGraphSubtraction() {
    Graph g1, g2;
    g1.loadGraph({
        {5, 7},
        {9, 11}
    });
    g2.loadGraph({
        {2, 3},
        {4, 5}
    });

    Graph g3 = g1 - g2;

    std::cout << "Test Graph Subtraction (should return 3, 4, 5, 6):" << std::endl;
    g3.printGraph();
}

void testGraphMultiplication() {
    Graph g1, g2;
    g1.loadGraph({
        {1, 2},
        {3, 4}
    });
    g2.loadGraph({
        {2, 0},
        {1, 2}
    });

    Graph g3 = g1 * g2;

    std::cout << "Test Graph Multiplication (should return 4, 4, 10, 8):" << std::endl;
    g3.printGraph();
}

void testGraphEquality() {
    Graph g1, g2, g3;
    g1.loadGraph({
        {1, 2},
        {3, 4}
    });
    g2.loadGraph({
        {1, 2},
        {3, 4}
    });
    g3.loadGraph({
        {2, 3},
        {4, 5}
    });

    std::cout << "Test Graph Equality (g1 == g2, g1 != g3):" << std::endl;
    std::cout << "g1 == g2: " << (g1 == g2 ? "True" : "False") << std::endl;
    std::cout << "g1 != g3: " << (g1 != g3 ? "True" : "False") << std::endl;
}

void testGraphComparison() {
    Graph g1, g2, g3;
    g1.loadGraph({
        {1, 0},
        {0, 1}
    });
    g2.loadGraph({
        {1, 1},
        {1, 1}
    });
    g3.loadGraph({
        {1, 1, 1},
        {1, 1, 1},
        {1, 1, 1}
    });

    std::cout << "Test Graph Comparison (g1 < g2 < g3):" << std::endl;
    std::cout << "g1 < g2: " << (g1 < g2 ? "True" : "False") << std::endl;
    std::cout << "g2 < g3: " << (g2 < g3 ? "True" : "False") << std::endl;
    std::cout << "g1 <= g2: " << (g1 <= g2 ? "True" : "False") << std::endl;
    std::cout << "g2 > g1: " << (g2 > g1 ? "True" : "False") << std::endl;
    std::cout << "g3 >= g2: " << (g3 >= g2 ? "True" : "False") << std::endl;
}

void testIncrementDecrementOperators() {
    Graph g;
    g.loadGraph({
        {1, 2},
        {3, 4}
    });

    std::cout << "Test Increment (prefix) (++g): " << std::endl;
    ++g;
    g.printGraph();

    std::cout << "Test Increment (postfix) (g++): " << std::endl;
    g++;
    g.printGraph();

    std::cout << "Test Decrement (prefix) (--g): " << std::endl;
    --g;
    g.printGraph();

    std::cout << "Test Decrement (postfix) (g--): " << std::endl;
    g--;
    g.printGraph();
}

void testScalarOperations() {
    Graph g;
    g.loadGraph({
        {1, 2},
        {3, 4}
    });

    std::cout << "Test Scalar Multiplication (g *= 2): " << std::endl;
    g *= 2;
    g.printGraph();

    std::cout << "Test Scalar Division (g /= 2): " << std::endl;
    g /= 2;
    g.printGraph();
}

void testNegationOperator() {
    Graph g;
    g.loadGraph({
        {1, 2},
        {3, 4}
    });

    Graph negG = -g;
    std::cout << "Test Negation Operator (should return -1, -2, -3, -4): " << std::endl;
    negG.printGraph();
}



int main() {
    testLoadAndPrintGraph();
    testIsConnected();
    testShortestPath();
    testIsBipartite();
    testIsContainsCycle();
    testNegativeCycle();
    
    testLoadAndPrintGraph();
    testGraphAddition();
    testGraphSubtraction();
    testGraphMultiplication();
    testGraphEquality();
    testGraphComparison();
    testIncrementDecrementOperators();
    testScalarOperations();
    testNegationOperator();

    return 0;
}
