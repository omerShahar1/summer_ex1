//omer shahar
//207689621
//omerzshahar@gmail.com

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
namespace ariel 
{
    class Graph {

    private:
        std::vector<std::vector<int>> adjMatrix;


    public:
        
        Graph(); 
        ~Graph(); 

        void loadGraph(const std::vector<std::vector<int>>& matrix);
        void printGraph() const;
        size_t V_size() const;
        vector<vector<int>> getMatrix() const;

        // אופרטורים חשבוניים
        Graph operator+(const Graph& other) const;
      
        Graph& operator+=(const Graph& other);
        Graph operator-() const; // פלוס אונרי
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);

        // אופרטורי השוואה
        bool operator==(const Graph& other) const;
        bool operator!=(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator>=(const Graph& other) const;

        // אופרטורים להגדלה/הקטנה
        Graph& operator++(); // prefix
        Graph operator++(int); // postfix
        Graph& operator--(); // prefix
        Graph operator--(int); // postfix

        // הכפלה בסקלר
        void operator*(int);
        Graph operator*(int) const;
        void operator*=(int);
        void operator/=(int);

        // כפל מטריצות (גרפים)
        Graph operator*(const Graph& other) const;



        // אופרטור פלט
        friend ostream& operator<<(ostream& os, const Graph&);
    };
}

#endif // GRAPH_HPP
