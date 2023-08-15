#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(log(n))
// Space complexity - O(1)
int lowerBound(vector<int> arr, int n, int x) {
	// Write your code here
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
	return lower_Bound;
}

int main(){
    vector<int> v{1,2,3,3,7,8,9,9,9,11};
    int n = v.size();
    int k = 9;
    cout << lowerBound(v,n,k);
    
    // NOTE 
    // In C++ STL we have predefined function for lower bound which return an iterator pointing to the lower bound of the element
    // SYNTAX FOR USING LOWER BOUND
    // lower_bound(arr.begin(),arr.end(),target);
    return 0;
}