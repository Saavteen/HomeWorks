#pragma once
#include <vector>

class Graph {
public:
    Graph(unsigned numVertices)
    {
        adjacencyList.resize(numVertices);
    }


    //TODO, STUDENTS: Implement this func
    void addEdge(unsigned x, unsigned y);

    //TODO, STUDNETS: Implement modified BFS algo to return path from start to destination only
    //no need to traverse the whole Graph
    std::vector<unsigned> bfs(unsigned start, unsigned destination);

private:
    std::vector<std::vector<unsigned>> adjacencyList;
};
