#include<bits/stdc++.h>
using namespace std;

// Approach 1 - (Brute Force)  Merging the sorted arrays then finding median
// Time Complexity - O(m+n)
// Space Complexity - O(m+n);
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int i = 0,j = 0,k = 0;
    int m = nums1.size(),n = nums2.size();
    vector<int> mergedArray(m+n);
    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            mergedArray[k] = nums1[i];
            i++;
        }
        else{
            mergedArray[k] = nums2[j];
            j++;
        }
        k++;
    }
    while(i < m){
        mergedArray[k] = nums1[i];
        i++;
        k++;
    }
    while(j < n){
        mergedArray[k] = nums2[j];
        j++;
        k++;
    }
    if((m+n) % 2 == 1)
        return (double)(mergedArray[(m+n)/2]);
    else
        return (mergedArray[(m+n)/2] + mergedArray[((m+n)/2) - 1]) / (2.0);
}

// Approach 2 - Brute force optimized(Here I am not creating a new array we are just running loop depending whether total no. of elements are even or odd)
// See Leetcode editorial for neat and clean code
// Time Complexity - O(m+n)
// Space Complexity - O(1);
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(),n = nums2.size();
    int k = (m+n)/2;
    double ans;
    int p1 = 0,p2 = 0;
    double sum = 0;
    for (int i = 0; i < k; i++)
    {
        if(i == k-1){
            if(p1 < m && p2 < n)   sum += min(nums1[p1],nums2[p2]);
            else if(p1 < m)     sum += nums1[p1];
            else    sum += nums2[p2];
        }
        if(p1 < m && p2 < n){
            if(nums1[p1] < nums2[p2])   p1++;
            else    p2++;
        }
        else if(p1 < m)     p1++;
        else    p2++;
    }
    if((m+n)%2 == 1){
        if(p1 < m && p2 < n)    return min(nums1[p1],nums2[p2]);
        else if(p1 < m)     return nums1[p1];
        else    return nums2[p2];
    }
    else
    {
        if(p1 < m && p2 < n)    sum += min(nums1[p1],nums2[p2]);
        else if(p1 < m)     sum += nums1[p1];
        else    sum += nums2[p2];
        return sum/2.0;
    }  
}

// Approach 3 - Binary Search
// Time Complexity - O(log(min(n1,n2)))
// Space Complexity - O(1)
double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size()) return findMedianSortedArrays3(nums2,nums1);
    int n1 = nums1.size(),n2 = nums2.size();
    int n = n1+n2;
    int left = (n1+n2+1) / 2;    // length of left half 
    int low = 0,high = n1;
    while (low <= high)
    {
        int mid1 = (low+high) / 2;
        int mid2 = left-mid1;
        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if(mid1 < n1)   r1 = nums1[mid1];
        if(mid2 < n2)   r2 = nums2[mid2];
        if(mid1 - 1 >= 0)   l1 = nums1[mid1-1];
        if(mid2 - 1 >= 0)   l2 = nums2[mid2-1];
        if(l1 <= r2 && l2 <= r1){
            if(n%2 == 1){
                return max(l1,l2);
            }
            else{
                return ((double)max(l1,l2)+min(r1,r2)) / 2.0;
            }
        }
        else if(l1 > r2)    high = mid1 - 1;
        else    low = mid1+1;
    }
    return -1;
}

int main(){
    vector<int> nums1 = {1,2};
    vector<int> nums2 = {3,4};
    cout << findMedianSortedArrays(nums1,nums2) << endl;
    cout << findMedianSortedArrays2(nums1,nums2) << endl;
    cout << findMedianSortedArrays3(nums1,nums2) << endl;
    return 0;
}