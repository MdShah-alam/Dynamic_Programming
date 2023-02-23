#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int h[N],dp[N];

int stone(int n,int m)
{
    if(n==1)
        return 0;
    if(n==2)
    {
        return abs(h[n-1]-h[n]);
    }

    int ans[m];
    for(int i=0;i<m;i++)
        ans[i]=0;

    if(dp[n]!=-1)
        return dp[n];

    for(int i=0;i<m;i++)
    {
         if(n - i <= 0) {
            break;
        }
        ans[i]=stone(n-(i+1),m)+abs(h[n]-h[n-(i+1)]);
    }
    int an=ans[0];
    for(int i=0;i<m;i++)
        an=min(an,ans[i]);
    dp[n]=an;
    return an;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>h[i];
    }
    for(int i=1;i<=n;i++)
    {
        dp[i]=-1;
    }
    cout<<stone(n,m)<<endl;
    return 0;
}

