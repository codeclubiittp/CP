#include <bits/stdc++.h>
using namespace std;


// This question iis similar to Koko Eating Bananas
// Time Complexity - O(n*log(K))       where K is the maximum element in the array
// Space complexity - O(1)

bool f(vector<int>& nums,int k,int threshold){
    int ans = 0,n = nums.size();
    for(int i = 0;i < n;i++){
        ans += ceil(double(nums[i])/k);
    }
    if(ans <= threshold){
        return true;
    }
    return false;
}
int smallestDivisor(vector<int>& nums, int threshold) {
    int low = 1,high = *max_element(nums.begin(),nums.end());
    int answer;
    while(low <= high){
        int mid = (low+high)/2;
        if(f(nums,mid,threshold)){
            answer = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return answer;
}
int main(){

    return 0;
}