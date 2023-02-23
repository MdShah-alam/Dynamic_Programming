#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int W=1e5+5;
int val[N],wt[N];
long long dp[N][W];

long long knapsack(int n,int cap)
{
    if(n==0) return 0;

    if(dp[n][cap]!=-1)
        return dp[n][cap];

    if(cap<wt[n]){
        long long ans=knapsack(n-1,cap);
        dp[n][cap]=ans;
        return dp[n][cap];
    }
    long long ans_1=val[n]+knapsack(n-1,cap-wt[n]);
    long long ans_2=knapsack(n-1,cap);
    dp[n][cap]=max(ans_1,ans_2);
    return dp[n][cap];
}

int main()
{
    int n,cap;
    cin>>n>>cap;
    for(int i=1;i<=n;i++)
        cin>>wt[i]>>val[i];

    for(int i=1;i<=n;i++){
        for(int j=1;j<=cap;j++)
            dp[i][j]=-1;
    }

    cout<<knapsack(n,cap)<<endl;

    return 0;
}
