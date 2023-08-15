#include <bits/stdc++.h>
using namespace std;

int CountPainter(vector<int> &boards,int mid){
    int ans = 1,n = boards.size(),currtime = 0;
    for(int i = 0;i < n;i++){
        if(currtime+boards[i] <= mid){
            currtime += boards[i];
        }
        else{
            ans++;
            currtime = boards[i];
        }
    }
    return ans;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.
    int low = *max_element(boards.begin(),boards.end());
    int high = accumulate(boards.begin(),boards.end(),0);
    int ans = 0;
    while(low <= high){
        int mid = (low+high) / 2;
        int painters = CountPainter(boards,mid);
        if(painters <= k){
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
    vector<int> boards = {10,20,30,40};
    int k = 2;
    cout << findLargestMinDistance(boards,k);
    return 0;
}