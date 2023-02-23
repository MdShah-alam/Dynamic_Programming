#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int W=1e5+5;
int dp[N][W];
int wt[N],val[N];
/**
int knapsack(int n,int w)
{
    if(n==0 || w==0)
        return 0;
    if(dp[n][w]!=-1)
        return dp[n][w];
    int ans1=knapsack(n-1,w);
    if(w<wt[n])
       return dp[n][w]=ans1;
    else
        return dp[n][w]=max(val[n]+knapsack(n,w-wt[n]),ans1);
}*/
int main()
{
    int n,w;
    cin>>n>>w;
    for(int i=1;i<=n;i++)
        cin>>wt[i]>>val[i];
    /**for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++)
            dp[i][j]=-1;
    }*/
    //cout<<knapsack(n,w)<<endl;
    for(int i=0;i<=w;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++){
        for(int cap=0;cap<=w;cap++){
            int ans1=dp[i-1][cap];
            if(cap<wt[i])
                dp[i][cap]=ans1;
            else
                dp[i][cap]=max((val[i]+dp[i][cap-wt[i]]),ans1);
        }
    }
    cout<<dp[n][w]<<endl;
    return 0;
}
