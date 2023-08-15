#include <bits/stdc++.h>
using namespace std;

// Appraoch 1 - Brute force Approach
// Time complexity - O(n)
// Space complexity - O(1)
vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    int front = -1,back = -1;
    for(int i = 0;i < n;i++){
        if(nums[i] == target){
            if(front == -1)
                front =  i;
            back = i;
        }
    }
    return {front,back};
}

// Approach 2 - Using Binary Search
// Time complexity - 2*O(log(n))
// Space complexity - O(1)
vector<int> searchRange2(vector<int>& nums, int target) {
    int n = nums.size();
    int low = 0,high = n-1;
    int front = -1;
    while(low <= high){
        int mid = low+((high-low)/2);
        if(nums[mid] == target){
            front = mid;
            high = mid-1;
        }
        else if(nums[mid] > target){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    int back = -1;
    low = 0;high = n-1;
    while(low <= high){
        int mid = low+((high-low)/2);
        if(nums[mid] == target){
            back = mid;
            low = mid+1;
        }
        else if(nums[mid] <= target){
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return {front,back};
}

// Approach 3 - Using lowerbound and upperbound
// Time complexity - 2*O(log(n))
// Space complexity - O(1)
vector<int> searchRange3(vector<int>& nums, int target) {
    int n = nums.size();
    int lowerBound = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
    int upperBound = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
    int front = -1,back = -1;
    if(lowerBound < n && nums[lowerBound] == target)
        front = lowerBound;
    if(upperBound > 0 && nums[upperBound-1] == target)
        back = upperBound-1;
    return {front,back};
}
int main(){

    return 0;
}