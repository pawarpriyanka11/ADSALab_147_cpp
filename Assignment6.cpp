/*
Problem Statement:Implement a problem of maximizing Profit by trading stocks based on
given rate per day.
Statement: Given an array arr[] of N positive integers which denotes
the cost of selling and buying stock on each of the N days. The task is
to find the maximum profit that can be earned by buying a stock on or
selling all previously bought stocks on a particular day.


Input: 
Enter number of days: 6
Enter stock prices: 1 2 100 4 5 6

Output:
Maximum Profit: 200*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int prices[100];
    cout << "Enter stock prices: ";
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    int maxProfit = 0;
    int maxPrice = 0;

    // Traverse from last day to first day
    for (int i = n - 1; i >= 0; i--) {
        if (prices[i] > maxPrice)
            maxPrice = prices[i];  // Update maximum future price
        maxProfit += (maxPrice - prices[i]);
    }

    cout << "Maximum Profit: " << maxProfit << endl;
    return 0;
}
