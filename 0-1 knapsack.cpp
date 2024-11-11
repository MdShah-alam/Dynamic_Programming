#include<bits/stdc++.h>
using namespace std;
int const N=1e4+5;
int const W=10005;
long long dp[N][W];

int knapsack(vector<int>&wt, vector<int>&val, int w, int i)
{
    if(i==0 || w==0)
        return 0;

    if(dp[i][w]!=-1) return dp[i][w];

    if(w<wt[i-1]){
        dp[i][w] = knapsack(wt,val,w,i-1);
        return dp[i][w];
    }
    int ans1=knapsack(wt,val,w-wt[i-1],i-1)+val[i-1];
    int ans2=knapsack(wt,val,w,i-1);
    dp[i][w] = max(ans1,ans2);
    return dp[i][w];
}

int main()
{
    int n;
    cin>>n;
    vector<int>wt(n),val(n);

    for(int i=0;i<n;i++)
        cin>>wt[i];
    for(int i=0;i<n;i++)
        cin>>val[i];

    int w;
    cin>>w;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++)
            dp[i][j]=-1;
    }

    cout<<knapsack(wt,val,w,n)<<endl;

    for(int i=0;i<=n; i++){
        for(int j=0; j<=w;j++)
            dp[i][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            if(wt[i-1]<=j){
                dp[i][j]=max(dp[i-1][j-wt[i-1]]+val[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<dp[n][w]<<endl;
    return 0;
}
/**

5
1 3 8 5 2
1 5 15 10 8
10

*/
