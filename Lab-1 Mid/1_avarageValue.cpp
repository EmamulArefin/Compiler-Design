#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a;
    int si,sum=0;
    cout<<"Input Array Size:";
    cin>>si;
    int arr[si];
    for(int i=0;i<si;i++)
    {
        cin>>arr[i];
    }

    for(int i=0;i<si;i++)
    {
        sum += arr[i];
    }
     a= sum/si;
    cout<<a;
}

