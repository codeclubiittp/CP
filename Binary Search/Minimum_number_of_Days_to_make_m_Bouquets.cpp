#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*log(K))       where K is the maximum element of the array
// Space complexity - O(n)
bool CanMakeBouquet(vector<int>& bloomDay,int day,int m,int k){
    int n = bloomDay.size();
    vector<int> flowers(n,0);
    for(int i = 0;i < n;i++){
        if(bloomDay[i] <= day){
            flowers[i] = 1;
        }
    }
    int i = 0,j = 0,maxConsecutive = 0;
    while(j < n){
        if(flowers[j] == 1){
            j++;
        }
        else{
            j++;
            i = j;
        }
        if(j-i == k){
            maxConsecutive++;
            i = j;
        }
    }
    if(j-i == k){
        maxConsecutive++;
        i = j;
    }
    return (maxConsecutive >= m);
}
int minDays(vector<int>& bloomDay, int m, int k) {
    long long totalflowers = (long long)(m)*k;
    int n = bloomDay.size();
    if(totalflowers > n)
        return -1;
    int low = 1,high = *max_element(bloomDay.begin(),bloomDay.end());
    while(low <= high){
        int mid = low+ ((high-low)/2);
        if(CanMakeBouquet(bloomDay,mid,m,k)){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}

int main(){

    return 0;
}