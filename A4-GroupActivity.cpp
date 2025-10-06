/*
Problem Statement:
Given a string expression of numbers and operators, return all possible results from computing all the different possible ways to add parentheses. The valid operators are +, - and *.
input:Enter an expression (use +, -, *): 2-1-1

Output:Different results possible: [2, 0]
*/

#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*');
}

// Recursive function to compute all results
int diffWaysToCompute(string expr, int results[]) {
    int count = 0;

    for (int i = 0; i < expr.size(); i++) {
        char c = expr[i];

        // Split at each operator
        if (isOperator(c)) {
            string left = expr.substr(0, i);
            string right = expr.substr(i + 1);

            int leftRes[50], rightRes[50];
            int leftCount = diffWaysToCompute(left, leftRes);
            int rightCount = diffWaysToCompute(right, rightRes);

            // Combine results from left and right subexpressions
            for (int l = 0; l < leftCount; l++) {
                for (int r = 0; r < rightCount; r++) {
                    if (c == '+')
                        results[count++] = leftRes[l] + rightRes[r];
                    else if (c == '-')
                        results[count++] = leftRes[l] - rightRes[r];
                    else if (c == '*')
                        results[count++] = leftRes[l] * rightRes[r];
                }
            }
        }
    }

    // Base case: expression contains only a number
    if (count == 0) {
        results[count++] = stoi(expr);
    }

    return count;
}

// Main function
int main() {
    string expression;
    cout << "Enter an expression (use +, -, *): ";
    cin >> expression;

    int results[100];
    int total = diffWaysToCompute(expression, results);

    cout << "Different results possible: [";
    for (int i = 0; i < total; i++) {
        cout << results[i];
        if (i != total - 1) cout << ", ";
    }
    cout << "]" << endl;

    return 0;
}
