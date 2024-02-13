#include<bits/stdc++.h>
using namespace std;
int main()
{
    float a;
    int si,k,temp;
    cout<<"Input Array Size:";
    cin>>si;
    int arr[si];
    for(int i=0;i<si;i++)
    {
        cin>>arr[i];
    }

    //Selection sort
   for(int i=0; i<si;i++)
    {
        k=i;
        for(int j=i+1;j<si;j++)
        {
            if(arr[k]>arr[j])
            {
                k=j;

            }
        }
                temp = arr[i];
                arr[i]=arr[k];
                arr[k]=temp;
    }
    cout<<"Maximum Value:"<<arr[si-1]<<endl;
    cout<<"Minimum Value:"<<arr[0]<<endl;
}
