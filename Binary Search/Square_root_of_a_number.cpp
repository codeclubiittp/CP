#include <bits/stdc++.h>
using namespace std;


// Approach - Binary Search
// Time complexty - O(log(n))
// Space complexity - O(1)
int floorSqrt(int n)
{
    // Write your code here.
    int low = 1,high = n/2;
    int mid;
    while(low <= high){
        mid = (low+high)/2;
        if(mid == n/mid)    // mid*mid might get overflowed because mid may go till 1e9 so mid == n/mid will work
            return mid;
        if(mid > n/mid) high = mid-1;
        else    low = mid+1;
    }
    return high;   //The floor sqrt will be saved in high 
}

int main(){

    return 0;
}