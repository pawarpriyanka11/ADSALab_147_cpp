
#include <iostream>
using namespace std;

int main() {
    int n, k, start[] = {1, 2, 5, 6, 9}, close[] = {3, 4, 7, 8, 10};
    cout<<"\nEnter number of shops: ";
    cin>>n;
    cout<<"\nEnter number of persons: ";
    cin>>k;
    cout<<"\nEnter start and close time of shop: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"start time for Shop"<<i+1<<": ";
        cin>>start[i];
        cout<<"end time of Shop"<<i+1<<": ";
        cin>>close[i];
    }
    int idx[n];
    
  
    for (int i = 0; i < n; i++) {
        idx[i] = i;
    }

   
    sort(idx, idx + n, [&](int a, int b) {
        return close[a] < close[b];
    });

    priority_queue<int, vector<int>, greater<int>> heap;
    
    
    for (int i = 0; i < k; i++) {
        heap.push(0);
    }

    int count = 0;
    
    for (int i = 0; i < n; i++) {
        int s = start[idx[i]], e = close[idx[i]]; 
        int avail = heap.top();
        
        if (s >= avail) {
            heap.pop();
            heap.push(e);
            count++;
        }
    }
    
    cout << "\nTotal number of shops "<<k<<" persons can visit is: " << count<<endl;

    return 0;
}
