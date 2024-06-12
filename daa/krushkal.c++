#include <iostream>
#include <algorithm>

const int MAX_VERTICES = 100; // Maximum number of vertices
const int MAX_EDGES = 1000; // Maximum number of edges

// Edge structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// Comparator function to sort edges based on weight
bool compareEdges(const Edge& e1, const Edge& e2) {
    return e1.weight < e2.weight;
}

// Function to find the parent of a node
int findParent(int parent[], int node) {
    if (parent[node] == -1)
        return node;
    return parent[node] = findParent(parent, parent[node]);
}

// Function to union two sets
void unionSets(int parent[], int rank[], int x, int y) {
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);

    if (rank[xRoot] < rank[yRoot])
        parent[xRoot] = yRoot;
    else if (rank[xRoot] > rank[yRoot])
        parent[yRoot] = xRoot;
    else {
        parent[yRoot] = xRoot;
        rank[xRoot]++;
    }
}

// Kruskal's algorithm to find the Minimum Spanning Tree (MST)
void kruskalMST(Edge edges[], int numEdges, int numVertices) {
    Edge mst[MAX_VERTICES - 1]; // MST edges
    int mstSize = 0; // Number of edges in the MST
    int totalWeight = 0; // Total weight of the MST

    // Sort the edges in non-decreasing order of weight
    std::sort(edges, edges + numEdges, compareEdges);

    int parent[MAX_VERTICES];
    int rank[MAX_VERTICES];

    // Initialize parent and rank arrays
    for (int i = 0; i < MAX_VERTICES; i++) {
        parent[i] = -1;
        rank[i] = 0;
    }

    // Iterate through all edges
    for (int i = 0; i < numEdges && mstSize < numVertices - 1; i++) {
        int srcRoot = findParent(parent, edges[i].src);
        int destRoot = findParent(parent, edges[i].dest);

        // If the edges don't form a cycle, add it to the MST
        if (srcRoot != destRoot) {
            mst[mstSize++] = edges[i];
            totalWeight += edges[i].weight;
            unionSets(parent, rank, srcRoot, destRoot);
        }
    }

    // Print the Minimum Spanning Tree
    std::cout << "Edges in the Minimum Spanning Tree:" << std::endl;
    for (int i = 0; i < mstSize; i++) {
        std::cout << mst[i].src << " -- " << mst[i].dest << " (weight: " << mst[i].weight << ")" << std::endl;
    }
    std::cout << "Total weight of the Minimum Spanning Tree: " << totalWeight << std::endl;
}

int main() {
    int numVertices, numEdges;
    std::cout << "Enter the number of vertices: ";
    std::cin >> numVertices;
    std::cout << "Enter the number of edges: ";
    std::cin >> numEdges;

    Edge edges[MAX_EDGES];
    std::cout << "Enter the edges (source, destination, weight):" << std::endl;
    for (int i = 0; i < numEdges; i++) {
        std::cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    kruskalMST(edges, numEdges, numVertices);

    return 0;
}