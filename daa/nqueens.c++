#include <iostream>
#include <cmath>

const int MAX_SIZE = 100; // Maximum board size

// Class to solve N-Queens problem
class NQueenSolver {
private:
    int n;
    int positions[MAX_SIZE];

public:
    NQueenSolver(int n) : n(n) {
        // Initialize positions with -1
        for (int i = 0; i < n; i++) {
            positions[i] = -1;
        }
    }

    // Function to check if the position is safe
    bool IsSafe(int k, int i) {
        for (int j = 0; j < k; j++) {
            if (positions[j] == i || // Check same column
                std::abs(positions[j] - i) == std::abs(j - k)) // Check diagonals
                return false;
        }
        return true;
    }

    // The main recursive function to solve N-Queens problem
    void PlaceQueens(int k) {
        for (int i = 0; i < n; i++) {
            if (IsSafe(k, i)) {
                positions[k] = i; // Place queen
                if (k == n - 1) {
                    PrintSolution(); // All queens placed
                } else {
                    PlaceQueens(k + 1); // Solve for next position
                }
                positions[k] = -1; // Backtrack
            }
        }
    }

    // Utility to print one of the solutions
    void PrintSolution() {
        for (int i = 0; i < n; i++) {
            std::cout << "Queen at: Row " << i << ", Col " << positions[i] << std::endl;
        }
        std::cout << "---" << std::endl; // Just for a clearer output
    }
};

int main() {
    int n ;
    std :: cout<<"Enter the value of N\n";
	std::cin >>n; // You can set this to any number
    NQueenSolver solver(n);
    std::cout << "Placing " << n << " Queens on a " << n << "x" << n << " chess board." << std::endl;
    solver.PlaceQueens(0); // Start placing queens from the first row
    return 0;
}