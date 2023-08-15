#include <bits/stdc++.h>
using namespace std;

// Brute Force Approach
// Time complexity - O(n)
// Space complexity - O(1)
int search(vector<int>& nums, int target) {
    for(int i = 0;i < nums.size();i++){
        if(nums[i] == target)
            return i;
    }
    return -1;
}

int search2(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return mid;
        }
        if(nums[low] <= nums[mid])  //This means the left part is sorted
        {
            if(nums[low] <= target && target <= nums[mid]){
            // if(nums[low] <= target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        else if(nums[mid] <= nums[high])  //This means the right part is sorted
        {
            if(nums[mid] <= target && target <= nums[high]){
            // if(target <= nums[high]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
    }
    return -1;
}
int main(){

    return 0;
}