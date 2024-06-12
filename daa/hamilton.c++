#include<iostream>

using namespace std;

const int N = 5; // Change this variable based on the number of vertices in the graph
const int MAX_VERTICES = 10; // Maximum number of vertices

void printSolution(const int path[], int pathSize) {
    for (int i = 0; i < pathSize; i++)
        cout << path[i] << " ";
    cout << path[0] << endl; // End by showing the first vertex to form a cycle
}

bool isSafe(int v, const bool graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos) {
    if (graph[path[pos - 1]][v] == 0)
        return false;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

bool HamiltonianCycleUtil(bool graph[MAX_VERTICES][MAX_VERTICES], int path[], int pos) {
    if (pos == N) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;  // A cycle is formed, return true
        } else {
            return false;
        }
    }

    for (int v = 1; v < N; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;
            if (HamiltonianCycleUtil(graph, path, pos + 1) == true)
                return true;
            path[pos] = -1; // Remove vertex if it doesn't lead to a solution
        }
    }
    return false;
}

bool findHamiltonianCycle(bool graph[MAX_VERTICES][MAX_VERTICES]) {
    int path[MAX_VERTICES];
    for (int i = 0; i < MAX_VERTICES; i++)
        path[i] = -1;

    path[0] = 0; // Start from the first vertex

    if (HamiltonianCycleUtil(graph, path, 1) == false) {
        cout << "Solution does not exist";
        return false;
    }

    printSolution(path, N);
    return true;
}

int main() {
    // Create a graph in the form of an adjacency matrix
    bool graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0},
    };

    findHamiltonianCycle(graph);

    return 0;
}