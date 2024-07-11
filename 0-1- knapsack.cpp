#include<bits/stdc++.h>
using namespace std;
int const N=105;
int const W=1e5+5;
long long dp[N][W] , wt[W];
long long val[N];

long long knapsack(int n , int cap)
{
    if(n==0)
        return 0;
    if(dp[n][cap]!=-1)
        return dp[n][cap];
    if(cap<wt[n]){
        int ans2 = knapsack(n-1,cap);
        dp[n][cap]=ans2;
        return ans2;
    }
    int ans1=val[n]+knapsack(n-1,cap-wt[n]);
    int ans2 = knapsack(n-1,cap);
    return dp[n][cap]=max(ans1,ans2);
}

int main()
{
    int n,cap;
    cin>>n>>cap;
    for(int i=1;i<=n;i++){
        cin>>wt[i]>>val[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=cap;j++)
            dp[i][j]=-1;
    }
    cout<<knapsack(n,cap)<<endl;
    return 0;
}
