/*
Problem Statement: 
Statement:
Given two arrays gas[] and cost[], find the starting gas station index from which you can complete the circuit once in a clockwise direction. You can travel from station i to station (i+1) only if you have enough gas. The car starts with an empty tank, and you can refuel at each station with gas[i] amount of fuel.

If you cannot complete the circuit, return -1.

Input:
Enter number of gas stations: 5               
Enter gas array: 1 2 3 4 5
Enter cost array: 3 4 5 1 2

Output:
Start index: 3
*/

#include <iostream>
using namespace std;

int canCompleteCircuit(int gas[], int cost[], int n) {
    int total = 0, tank = 0, start = 0;

    for (int i = 0; i < n; i++) {
        total += gas[i] - cost[i];
        tank += gas[i] - cost[i];
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    if (total >= 0)
        return start;
    else
        return -1;
}

int main() {
    int n;
    cout << "Enter number of gas stations: ";
    cin >> n;

    int gas[100], cost[100]; // assuming max 100 stations

    cout << "Enter gas array: ";
    for (int i = 0; i < n; i++) {
        cin >> gas[i];
    }

    cout << "Enter cost array: ";
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }

    int startIndex = canCompleteCircuit(gas, cost, n);
    if (startIndex != -1)
        cout << "Start index: " << startIndex << endl;
    else
        cout << "No possible starting point." << endl;

    return 0;
}
