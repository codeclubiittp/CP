#include <bits/stdc++.h>
using namespace std;

// Approach 1 - My Approach
// Time complexity - O(log(n))
// Space complexity - O(1)
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0,high = n-1;
    int ans = 1e9;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] < ans){
            ans = nums[mid];
        }
        // Both sides are sorted 
        if(nums[low] <= nums[mid] && nums[mid] <= nums[high]){
            high = mid-1;
            continue;
        }

        if(nums[low] <= nums[mid])  //This means the left part is sorted
        {
            if(nums[low] <= nums[mid]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        else if(nums[mid] <= nums[high])  //This means the right part is sorted
        {
            if(nums[mid] <= nums[high]){
                high = mid-1;
            }
            else{
                 low = mid+1;
            }
        }
    }
    return ans;
}

// Approach 2 - Optimized Approach
// Time complexity - O(log(n))
// Space complexity - O(1)
int findMin2(vector<int>& nums) {
    int n = nums.size();
    int low = 0,high = n-1;
    int ans = 1e9;
    while(low <= high){
        int mid = (low+high)/2;
        // If search space is always sorted
        // if(nums[low] <= nums[mid] && nums[mid] <= nums[high]){
        if(nums[low] <= nums[high]){
            ans = min(ans,nums[low]);
            break;
        }

        if(nums[low] <= nums[mid])  //This means the left part is sorted
        {
            ans = min(ans,nums[low]);
            low = mid+1;
        }
        else if(nums[mid] <= nums[high])  //This means the right part is sorted
        {
            ans = min(ans,nums[mid]);
            high = mid-1;
        }
    }
    return ans;
}

int main(){

    return 0;
}