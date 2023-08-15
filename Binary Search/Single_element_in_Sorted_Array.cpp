#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Brute Force Approach 1
// Time complexity - O(n)
// Space complexity - O(1)
int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(i == 0){
            if(nums[i] != nums[i+1]){
                ans = nums[i];
                break;
            }
            else
                continue;
        }
        if(i == n-1){
            if(nums[i-1] != nums[i]){
                ans = nums[i];
                break;
            }
            else
                continue;
        }
        if(nums[i-1] != nums[i] && nums[i] != nums[i+1]){
            ans = nums[i];
            break;
        }
    }
    return ans;
}

// Approach 2 - Brute Force Approach 2
// Time complexity - O(n)
// Space complexity - O(n)
int singleNonDuplicate2(vector<int>& nums) {
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    int ans = 0;
    unordered_map<int,int> mp;
    for(int i = 0;i < n;i++){
        mp[nums[i]]++;
    }
    for(auto it:mp){
        if(it.second == 1)
            ans = it.first;
    }
    return ans;
}

// Approach 3 - Using XOR
// We will XOR every element of the array and at last we will be left out with the unique element because of the properties of XOR
// 1. a^a = 0
// 2. a^0 = a

// Time complexity - O(n)
// Space complexity - O(1)
int singleNonDuplicate3(vector<int>& nums) {
    int n = nums.size();
    int ans = nums[0];
    for(int i = 1;i < n;i++){
        ans ^= nums[i];
    }
    return ans;
}

// Approach 4 - Binary Search
// Time complexity - O(log(n))
// Space complexity - O(1)
int singleNonDuplicate4(vector<int>& nums) {
    int n = nums.size();
    if(n == 1){
        return nums[0];
    }
    if(nums[0] != nums[1]){
        return nums[0];
    }
    if(nums[n-1] != nums[n-2]){
        return nums[n-1];
    }
    int low = 1,high = n-2;    // I am keeping the low and high pointer at 1 and n-2 because I have already checked the condition for 0 and n-1 indices
    while(low <= high){
        int mid = (low+high)/2;

        if(nums[mid-1] != nums[mid] && nums[mid] != nums[mid+1]){
            return nums[mid];
        }

        // left side
        if((mid%2 == 0 && nums[mid+1] == nums[mid])||(mid%2 == 1 && nums[mid-1] == nums[mid])){
            low = mid+1;
        }
        // right side 
        else{
            high = mid-1;
        }
    }
    return -1;
}

int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};
    cout << singleNonDuplicate(nums) << endl;
    cout << singleNonDuplicate2(nums) << endl;
    cout << singleNonDuplicate3(nums) << endl;
    cout << singleNonDuplicate4(nums) << endl;
    return 0;
}