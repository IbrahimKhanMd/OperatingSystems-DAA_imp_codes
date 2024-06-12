#include<iostream>
#include <bits/stdc++.h> 
using namespace std; 
  
int max(int a, int b) { return (a > b) ? a : b; } 

int knapSack(int W, int wt[], int val[], int n) 
{ 
    if (n == 0 || W == 0) 
        return 0; 
    if (wt[n - 1] > W) 
        return knapSack(W, wt, val, n - 1); 
    else
        return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),  knapSack(W, wt, val, n - 1)); 
} 

int main() 
{ 
    int x;
    cout << "Enter number of items: ";
    cin >> x;
    int profit[x]; 
    int weight[x]; 
    cout << "Enter profit of items: ";
    for(int i = 0; i < x; i++) {
        cin >> profit[i];
    }
    cout << "Enter weights of items: ";
    for(int i = 0; i < x; i++) {
        cin >> weight[i];
    }
    int W; 
    cout << "Enter capacity of knapsack: ";
    cin >> W;
    int n = sizeof(profit) / sizeof(profit[0]); 
    cout << knapSack(W, weight, profit, n) << endl; 
    return 0; 
}
