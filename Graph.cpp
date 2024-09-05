//omer shahar
//207689621
//omerzshahar@gmail.com

#include "Graph.hpp"

using namespace std;

namespace ariel {

    Graph::Graph() {}
    Graph::~Graph() {}

        // פעולה לטעינת הגרף ממטריצת שכנויות
        void Graph::loadGraph(const std::vector<std::vector<int>>& matrix) {
            int n = matrix.size();
            for (const auto& row : matrix) {
                if (row.size() != n) {
                    throw std::invalid_argument("Matrix must be square");
                }
            }
            adjMatrix = matrix;
        }

        // פעולה להדפסת הגרף
        void Graph::printGraph() const {
            for (const auto& row : adjMatrix) {
                for (int val : row) {
                    std::cout << val << " ";
                }
                std::cout << std::endl;
            }
        }

        size_t Graph::V_size() const// return the size of the graph (מספר הקודקודים)
        {
            return adjMatrix.size();
        }

        vector<vector<int>> Graph::getMatrix() const//מחזיר קישור שאין לשנות אותו לגרף
        {
            return adjMatrix;
        }

        // אופרטורים חשבוניים
        Graph Graph::operator+(const Graph& other) const {
            if (adjMatrix.size() != other.adjMatrix.size()) {
                throw std::invalid_argument("Graphs must have the same size for addition");
            }
            Graph result = *this;
            for (size_t i = 0; i < adjMatrix.size(); i++) {
                for (size_t j = 0; j < adjMatrix[i].size(); j++) {
                    result.adjMatrix[i][j] += other.adjMatrix[i][j];
                }
            }
            return result;
        }

        Graph& Graph::operator+=(const Graph& other) {
            *this = *this + other;
            return *this;
        }

        Graph Graph::operator-() const {
            Graph result = *this;
            for (size_t i = 0; i < adjMatrix.size(); i++) {
                for (size_t j = 0; j < adjMatrix[i].size(); j++) {
                    result.adjMatrix[i][j] = -result.adjMatrix[i][j];
                }
            }
            return result;
        }

        Graph Graph::operator-(const Graph& other) const {
            return *this + (-other);
        }

        Graph& Graph::operator-=(const Graph& other) {
            *this = *this - other;
            return *this;
        }

        // אופרטורים להשוואת גרפים
        bool Graph::operator==(const Graph& other) const {
            return adjMatrix == other.adjMatrix;
        }

        bool Graph::operator!=(const Graph& other) const {
            return !(*this == other);
        }

        bool Graph::operator<(const Graph& other) const {
            return adjMatrix.size() < other.adjMatrix.size();
        }

        bool Graph::operator<=(const Graph& other) const {
            return adjMatrix.size() <= other.adjMatrix.size();
        }

        bool Graph::operator>(const Graph& other) const {
            return adjMatrix.size() > other.adjMatrix.size();
        }

        bool Graph::operator>=(const Graph& other) const {
            return adjMatrix.size() >= other.adjMatrix.size();
        }

        // אופרטורים להגדלה והקטנה ב-1
        Graph& Graph::operator++() {
            for (auto& row : adjMatrix) {
                for (auto& val : row) {
                    val++;
                }
            }
            return *this;
        }

        Graph Graph::operator++(int) {
            Graph temp = *this;
            ++(*this);
            return temp;
        }

        Graph& Graph::operator--() {
            for (auto& row : adjMatrix) {
                for (auto& val : row) {
                    val--;
                }
            }
            return *this;
        }

        Graph Graph::operator--(int) {
            Graph temp = *this;
            --(*this);
            return temp;
        }

        // אופרטור להכפלה בסקלר
        Graph Graph::operator*(int scalar) const {
            Graph result = *this;
            for (auto& row : result.adjMatrix) {
                for (auto& val : row) {
                    val *= scalar;
                }
            }
            return result;
        }

        void Graph::operator*=(int num) {
            for (auto& row : adjMatrix) {
                for (auto& val : row) {
                    val *= num;
                }
            }
        }

        void Graph::operator/=(int num) {
            if (num == 0) {
                throw std::invalid_argument("Division by zero is not allowed.");
            }
            for (auto& row : adjMatrix) {
                for (auto& val : row) {
                    val /= num;
                }
            }
        }

        // אופרטור להכפלת גרפים
        Graph Graph::operator*(const Graph& other) const {
            if (adjMatrix.size() != other.adjMatrix.size()) {
                throw std::invalid_argument("Graphs must have the same size for multiplication");
            }
            Graph result;
            size_t n = adjMatrix.size();
            result.adjMatrix.resize(n, std::vector<int>(n, 0));

            for (size_t i = 0; i < n; i++) {
                for (size_t j = 0; j < n; j++) {
                    for (size_t k = 0; k < n; k++) {
                        result.adjMatrix[i][j] += adjMatrix[i][k] * other.adjMatrix[k][j];
                    }
                }
            }
            return result;
        }

        // אופרטור פלט
        ostream& operator<<(ostream& os, const Graph& g) {
            for (const auto& row : g.adjMatrix) {
                for (const auto& val : row) {
                    os << val << " ";
                }
                os << std::endl;
            }
            return os;
        }
}

