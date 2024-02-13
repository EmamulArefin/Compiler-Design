#include<bits/stdc++.h>
using namespace std;

bool operator_Check(char a)
{
    char ab[]={'+','-','/','%','=','*'};

    for(int i=0;i<6;i++)
    {
        if(a==ab[i])
        {
            return true;
        }
    }
     return false;
}

void final_check(string a)
{
    set<char>c;
    for(int i=0;i<a.length();i++)
    {
        if(operator_Check(a[i])== true)
        {
            c.insert(a[i]);
        }
    }
    cout<<"Operators: ";
    for(auto i:c)
    {
        cout<<i<<" ";
    }
}
int main()
{
    string a;
    cin>>a;
    final_check(a);
}
