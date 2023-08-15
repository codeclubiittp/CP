#include <bits/stdc++.h>
using namespace std;

// My Approach
int findKthPositive(vector<int>& arr, int k) {
    int n = arr.size();
    unordered_map<int,int> mp;
    for(int i = 0;i < n;i++){
        mp[arr[i]]++;
    }
    int low = 1,high = *max_element(arr.begin(),arr.end())+k;
    int a = k;
    while(low <= high){
        int mid = (low+high)/2;
        // Checking the left part
        int curr = 0;
        int last = -1;
        for(int i = low;i <= mid;i++){
            if(mp[i] == 0)
            {
                curr++;
                last= i;
            }
        }
        if(curr < a) // move to right part
        {
            a -= curr;
            low = mid+1;
        }
        else if(curr > a){
            high = mid-1;
        }
        else{
            return last;
        }
            // return mid;
    }
    return -1;
}

// Brute Force Approach
// Time complexity - O(n)
// Space complexity - O(1)
int findKthPositive2(vector<int>& arr, int k) {
    int n = arr.size();
    for(int i = 0;i < n;i++){
        if(arr[i] <= k)
            k++;
        else
            break;
    }
    return k;
}

// Binary Search
// Time complexity - O(log(n))
// Space complexity - O(1)
int findKthPositive3(vector<int>& arr, int k) {
    int n = arr.size();
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high) /2;
        int missingNumber = arr[mid]-mid-1;
        if(missingNumber < k){
            // Eliminate the left search space
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return high+k+1;
}

int main(){

    return 0;
}