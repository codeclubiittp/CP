#include <bits/stdc++.h>
using namespace std;


// Time complexity - O(n*log(K))           K is the sum of all array elements
// Space complexity - O(1)
int f(vector<int>& weights,int capacity, int days){
    int i = 0,j = 0,n = weights.size(),sum = 0,totalDays = 0;
    while(j < n){
        if(weights[i] > capacity)
            return 1e9;
        sum += weights[j];
        if(sum == capacity){
            totalDays++;
            j++;
            i = j;
            sum = 0;
        }
        else if(sum > capacity){
            totalDays++;
            i = j;
            sum = 0;
        }
        else{
            j++;
        }
    }
    if(j > i && sum <= capacity){
        totalDays++;
    }
    return totalDays;
}
int shipWithinDays(vector<int>& weights, int days) {
    int low = 1,high = 0;
    for(auto it:weights){
        high += it;
    }
    while(low <= high){
        int mid = (low+high)/2;
        // cout << mid << " " << f(weights,mid,days) << endl;
        if(f(weights,mid,days) <= days){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main(){
    vector<int> weights = {1,2,3,1,1};
    int days = 4;
    cout << shipWithinDays(weights,days);
    return 0;
}