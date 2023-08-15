#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(log(n))
// Space complexity - O(1)
pair<int, int> getFloorAndCeil(int arr[], int n, int x) {
	// Write your code here.
	sort(arr,arr+n);    //Sorting the array as we want to implement Binary Search
	int low = 0,high = n-1;
	int lower_Bound = n;
	while(low <= high){
		int mid = low+((high-low)/2);
		if(arr[mid] >= x){
			lower_Bound = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	if(arr[lower_Bound] == x)
		return {arr[lower_Bound],arr[lower_Bound]};
	else
	{
		int floor,ceil;
		if(lower_Bound == n)
			ceil = -1;
		else
			ceil = arr[lower_Bound];
		
		if(lower_Bound == 0)
			floor = -1;
		else
			floor = arr[lower_Bound-1];

        return {floor, ceil};
    }
}

int main(){
    int n = 6;
    int v[n] = {4,3,8,4,7,10};
    int x = 5;
    pair<int,int> floor_ceil = getFloorAndCeil(v,n,x);
    cout << floor_ceil.first << " " << floor_ceil.second << endl;
    return 0;
}