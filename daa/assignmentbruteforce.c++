#include <iostream>
#include <climits> 

using namespace std;
int minCost(int cost[4][4], int n) {
  
  if (n == 1) {
    return cost[0][0];
  }
  int min_cost = INT_MAX;
  for (int i = 0; i < n; i++) {
 
    int rec_cost = cost[i][0] + minCost(cost, n - 1);

    // If the recursive cost is smaller than current min cost, update it
    if (rec_cost < min_cost) {
      min_cost = rec_cost;
    }
  }

  return min_cost;
}

int main() {
  int cost[4][4] = {{9, 2, 7, 8},
                   {6, 4, 3, 7},
                   {5, 8, 1, 8},
                   {7, 6, 9, 4}};
  int n = 4;

  cout << "Minimum cost using Brute Force: " << minCost(cost, n) << endl;

  return 0;
}
