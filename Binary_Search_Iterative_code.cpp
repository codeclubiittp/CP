#include <bits/stdc++.h>
using namespace std;

// I am assuming the array is already sorted
// We will return -1 if element is not found in the array otherwise we will return the index of the element 
int Binary_Search(vector<int>& v,int element){
    // In case its not sorted comment out the below line (NOTE - But then it will not give us the correct index as array is changed)
    // sort(v.begin(),v.end());
    int n = v.size();
    int low = 0,high = n-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(v[mid] == element){
            return mid;
        }
        else if(v[mid] > element){
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return -1;
}

int main(){
    vector<int> v{3,4,6,7,9,12,16,17};
    int k = 16;
    cout << Binary_Search(v,k);
    return 0;
}