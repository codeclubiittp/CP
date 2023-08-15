#include<bits/stdc++.h>
using namespace std;

// Time complexity - O(log(high-low+1)*m*log(n))
// Space complexity - O(1)
int median(vector<vector<int>> &matrix, int m, int n) {
    // Write your code here.
    int low = matrix[0][0],high = matrix[0][n-1];
    for(int i = 1;i < m;i++){
        low = min(low,matrix[i][0]);
        high = max(high,matrix[i][n-1]);
    }
    int left = (m*n)/2 + 1;
    while(low <= high){
        int mid = (low+high)/2;
        int leftElements = 0;
        for(int i = 0;i < m;i++){
            int j = upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
            leftElements += j;
        }
        if(leftElements >= left)    high = mid-1;
        else if(leftElements < left)    low = mid+1;
        //else    high = mid-1;
    }
    return low;
}
int main(){

    return 0;
}