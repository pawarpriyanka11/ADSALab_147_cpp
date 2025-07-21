/*
Problem statement: Implement the problem statemnt of moving all zeros to end of the array.
Description: Given an array of random numbers push all the zeros of the given array at the end of the array.
*/

/*Input:
Enter array size: 5
Enter 5 elements:1 0 222 0 0  */



#include <iostream>
using namespace std;

// mergein descending
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    // decending-sort
    while (i < n1 && j < n2) {
        if (L[i] >= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}


void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

// Printarray
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cout << "Enter array size: ";
    cin >> n;

    int arr[10];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Original array:\n";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    cout << "Zero appended to end of array: \n";
    printArray(arr, n);

    return 0;
}


/*Output:
Original array:
1 0 222 0 0 
Zero appended to end of array:
222 1 0 0 0 */
