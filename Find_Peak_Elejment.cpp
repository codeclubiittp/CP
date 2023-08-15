#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(log(n))
// Space complexity - O(1)
int findPeakElement(vector<int>& nums) {
    int n = nums.size();
    if(n == 1)  return 0;
    if(nums[0] > nums[1])   return 0;
    if(nums[n-1] > nums[n-2])   return n-1;
    int low = 1,high = n-2;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid-1] < nums[mid] && nums[mid] > nums[mid+1])  return mid;

        // On left of peak
        if(nums[mid-1] <= nums[mid] && nums[mid] <= nums[mid+1]){
            // Eliminate the left search space
            low = mid+1;
        }
        // On right of peak  (We can also be on thecommon point where a decreasing sequence ends and increasing sequence begins)
        else{
            // Eliminate the right search space
            high = mid-1;
        }
    }
    return -1;
}

// Brute Force Approach   
// Time Complexity - O(n)
// Space complexity - O(1)
int findPeakElement2(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    for (int i = 0; i < n; i++) {
        //Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i]) && (i == n - 1 || arr[i] > arr[i + 1]))                //(Condition is written very cleaverly here)
        {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

int main(){

    return 0;
}