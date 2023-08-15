#include<bits/stdc++.h>
using namespace std;


// Time Complexity - O(m*log(n))     where m - row , n - column
vector<int> findPeakGrid(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    int deltarow[4] = {-1,0,1,0};
    int deltacol[4] = {0,1,0,-1};
    for(int i = 0;i < m;i++){
        int j = max_element(mat[i].begin(),mat[i].end()) - mat[i].begin();
        bool status = true;
        for(int k = 0;k < 4;k++){
            int newRow = i+deltarow[k];
            int newCol = j+deltacol[k];
            if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n){
                if(mat[newRow][newCol] >= mat[i][j]){
                    status = false;
                }
            }
        }
        if(status)
            return {i,j};
    }
    return {-1,-1};
}
int main(){

    return 0;
}