#include<bits/stdc++.h>
using namespace std;

void check_comment(string a)
{
    int len = a.length();
    for(int i=0;i<len;i++)
    {
        if(a[0]=='/'&& a[1]=='/')
        {
           cout<<"Single Line comment";
           break;
        }
        else if((a[0]=='/'&&a[1]=='*')&& (a[len-2]=='*'&& a[len-1]=='/'))
        {
            cout<<"Multi Line Comment";
            break;
        }
        else
        {
            cout<<"Write in correct way of comment";
            break;
        }
    }
}

int main()
{
    string a;
    cin>>a;
    check_comment(a);
}

