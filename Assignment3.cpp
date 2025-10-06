/*
Problem statement: Implement a problem of smallest number with at least n trailing zeros in factorial.
Description: Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeros.
*/

/*Input:
Enter the number of trailing zeros:3
*/

#include<iostream>
using namespace std;

int countZeros(int x) {
    int count = 0;
    while (x > 0) {
        count += x / 5;
        x /= 5;
    }
    return count;
}

int main()
{
    int n,mid,zeros;
    cout << "\nEnter the number of trailing zeros: ";
    cin >> n;
    int low = 0, high = n * 5, ans = -1;
    while (low <= high) {
        mid = (low + high) / 2;
        zeros = countZeros(mid);
        if (zeros == n) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    if (ans != -1 )
        cout << "The smallest number whose factorial contains exactly " << n << " trailing zeros is: " << ans << endl;
    else
        cout << "No such number exists." << endl;
    return 0;
}

/* Output:
 The smallest number whose factorial contains exactly 3 trailing zeros is:15 
 */