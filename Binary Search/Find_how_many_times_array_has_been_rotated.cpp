#include <bits/stdc++.h>
using namespace std;

// Brute force approach
// Time complexity - O(n)
// Space complexity - O(1)
int findKRotation(vector<int> &arr){
    // Write your code here. 
    int n = arr.size();
    for(int i = 0;i < n-1;i++){
        if(arr[i+1] < arr[i]){
            return i+1;
            break;
        }
    }  
    return 0; 
}

// Approach 2 - binary Search
// We will just find the index of minimum element in the rotated sorted array to get how many times the array was sorted
// Time Complexity - O(log(n))
// Space Complexity - O(1)
int findKRotation(vector<int> &arr){
    // Write your code here. 
    int n = arr.size();
    int low = 0,high = n-1,mini = 1e9,ans = -1;
    while(low <= high){
        int mid = (low+high)/2;
        // if the search space is sorted then we have already found the rotating point
        if(arr[low] <= arr[high]){
            if(mini > arr[low]){
                ans = low;
                mini = arr[low];
            }
            break;
        }

        if(arr[low] <= arr[mid]){
            if(mini > arr[low]){
                ans = low;
                mini = arr[low];
            }
            low = mid+1;
        }
        else{
            if(mini > arr[mid]){
                ans = mid;
                mini = arr[mid];
            }
            high = mid-1;
        }
    }
    return ans;
}

// NOTE - We can extend this problem for duplicates by the condition we have used in serching element in rotated sorted array II and finding minimum in rotated sorted array II
int main(){

    return 0;
}