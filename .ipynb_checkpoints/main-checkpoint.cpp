#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarraySum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return max(0, arr[0]);
    int incl = max(0, arr[0]);
    int excl = 0;
    for (int i = 1; i < n; ++i) 
    {
        int new_incl = excl + max(0, arr[i]);
        excl = max(incl, excl);
        incl = new_incl;
    }

    return max(incl, excl); 
}

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout << maxSubarraySum(arr) << endl;
    return 0;
}
