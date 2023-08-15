#include<bits/stdc++.h>
using namespace std;

// Time complexity - O(log(n))(for Best Case - All elements are distinct)
// Time complexity - O(n)(for Worst Case - when duplicates are there eg - {2,2,2,2,2,2})
// Space complexity - O(1)
int findMin(vector<int>& nums) {
    int n = nums.size();
    int low = 0,high = n-1;
    int ans = 1e9;
    while(low <= high){
        int mid = (low+high)/2;
        // Speial Case to handle for duplicates
        if(nums[low] == nums[high]){
            ans = min(ans,nums[low]);
            low++;
            high--;
            continue;
        }
        
        // If search space is always sorted
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