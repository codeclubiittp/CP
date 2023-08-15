#include <bits/stdc++.h>
using namespace std;

// Function to be used by both approaches
bool CanPlaceCows(int dist,vector<int> &stalls, int k){
    int n = stalls.size();
    k--;   //Assume first cow is placed on first position
    int lastPos = 0;
    for(int i = 1;i < n;i++){
        if(k == 0){
            return true;
        }
        if(stalls[i]-stalls[lastPos] >= dist){
            k--;
            lastPos = i;
        }
    }
    return k == 0;
}

// Brute Force Approach
// Time complexity - O(M*n)
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int M = stalls[n-1]-stalls[0];
    int i = 1;
    for(;i <= M;i++){
        if(!CanPlaceCows(i,stalls,k)){
            break;
        }
    }
    return i-1;
}

// Binary Search
// Time complexity - O(log(M)*n)
int aggressiveCows2(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(),stalls.end());
    int M = stalls[n-1]-stalls[0];
    int low = 1,high = M;
    while(low <= high){
        int mid = (low+high) / 2;
        if(CanPlaceCows(mid, stalls, k))
            low = mid+1;
        else
            high = mid-1;
    }
    return high;
}

int main(){

    return 0;
}
