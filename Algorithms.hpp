//omer shahar
//207689621
//omerzshahar@gmail.com

#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "Graph.hpp"
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <vector>
#include <limits>
using namespace std;
namespace ariel
{
    class Algorithms
    {
        
        public:
            static int isConnected(const Graph&);
            static string shortestPath(const Graph&, size_t, size_t);
            static int isContainsCycle(const Graph&);
            static string isBipartite(const Graph&);
            static string negativeCycle(const Graph&);
    };
}

#endif // ALGORITHMS_HPP
