#include<bits/stdc++.h>
using namespace std;
const int N=101;
int dp[N][N];

int uniquePaths(int m, int n)
{
    if(m==0 && n==0) return 1;
    if(dp[m][n]!=-1) return dp[m][n];

    int ans=0;
    if(m>0)
        ans+=uniquePaths(m-1,n);
    if(n>0)
        ans+=uniquePaths(m,n-1);

    dp[m][n]=ans;
    return dp[m][n];

}

int main()
{
    int row,col;
    cin>>row>>col;

    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++)
            dp[i][j]=-1;
    }

    cout<<uniquePaths(row-1,col-1)<<endl;
    return 0;
}
