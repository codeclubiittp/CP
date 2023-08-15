#include <bits/stdc++.h>
using namespace std;

// Approach 1 - Binary Search
// Time complexity - O(log(m+n))
// Space complexity - O(1)
int NthRoot(int n, int m) {
    // Write your code here.
    int low = 1,high = m;
    while(low <= high){
      int mid = (low+high)/2;
      int temp = m,count = 0;
      while(temp > 0 && count < n-1){
        temp /= mid;
        count++;
      }
      if(temp == mid)
        return mid; 
      if(temp < mid) high = mid-1;
      else  low = mid+1;
    }
    return -1;
}

int main(){

    return 0;
}