#include <bits/stdc++.h>
using namespace std;


// Time complexity - O(log(m)*n)     where m = sum(arr[])-max(arr[])+1
int DistributeStudents(vector<int>& arr, int Pages){
    int n = arr.size();
    int students = 1;
    int Stuedntpages = 0;
    for(int i = 0;i < n;i++){
        if(arr[i]+Stuedntpages <= Pages){
            //add pages to current student
            Stuedntpages += arr[i];
        }
        else{
            //add pages to next student
            students++;
            Stuedntpages = arr[i];
        }
    }
    return students;
}
// Binary Search
int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(m > n)
        return -1;

    int ans = -1;
    int low = *max_element(arr.begin(),arr.end());
    // We could have used accumulate function to calculate the sum rather than running a loop
    int high = accumulate(arr.begin(),arr.end(),0);
    // int high = 0;
    // for (auto it:arr)
    //     high += it;

    while (low <= high){
        int mid = (low+high)/2;
        int Students = DistributeStudents(arr,mid);
        if(Students <= m){
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;

    }
    return ans;    
}
int main(){

    return 0;
}
