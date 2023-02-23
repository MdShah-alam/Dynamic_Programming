#include<bits/stdc++.h>
using namespace std;
long long dp[101][100001];

long long choice(long long wt[],long long val[],long long n, long long w)
{
    if(n==0||w==0)
        return 0;

    if(dp[n][w]!=-1)
        return dp[n][w];

    if(wt[n]<=w)
    {
        dp[n][w]= max((val[n]+choice(wt,val,n-1,w-wt[n])),choice(wt,val,n-1,w));
        return dp[n][w];
    }
    else
    {
        dp[n][w]=choice(wt,val,n-1,w);
        return dp[n][w];
    }
}

int main()
{
    long long n,m;
    cin>>n>>m;

    long long wt[n+1],val[n+1];
    for(long long i=1; i<=n; i++)
    {
        cin>>wt[i]>>val[i];
    }
    for(long long i=0;i<=n;i++)
    {
        for(long long j=0;j<=m;j++)
            dp[i][j]=-1;
    }
    cout<<choice(wt,val,n,m)<<endl;
    return 0;
}
