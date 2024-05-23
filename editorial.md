# Editorial: Subarray Sum 2.0

We have to find maximum subarray sum such that no 2 elements in that sum are consecutive.

Let's consider the given example:

**Input:**

4

3 2 7 10

**Output:**

13

Clearly, the maximum sum in this case is  10+3=13

### Approach

This problem can be efficiently solved using dynamic programming. Let's define two variables:

(1) incl: represents the maximum sum including the current element.
(2) excl: represents the maximum sum excluding the current element.
We initialize incl as the maximum of 0 and the first element of the array, and excl as 0.

Then, we iterate through the array, updating incl and excl as follows:

For each element arr[i], we calculate a new inclusive sum new_incl as the sum of excl and max(0, arr[i]), i.e., the maximum of 0 and the current element.
We update excl as the maximum of the previous incl and excl.
We update incl with the newly calculated new_incl.
Finally, the maximum subarray sum will be the maximum of incl and excl.

### Solution code

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubarraySum(vector<int>& arr) {
    int n = arr.size();
    if (n == 0) return 0;
    if (n == 1) return max(0, arr[0]);

    int incl = max(0, arr[0]); // Maximum sum including the current element
    int excl = 0; // Maximum sum excluding the current element

    for (int i = 1; i < n; ++i) {
        int new_incl = excl + max(0, arr[i]); // Calculate the new inclusive sum
        excl = max(incl, excl); // Update excl and incl for the next iteration
        incl = new_incl;
    }

    return max(incl, excl); // Return the maximum of incl and excl as the final result
}

int main() {
    vector<int> arr = {3, 2, 7, 10};
    cout << maxSubarraySum(arr) << endl; // Output: 13

    return 0;
}


### Complexity Analysis

Time Complexity: $O(N)$ - The time complexity of this solution is O(n), where n is the number of elements in the input array.

Space Complexity: $O(1)$ - The space complexity is O(1) as we only use a constant amount of extra space.
