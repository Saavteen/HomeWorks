#include "Graph.h"
#include <queue>
#include <unordered_map>

//TODO, STUDENTS: Implement this func
void Graph::addEdge(unsigned x, unsigned y)
{
    adjacencyList[x].push_back(y);
    adjacencyList[y].push_back(x);
}

//TODO, STUDENTS: Implement modified BFS algo to return path from start to destination only
//no need to traverse the whole Graph
std::vector<unsigned> Graph::bfs(unsigned start, unsigned destination)
{
    std::vector<bool> visited(adjacencyList.size(), false);
    std::unordered_map<unsigned, unsigned> parent; // Для відстеження шляху
    std::queue<unsigned> queue;

    visited[start] = true;
    queue.push(start);

    while (!queue.empty())
    {
        unsigned current = queue.front();
        queue.pop();

        if (current == destination)
        {
            std::vector<unsigned> path;
            for (unsigned v = destination; v != start; v = parent[v])
            {
                path.push_back(v);
            }
            path.push_back(start);
            std::reverse(path.begin(), path.end());
            return path;
        }

        for (unsigned neighbor : adjacencyList[current])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = current;
                queue.push(neighbor);
            }
        }
    }

    return {}; // Return an empty path if no path is found
}