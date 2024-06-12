#include <iostream>
#include <climits>

const int MAX_VERTICES = 100; // Maximum number of vertices

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[], int V) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

// Function to print the constructed Minimum Spanning Tree (MST)
void printMST(int parent[], int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    std::cout << "Edge \tWeight\n";
    for (int i = 1; i < V; i++)
        std::cout << parent[i] << " - " << i << "\t" << graph[i][parent[i]] << "\n";
}

// Prim's algorithm to construct the Minimum Spanning Tree (MST)
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int V) {
    int parent[MAX_VERTICES]; // Array to store the MST
    int key[MAX_VERTICES];    // Key values used to pick minimum weight edge
    bool mstSet[MAX_VERTICES]; // To represent set of vertices included in MST

    // Initialize all keys as INFINITE
    for (int i = 0; i < V; i++)
        key[i] = INT_MAX, mstSet[i] = false;

    // Always include the first vertex in the MST
    key[0] = 0;
    parent[0] = -1; // First node is always the root

    // The MST will have V-1 edges
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum key vertex from the set of vertices not yet included in MST
        int u = minKey(key, mstSet, V);

        // Add the picked vertex to the MST set
        mstSet[u] = true;

        // Update key value and parent index of adjacent vertices of the picked vertex.
        // Consider only those vertices that are not yet included in MST
        for (int v = 0; v < V; v++)
            // graph[u][v] is non-zero only for adjacent vertices of u
            // mstSet[v] is false for vertices not yet included in MST
            // Update the key only if graph[u][v] is smaller than key[v]
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    // Print the constructed MST
    printMST(parent, graph, V);
}

int main() {
    int V; // Number of vertices
    std::cout << "Enter the number of vertices: ";
    std::cin >> V;

    int graph[MAX_VERTICES][MAX_VERTICES];

    std::cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            std::cin >> graph[i][j];

    primMST(graph, V);

    return 0;
}