/*
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Structure to represent a city
struct City {
    int id;
    double x;
    double y;
};

// Function declarations
double distance(const City& c1, const City& c2);
double calculatePathDistance(const vector<City>& path, const vector<vector<double>>& distances);
vector<vector<City>> permute(const vector<City>& cities);
vector<City> findShortestPath(const vector<City>& cities, const vector<vector<double>>& distances);

// Distance function (can be replaced with actual distance calculation)
double distance(const City& c1, const City& c2) {
    return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

// Function to calculate the total distance of a path
double calculatePathDistance(const vector<City>& path, const vector<vector<double>>& distances) {
    double totalDistance = 0.0;
    for (int i = 0; i < path.size() - 1; ++i) {
        int city1 = path[i].id;
        int city2 = path[i + 1].id;
        totalDistance += distances[city1][city2];
    }
    // Add distance back to starting city
    totalDistance += distances[path[path.size() - 1].id][path[0].id];
    return totalDistance;
}

// Function to generate all permutations of a vector (helper function)
vector<vector<City>> permute(const vector<City>& cities) {
    if (cities.size() == 1) {
        return {cities};
    }
    vector<vector<City>> permutations;
    for (int i = 0; i < cities.size(); ++i) {
        vector<City> remainingCities(cities.begin(), cities.begin() + i);
        remainingCities.insert(remainingCities.end(), cities.begin() + i + 1, cities.end());
        for (const auto& permutation : permute(remainingCities)) {
            vector<City> currentPermutation{cities[i]}; // Create a new vector for each permutation
            currentPermutation.insert(currentPermutation.end(), permutation.begin(), permutation.end());
            permutations.push_back(currentPermutation);
        }
    }
    return permutations;
}

// Function to find the shortest path using brute force
vector<City> findShortestPath(const vector<City>& cities, const vector<vector<double>>& distances) {
    // Generate all permutations of city visits
    vector<vector<City>> permutations = permute(cities);

    // Find the permutation with the minimum total distance
    double minDistance = numeric_limits<double>::max();
    vector<City> shortestPath;
    for (const auto& permutation : permutations) {
        double pathDistance = calculatePathDistance(permutation, distances);
        if (pathDistance < minDistance) {
            minDistance = pathDistance;
            shortestPath = permutation;
        }
    }

    return shortestPath;
}

int main() {
    // Example data (replace with actual city data and distance matrix)
    vector<City> cities = {
        {1, 1.0, 2.0},
        {2, 3.0, 4.0},
        {3, 5.0, 6.0},
        {4, 7.0, 8.0},
    };
    vector<vector<double>> distances = {
        {0.0, 5.0, 8.0, 13.0},
        {5.0, 0.0, 3.0, 9.0},
        {8.0, 3.0, 0.0, 6.0},
        {13.0, 9.0, 6.0, 0.0},
    };

    // Find the shortest path
    vector<City> shortestPath = findShortestPath(cities, distances);

    // Print the shortest path and its distance
    cout << "Shortest path: ";
    for (const auto& city : shortestPath) {
        cout << city.id << " -> ";
    }
    cout << endl;
    cout << "Total distance: " << calculatePathDistance(shortestPath, distances) << endl;

    return 0;
}
*/
#include <iostream>
#include <limits>

#define N 4

int calculateTotalDistance(int route[], int distanceMatrix[N][N]) {
    int totalDistance = 0;
    for (int i = 0; i < N - 1; i++) {
        totalDistance += distanceMatrix[route[i]][route[i + 1]];
    }
    totalDistance += distanceMatrix[route[N - 1]][route[0]];
    return totalDistance;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void permute(int route[], int distanceMatrix[N][N], int start, int end, int &minDistance, int optimalRoute[]) {
    if (start == end) {
        int currentDistance = calculateTotalDistance(route, distanceMatrix);
        if (currentDistance < minDistance) {
            minDistance = currentDistance;
            for (int i = 0; i < N; i++) {
                optimalRoute[i] = route[i];
            }
        }
    } else {
        for (int i = start; i <= end; i++) {
            swap(route[start], route[i]);
            permute(route, distanceMatrix, start + 1, end, minDistance, optimalRoute);
            swap(route[start], route[i]);
        }
    }
}

int main() {
    int distanceMatrix[N][N] = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 5, 0, 30},
        {20, 25, 30, 0}
    };

    int route[N];
    for (int i = 0; i < N; i++) {
        route[i] = i;
    }

    int minDistance = std::numeric_limits<int>::max();
    int optimalRoute[N];

    permute(route, distanceMatrix, 0, N - 1, minDistance, optimalRoute);

    std::cout << "Optimal Route: ";
    for (int i = 0; i < N; i++) {
        std::cout << optimalRoute[i] << " ";
    }

    std::cout << "\nMinimum Distance: " << minDistance << std::endl;

    return 0;
}
