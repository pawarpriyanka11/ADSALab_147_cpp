#include <iostream>
using namespace std;

int main() {
    int n;
cout<<"\nEnter the size of array:";
cin>>n;
int arr[10];

cout<<"\nEnter"<<n<<"elements of array: ";
for(int i=0;i<n;i++)
{
  cin>>arr[i];
}


    for (int i = 1; i < n; i++) {
        if (arr[i] == 1 && arr[i - 1] == 0) {
            cout << "Invalid input!" << endl;
            return 0;
        }
    }


    int low = 0, high = n - 1, temp = -1;
while (low <= high) {
    int mid = (low + high) / 2;
    if (arr[mid] == 0) {
        temp = mid;
        high = mid - 1;
    } else {
        low = mid + 1;
    }
}
if (temp == -1)
    cout << "Number of 0's: 0" << endl;
else
    cout << "Number of 0's: " << n - temp << endl;
    return 0;
}
