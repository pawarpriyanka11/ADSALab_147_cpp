/*Implement a problem of minimum work to be done per day to CO2
finish given tasks within D days problem.
Statement: Given an array task [] of size N denoting amount of work to
be done for each task, the problem is to find the minimum amount of
work to be done on each day so that all the tasks can be completed in
at most D days.
Note: On one day work can be done for only one task

Input:
Enter number of tasks: 5
Enter tasks:  3 1 4 2 2
Enter number of days: 3

Ouput: 
Minimum work per day: 4
*/

#include <iostream>
using namespace std;

bool canFinish(int tasks[], int n, int D, int dailyLimit) {
    int days = 1, current = 0;
    for (int i = 0; i < n; i++) {
        if (tasks[i] > dailyLimit) return false; // single task exceeds daily limit
        if (current + tasks[i] <= dailyLimit)
            current += tasks[i];
        else {
            days++;
            current = tasks[i];
        }
    }
    return days <= D;
}

int main() {
    int n, D;
    cout << "Enter number of tasks: ";
    cin >> n;
    int tasks[100];
    cout << "Enter tasks: ";
    for (int i = 0; i < n; i++)
        cin >> tasks[i];
    cout << "Enter number of days: ";
    cin >> D;

    int left = 0, right = 0;
    for (int i = 0; i < n; i++) right += tasks[i];

    int result = right;

    // Binary search on daily limit
    while (left <= right) {
        int mid = (left + right) / 2;
        if (canFinish(tasks, n, D, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << "Minimum work per day: " << result << endl;
    return 0;
}
