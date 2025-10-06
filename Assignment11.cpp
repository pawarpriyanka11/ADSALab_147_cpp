/*Implement Check if it is possible to transform one string to another.
Statement: - Given two strings s1 and s2 (all letters in uppercase).
Check if it is possible to convert s1 to s2 by performing following
operations. 1. Make some lowercase letters upper. 2. Delete all the
lowercase letters

Input: 
Enter string s1: daBcd
Enter string s2: ABC

Output: 
YES, transformation is possible.

*/

#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

bool canTransform(string s1, string s2) {
    int n = s1.length();
    int m = s2.length();

    bool dp[105][105]; // assuming strings length <= 100
    memset(dp, false, sizeof(dp));

    dp[0][0] = true;

    // If s2 is empty, we can only delete lowercase letters from s1
    for (int i = 1; i <= n; i++) {
        if (islower(s1[i - 1]))
            dp[i][0] = true;
        else
            dp[i][0] = false;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (toupper(s1[i - 1]) == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] || (islower(s1[i - 1]) && dp[i - 1][j]);
            }
            else if (isupper(s1[i - 1])) {
                dp[i][j] = false; // can't delete uppercase
            }
            else {
                dp[i][j] = dp[i - 1][j]; // delete lowercase
            }
        }
    }

    return dp[n][m];
}

int main() {
    string s1, s2;
    cout << "Enter string s1: ";
    cin >> s1;
    cout << "Enter string s2: ";
    cin >> s2;

    if (canTransform(s1, s2))
        cout << "YES, transformation is possible." << endl;
    else
        cout << "NO, transformation is not possible." << endl;

    return 0;
}
