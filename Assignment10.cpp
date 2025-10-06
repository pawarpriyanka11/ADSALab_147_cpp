/*Statement:
Implement Subset Sum Problem. Statement:-Given a set of nonnegative integers and a value sum, the task is to check if there is a
subset of the given set whose sum is equal to the given sum.

Input:Enter number of elements: 5
Enter elements: 2 3 7 8 10
Enter target sum: 11

Ouput:Subset with given sum exists.

*/
#include <iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    bool dp[100][100] = {false};

    for (int i = 0; i <= n; i++)
        dp[i][0] = true;  // sum = 0 is always possible (empty subset)

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[n][sum];
}

int main() {
    int n, sum;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target sum: ";
    cin >> sum;

    if (isSubsetSum(arr, n, sum))
        cout << "Subset with given sum exists." << endl;
    else
        cout << "No subset with given sum exists." << endl;

    return 0;
}
