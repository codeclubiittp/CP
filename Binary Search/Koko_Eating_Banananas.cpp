#include <bits/stdc++.h>
using namespace std;

// Time Complexity - O(n*log(K))       where K is the maximum element in the array
// Space complexity - O(1)
long long findTime(int speed,vector<int>& dist){
    int n = dist.size();
    long long ans = 0;
    for(int i = 0;i < n;i++){
        ans += ceil(double(dist[i])/speed);
    }
    return ans;
}
int minEatingSpeed(vector<int>& piles, int h) {
    int n = piles.size();
    int ans = -1;
    int low = 1,high = *max_element(piles.begin(),piles.end());
    while(low <= high){
        int mid = (low+high)/2;
        if(findTime(mid,piles) <= h){
            // Eliminate the right search space
            ans = mid;
            high = mid-1;
        }
        else{
            // Eliminate the left search space
            low = mid+1;
        }
    }
    return ans;   
}
int main(){

    return 0;
}