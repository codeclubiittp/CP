#include<bits/stdc++.h>
using namespace std;

// Approach 1 - Brute Force Approach 
// Time complexity - O(k*n) 
long double minimiseMaxDistance(vector<int> &arr, int k){
	// Write your code here.
    int n = arr.size();
    vector<long double> partitions(n-1,1);
    for(int i = 1;i <= k;i++){
        long double maxDist = -1;
        int maxDistInd = -1;
        for(int j = 0;j < n-1;j++){
            long double currDist = (arr[j+1]-arr[j])/partitions[j];
            if(currDist > maxDist)
            {
                maxDist = currDist;
                maxDistInd = j;
            }
        }
        partitions[maxDistInd] += 1;
    }	

    long double ans = -1;
    for (int i = 0; i < n-1; i++)
    {
        long double curr = (arr[i+1]-arr[i])/partitions[i];
        ans = max(ans,curr);
    }
    return ans;    
}

// Approach 2 - Using Max Heap 
// Time complexity - O(n*log(n)) + O(k*log(n))
// Space complexity - 2*O(n)     for partition  array and priority queue
long double minimiseMaxDistance2(vector<int> &arr, int k){
	// Write your code here.
    int n = arr.size();
    vector<long double> partitions(n-1,1);
    priority_queue<pair<long double,int>> pq;
    for(int i = 0;i < n-1;i++){
        pq.push({(arr[i+1]-arr[i])/partitions[i],i});
    }
    for(int i = 1;i <= k;i++){
        long double maxDist = pq.top().first;
        int maxDistInd = pq.top().second;
        pq.pop();
        partitions[maxDistInd] += 1;

        pq.push({(arr[maxDistInd+1]-arr[maxDistInd])/partitions[maxDistInd],maxDistInd});
    }

    long double ans = -1;
    for (int i = 0; i < n-1; i++)
    {
        long double curr = (arr[i+1]-arr[i])/partitions[i];
        ans = max(ans,curr);
    }
    return ans;    
}

// Approach 3 - Binary Search
// Time complexity - O(log(max(dist))*n)       since the length of search space is 0 to max(dist) between two consecutive stations
int CalculateStations(vector<int> &arr,long double mid){
    int n = arr.size();
    int ans = 0;
    for(int i = 0;i < n-1;i++){
        int stationsInBetween = (arr[i+1]-arr[i]) / mid;
        if((arr[i+1]-arr[i]) == mid*stationsInBetween){
            stationsInBetween--;
        }
        ans += stationsInBetween;
    }
    return ans;
}
long double minimiseMaxDistance3(vector<int> &arr, int k){
	// Write your code here.
    int n = arr.size();
    long double low = 0,high = 0;
    for(int i = 0;i < n-1;i++){
        high = max(high,(long double)(arr[i+1]-arr[i]));
    }
    long double diff = 1e-6;
    while (high - low > diff)
    {
        long double mid = (low+high) / 2;
        int newStations = CalculateStations(arr,mid);
        if(newStations > k)
            low = mid;
        else{
            high = mid;
        }
    }
    return high;
}

int main(){

    return 0;
}