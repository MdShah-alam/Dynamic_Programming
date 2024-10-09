#include<bits/stdc++.h>
using namespace std;

int dp[205][205];
int minsum(int i,int j,vector<vector<int>>&grid)
{
    int n=grid.size();
    int m=grid[0].size();
    if(i==n-1 && j==m-1) return grid[i][j];

    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int ans1=INT_MAX,ans2=INT_MAX;

    if(i+1<n)
        ans1=minsum(i+1,j,grid);
    if(j+1<m)
        ans2=minsum(i,j+1,grid);

    int ans=min(ans1,ans2);
    ans+=grid[i][j];
    dp[i][j]=ans;
    return ans;
}
int minPathSum(vector<vector<int>>& grid)
{
    int n=grid.size();
    int m=grid[0].size();

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
    }
    return minsum(0,0,grid);
}

int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>grid[i][j];
    }

    cout<<minPathSum(grid)<<endl;
}
/**

3 3
1 3 1
1 5 1
4 2 1

*/
