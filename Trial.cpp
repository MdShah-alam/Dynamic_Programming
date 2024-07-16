#include<bits/stdc++.h>
using namespace std;
const int N=205;
int dp[N][N];
int grid[N][N];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }
    int d = INT_MAX;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=d;
    }
    dp[n][m-1]=0;
    dp[n-1][m]=0;

    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--)
            dp[i][j]=grid[i][j]+min(dp[i+1][j],dp[i][j+1]);
    }
    cout<<dp[0][0]<<endl;
    return 0;
}
