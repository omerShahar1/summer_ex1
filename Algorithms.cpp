//omer shahar
//207689621
//omerzshahar@gmail.com

#include "Algorithms.hpp"

using namespace std;
using namespace ariel;

// Helper function for DFS in isContainsCycle
bool dfsCycle(size_t v, const Graph& g, vector<bool>& visited, vector<int>& parent) {
    visited[v] = true;
    for (size_t u = 0; u < g.getMatrix().size(); u++) {
        if (g.getMatrix()[v][u] != 0) {
            if (!visited[u]) {
                parent[u] = v;
                if (dfsCycle(u, g, visited, parent)) {
                    return true;
                }
            } else if (parent[v] != u) {
                return true; // back edge found, cycle exists
            }
        }
    }
    return false;
}

int Algorithms::isContainsCycle(const Graph& g) {
    //Purpose: Checks if the graph contains any cycles.
    //How it works: Utilizes Depth-First Search (DFS) to detect cycles. 
    //If a vertex is revisited (that is not the direct parent), a cycle is detected.

    size_t n = g.getMatrix().size();
    vector<bool> visited(n, false);
    vector<int> parent(n, -1);

    for (size_t v = 0; v < n; v++) {
        if (!visited[v]) {
            if (dfsCycle(v, g, visited, parent)) {
                return 1;
            }
        }
    }
    return 0;
}

string Algorithms::isBipartite(const Graph& g) {
    //Purpose: Determines if the graph can be colored using two colors without adjacent nodes 
    //having the same color, which would indicate the graph is bipartite.
    //How it works: Employs BFS to attempt to color the graph using two colors. 
    //If adjacent vertices end up with the same color, the graph is not bipartite.
size_t n = g.V_size();
vector<int> colors(n, -1); // -1 means uncolored
vector<int> setA, setB;

    for (size_t start = 0; start < n; ++start) {
        if (colors[start] == -1) {
            queue<int> q;
            q.push(start);
            colors[start] = 0; // color the first node with color 0
            setA.push_back(start);

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (size_t neighbor = 0; neighbor < n; ++neighbor) {
                    if (g.getMatrix()[size_t(node)][neighbor] != 0) { // there's an edge
                        if (colors[neighbor] == -1) {
                            colors[neighbor] = 1 - colors[size_t(node)]; // color with opposite color
                            if (colors[neighbor] == 0) {
                                setA.push_back(neighbor);
                            } else {
                                setB.push_back(neighbor);
                            }
                            q.push(neighbor);
                        } else if (colors[neighbor] == colors[size_t(node)]) {
                            return "0"; // not bipartite
                        }
                    }
                }
            }
        }
    }

    // Constructing the output string
    string result = "A={";
    for (size_t i = 0; i < setA.size(); ++i) {
        result += to_string(setA[i]);
        if (i < setA.size() - 1) {
            result += ", ";
        }
    }
    result += "}, B={";
    for (size_t i = 0; i < setB.size(); ++i) {
        result += to_string(setB[i]);
        if (i < setB.size() - 1) {
            result += ", ";
        }
    }
    result += "}";

    return result;
}


int Algorithms::isConnected(const Graph& g) 
{
    //Purpose: Determines whether all vertices in the graph are connected.
    //How it works: Uses a Breadth-First Search (BFS) to traverse the graph from a starting vertex, 
    //marking all reachable vertices. It checks if all vertices have been visited to determine connectivity.

    size_t n = g.getMatrix().size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (size_t i = 0; i < n; i++) {
            if (g.getMatrix()[size_t(node)][i] != 0 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }

    for (bool v : visited) {
        if (!v) return 0;
    }
    return 1;
}

string Algorithms::shortestPath(const Graph& graph, size_t start, size_t end) {

    //Purpose: Finds the shortest path between two vertices in the graph.
    //How it works: Uses Dijkstra’s algorithm 
    //to compute the shortest path from the start vertex to the end vertex. 
    //The path is reconstructed and returned as a string.

        const vector<vector<int>> &mat = graph.getMatrix();
        size_t graph_size = mat.size();
        vector<vector<int>> adjacencyMatrix = graph.getMatrix();

        
        if(start >= graph_size || end >= graph_size)
        {
            return "start or end invalid";
        }

        
        vector<int> dist (graph_size,-1);
        vector<size_t> prev(graph_size,SIZE_MAX);
        queue<size_t> queue;
        queue.push(start);
        dist[start]=0;

        while (!queue.empty())
        {
            size_t current = queue.front();
            queue.pop();


            for(size_t neighbor = 0; neighbor< graph_size;neighbor++){
                if (adjacencyMatrix[current][neighbor]!=0)
                {
                    if (dist[neighbor]==-1)
                    {
                        dist[neighbor]=dist[current]+1;
                        prev[neighbor]=current;
                        queue.push(neighbor);
                    }
                }
            }
        }
        if(dist[end]==-1)
            return "-1";

        string answer = to_string(end);
        size_t current = end;
        while (current!=start)
        {
            current=prev[current];
            answer= to_string(current) + "->" + answer;
        }
        return answer;
    
}

string Algorithms::negativeCycle(const Graph& g) {
    // Purpose: Identifies if there is any cycle in the graph where the total weight is negative.
    //How it works: Applies the Bellman-Ford algorithm, which iteratively relaxes edges; if any edge can still be relaxed after N-1 iterations
    // (where N is the number of vertices), a negative cycle exists.

    
    size_t n = g.V_size();
    vector<int> dist(n, 0);

    for (size_t k = 0; k < n; ++k) {
        for (size_t u = 0; u < n; ++u) {
            for (size_t v = 0; v < n; ++v) {
                if (g.getMatrix()[u][v] != 0 && dist[u] + g.getMatrix()[u][v] < dist[v]) {
                    dist[v] = dist[u] + g.getMatrix()[u][v];
                    if (k == n - 1) {
                        return "Graph contains a negative cycle";
                    }
                }
            }
        }
    }
    return "Graph does not contain a negative cycle";

}
