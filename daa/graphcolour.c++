#include <iostream>

const int MAX_VERTICES = 100; // Maximum number of vertices

// Custom vector implementation using static array
template <typename T>
class Vector {
private:
    T arr[MAX_VERTICES];
    int size;

public:
    Vector() : size(0) {}

    void push_back(const T& value) {
        arr[size++] = value;
    }

    T& operator[](int index) {
        return arr[index];
    }

    int getSize() const {
        return size;
    }
};

class GraphColoring {
private:
    int n; // Number of vertices
    int m; // Number of colors
    bool G[MAX_VERTICES][MAX_VERTICES]; // Adjacency matrix
    int colors[MAX_VERTICES]; // Colors assigned to vertices

public:
    GraphColoring(int n, int m, const bool graph[MAX_VERTICES][MAX_VERTICES])
        : n(n), m(m) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                G[i][j] = graph[i][j];
            }
        }
        for (int i = 0; i < n; ++i) {
            colors[i] = 0; // Initialize colors to 0
        }
    }

    // Try to assign a valid color to vertex k
    void NextValue(int k) {
        while (true) {
            colors[k] = (colors[k] + 1) % (m + 1); // Next highest color
            if (colors[k] == 0) return; // All colors attempted, backtrack

            int j;
            for (j = 0; j < n; ++j) {
                if (G[k][j] && colors[k] == colors[j]) {
                    // If k and j are adjacent and have the same color
                    break;
                }
            }
            if (j == n) return; // No conflicts, color is valid
        }
    }

    // Recursive function to color the graph
    void mColoring(int k) {
        do {
            NextValue(k);
            if (colors[k] == 0) return; // Backtrack if no color possible
            if (k == n - 1) {
                PrintSolution(); // Print solution if all vertices are colored
            } else {
                mColoring(k + 1); // Color next vertex
            }
        } while (true);
    }

    // Utility function to print current coloring
    void PrintSolution() {
        std::cout << "One of the solutions: ";
        for (int i = 0; i < n; ++i) {
            std::cout << "Vertex " << i + 1 << " -> Color " << colors[i] << ", ";
        }
        std::cout << '\n';
    }
};

int main() {
    int n = 4; // Number of vertices
    int m = 3; // Number of colors

    // Example graph: Adjacency matrix
    bool graph[MAX_VERTICES][MAX_VERTICES] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0}
    };

    GraphColoring solver(n, m, graph);
    std::cout << "Graph Coloring Solutions:" << std::endl;
    solver.mColoring(0); // Start the process from the first vertex

    return 0;
}