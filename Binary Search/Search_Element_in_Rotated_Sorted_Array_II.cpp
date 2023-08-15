#include <bits/stdc++.h>
using namespace std;


// Binary Search Approach

// TIME COMPLEXITIES
// Best Case Time Complexity - O(log(n))    (When all the elements are distinct)
// Worst Case Time complexity - O(n)         (When there are duplicate elements, we miss the chance of applying binary search and have to do low++ which eventually boils down to O(n) time complexity)

// SPACE COMPLEXITY - O(1)

 
// Helper function to tell the target number is in which sorted part of the array
bool inFirst(vector<int>& nums, int low,int target){
    if(nums[low] <= target)
        return true;
    return false;
}
int search(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0,high = n-1;
    while(low <= high){
        // cout << low << " " << high << endl;
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return true;
        }
        // Corner Case - When nums[mid] == nums[low]
        if(nums[mid] == nums[low])  //This means the right part is sorted
        {
            low++;
            continue;
        }

        // Case 1 - nums[mid] is in first sorted part and target is in second sorted part
        if(inFirst(nums,low,nums[mid]) && !inFirst(nums,low,target)) 
        {
            low = mid+1;
        }
        // Case 2 - nums[mid] is in second sorted part and target is in first sorted part
        else if(!inFirst(nums,low,nums[mid]) && inFirst(nums,low,target)){
            high = mid-1;
        }
        // Case 3 - nums[mid] is in first sorted part and target is in first sorted part
        else if(inFirst(nums,low,nums[mid]) && inFirst(nums,low,target)){
            if(target < nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        // Case 4 - nums[mid] is in second sorted part and target is in second sorted part
        else if(!inFirst(nums,low,nums[mid]) && !inFirst(nums,low,target)){
            if(target < nums[mid]){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
    }
    return false;
}

// More optimized Approach 
// Time Complexity - O(log(n)) (for BEST case)
// Time Complexity - O(n) (for WORST case)
// Space complexity - O(1)
int search2(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(nums[mid] == target){
            return true;
        }
        // Case where unique elements code was failing
        if(nums[low] == nums[mid] && nums[mid] == nums[high]){
            low++;
            high--;
            continue;
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
    return false;
}

int main(){
    vector<int> nums = {1,0,1,1,1};
    int target = 0;
    cout << search(nums,target) << endl;
    cout << search2(nums,target);
    return 0;
}