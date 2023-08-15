#include <bits/stdc++.h>
using namespace std;

// I am assuming the array is already sorted
// We will return -1 if element is not found in the array otherwise we will return the index of the element 
int Binary_Search(vector<int>& v,int element,int low,int high){
    int n = v.size();
    // Base Case
    if(low > high){
        return -1;
    }
    int mid = (low+high)/2;
    if(v[mid] == element){
        return mid;
    }
    else if(v[mid] > element){
        return Binary_Search(v,element,low,mid-1);
    }
    else{
        return Binary_Search(v,element,mid+1,high);
    }
}
int main(){
    vector<int> v{3,4,6,7,9,12,16,17};
    int k = 16;
    int l = 0,h = v.size()-1;
    cout << Binary_Search(v,k,l,h);
    return 0;
}