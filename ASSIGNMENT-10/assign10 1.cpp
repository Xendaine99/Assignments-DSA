#include <iostream>
#include <list>
#include <queue>
#include <stack>

class Graph {
private:
    int vertices;
    std::list<int>* adjacencyList;

public:
    Graph(int V);
    void addEdge(int v, int w);
    void BFS(int startVertex);
    void DFS(int startVertex);
    void DFSUtil(int vertex, bool visited[]);
};

Graph::Graph(int V) {
    this->vertices = V;
    adjacencyList = new std::list<int>[V];
}

void Graph::addEdge(int v, int w) {
    adjacencyList[v].push_back(w);
}

void Graph::BFS(int startVertex) {
    std::queue<int> queue;
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    visited[startVertex] = true;
    queue.push(startVertex);

    while (!queue.empty()) {
        startVertex = queue.front();
        std::cout << startVertex << " ";
        queue.pop();

        for (auto i = adjacencyList[startVertex].begin(); i != adjacencyList[startVertex].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push(*i);
            }
        }
    }

    delete[] visited;
}

void Graph::DFSUtil(int vertex, bool visited[]) {
    visited[vertex] = true;
    std::cout << vertex << " ";

    for (auto i = adjacencyList[vertex].begin(); i != adjacencyList[vertex].end(); ++i) {
        if (!visited[*i]) {
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS(int startVertex) {
    bool* visited = new bool[vertices];
    for (int i = 0; i < vertices; i++) {
        visited[i] = false;
    }

    DFSUtil(startVertex, visited);

    delete[] visited;
}

int main() {
    Graph g(6);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 4);
    g.addEdge(3, 5);
    g.addEdge(4, 5);

    std::cout << "BFS traversal starting from vertex 0: ";
    g.BFS(0);

    std::cout << "\nDFS traversal starting from vertex 0: ";
    g.DFS(0);

    return 0;
}
