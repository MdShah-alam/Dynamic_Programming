#include<bits/stdc++.h>
using namespace std;

int LCS(string s, string t , int n, int m)
{
    if(n==0 || m==0) return 0;
    if(s[n-1]==t[m-1]) return 1 + LCS(s,t,n-1,m-1);

    else return max(LCS(s,t,n-1,m),LCS(s,t,n,m-1));
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<LCS(s,t,s.size(),t.size())<<endl;

    return 0;
}
