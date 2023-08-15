#include <iostream>
#include <bits/stdc++.h>
using namespace std;

double multiply(double number,int n)
{
    for(int i = 1;i < n;i++)
    {
        number *= number;
    }
    return number;
}
// here I am calculating the root untill 5 digit precision
double nth_root(int m,int n)
{
    double low = 1;
    double high = m;
    double mid = (low+high)/2.0;
    double eps = 1e-6;              //power should be 1 more than the precision
    while((high-low) > eps)
    {
        if(multiply(mid,n) < m)
            low = mid;
        else
            high = mid;
        mid = (low+high)/2.0;
    }
    cout << low << " " << high << endl;         // both will be same upto 5 decimal places 
    cout << pow(m,(1.0/n)) << endl;            // for crosschecking
    return low;
}
int main(){
    int n = 3;
    int m = 28;
    cout << nth_root(m,n);
    return 0;
}