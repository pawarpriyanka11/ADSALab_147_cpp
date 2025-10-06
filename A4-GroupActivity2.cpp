/*Problem Statement:
Given a set of points in a 2D plane, find the closest pair of points.
*/
#include <bits/stdc++.h>
using namespace std;

double distance(pair<int, int> p1, pair<int, int> p2)
{
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) +
                (p1.second - p2.second) * (p1.second - p2.second));
}

double closestPairBruteForce(vector<pair<int, int>> &points)
{
    double minDist = DBL_MAX;
    pair<int, int> a, b;
    int n = points.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double d = distance(points[i], points[j]);
            if (d < minDist)
            {
                minDist = d;
                a = points[i];
                b = points[j];
            }
        }
    }

    cout << "Closest Points: (" << a.first << "," << a.second << ") and ("
         << b.first << "," << b.second << ")\n";
    return minDist;
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].first >> points[i].second;
    }

    double minDist = closestPairBruteForce(points);
    cout << "Minimum Distance: " << minDist << endl;
    return 0;
}

/*
Example:
Input:
4
0 0
1 1
2 2
3 3
Output:
Closest Points: (0,0) and (1,1)
Minimum Distance: 1.41421
*/