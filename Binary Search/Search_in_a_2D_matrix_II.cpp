#include<bits/stdc++.h>
using namespace std;


// Time Complexity - O(m*log(n))      where m - rows and n - columns
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(),n = matrix[0].size();
    for(int i = 0;i < m;i++){
        int low = 0,high = n-1;
        while(low <= high){
            int mid = (low+high) / 2;
            if(matrix[i][mid] == target)    return true;
            else if(matrix[i][mid] < target)    low = mid+1;
            else    high = mid-1;
        }
    }
    return false;
}

// Most Optimized Solution
// Time Complexity - O(m+n)
// Space Complexity - O(1)
bool searchMatrix2(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(),n = matrix[0].size();
    int low = 0,high = n-1;
    while(low < m && high >= 0){
        if(matrix[low][high] == target)
            return true;
        else if(matrix[low][high] > target){
            high--;
        }
        else{
            low++;
        }
    }
    return false;
}
int main(){

    return 0;
}