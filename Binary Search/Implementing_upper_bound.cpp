#include <bits/stdc++.h>
using namespace std;

// Time complexity - O(log(n))
// Space complexity - O(1)
int upperBound(vector<int> arr, int x, int n) {
	// Write your code here
	int low = 0,high = n-1;
	int upper_Bound = n;
	while(low <= high){
		int mid = low+((high-low)/2);
		if(arr[mid] > x){
			upper_Bound = mid;
			high = mid-1;
		}
		else{
			low = mid+1;
		}
	}
	return upper_Bound;
}

int main(){
    vector<int> v{1,2,3,3,7,8,9,9,9,11};
    int n = v.size();
    int k = 9;
    cout << upperBound(v,k,n);
    
    // NOTE 
    // In C++ STL we have predefined function for upper bound which return an iterator pointing to the lower bound of the element
    // SYNTAX FOR USING UPPER BOUND
    // upper_bound(arr.begin(),arr.end(),target);
    return 0;
}