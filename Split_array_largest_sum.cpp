#include <bits/stdc++.h>
using namespace std;

// Binary Search
// Time complexity - O(log(m)*n)     where m = sum(nums[])-max(nums[])+1
int NoOfPartition(vector<int>& nums,int mid){
    int ans = 1,n = nums.size(),currSum = 0;
    for(int i = 0;i < n;i++){
        if(currSum+nums[i] <= mid)
            currSum += nums[i];
        else{
            ans++;
            currSum = nums[i];
        }
    }
    return ans;
} 
int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(),nums.end());
    int high = accumulate(nums.begin(),nums.end(),0);
    int ans = 0;
    while(low <= high){
        int mid = (low+high) / 2;
        int Partitions = NoOfPartition(nums,mid);
        if(Partitions <= k){
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}

int main(){

    return 0;
}