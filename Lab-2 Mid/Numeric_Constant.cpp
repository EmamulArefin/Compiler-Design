#include<bits/stdc++.h>
using namespace std;

void numeric_check(string a)
{
    int con=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]>=46 && a[i]<=57 && a[i]!=47 ||a[i]==45)
        {
           con++;
        }
    }
    if(con==a.length())
    {
        cout<<"Numeric Constant";
    }
    else
    {
        cout<<"Not numeric";
    }
}

int main()
{
    string a;
    cin>>a;
   numeric_check(a);
}
