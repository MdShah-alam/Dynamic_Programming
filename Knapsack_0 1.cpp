#include<bits/stdc++.h>
using namespace std;
const int N=101;
const int W=1e5+5;
int val[N];
int wt[W];
long long dp[N][W];

long long  knapsack(int n,int cap)
{
    if(n==0)
        return 0;
    if(dp[n][cap]!=-1) return dp[n][cap];

    long long ans=knapsack(n-1,cap);
    if(cap-wt[n]>=0)
        dp[n][cap]=max(ans,val[n]+knapsack(n-1,cap-wt[n]));
    else
        dp[n][cap]=ans;
    return dp[n][cap];
}

int main()
{
    int n,cap;
    cin>>n>>cap;
    for(int i=1;i<=n;i++)
        cin>>wt[i]>>val[i];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++)
            dp[i][j]=-1;
    }

    cout<<knapsack(n,cap);
    return 0;
}
