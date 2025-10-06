/*
Statement:
Given an integer array coins[] of size N representing different denominations and an integer sum, find the number of ways to make the given sum using different combinations of coins.

Input:
Enter number of coins: 3
Enter coin values: 1 2 3
Enter total sum: 4

Ouput:
Number of ways to make sum: 4

*/

#include <iostream>
using namespace std;

int countWays(int coins[], int n, int sum) {
    int dp[100][100] = {0};  // dp[i][j] = number of ways to make sum j using first i coins

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;  // 1 way to make sum 0 (no coins)

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (coins[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    int coins[100];

    cout << "Enter number of coins: ";
    cin >> n;

    cout << "Enter coin values: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter total sum: ";
    cin >> sum;

    cout << "Number of ways to make sum: " << countWays(coins, n, sum) << endl;
    return 0;
}
