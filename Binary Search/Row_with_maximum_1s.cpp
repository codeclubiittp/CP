#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(n*log(m))
// Space complexity- O(1)
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    //    Write your code here.

    int ans = -1,maxi = 0;
    for(int i = 0;i < n;i++){
        int low = 0,high = m-1;
        int curr = m;
        while(low <= high){
            int mid = (low+high) / 2;
            if(matrix[i][mid] == 1){
                curr = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        if(maxi < m-curr){
            maxi = m-curr;
            ans = i;
        }
    }
    return ans;
}
int main(){

    return 0;
}