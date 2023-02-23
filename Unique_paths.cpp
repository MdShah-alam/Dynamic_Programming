#include<bits/stdc++.h>
using namespace std;
const int N=101;
int dp[N][N];

int unique_path(int n,int m)
{
    if(n==0 && m==0)
        return 1;
    if(dp[n][m]!=-1)
        return dp[n][m];

    int ans=0;

    if(n>0) ans+=unique_path(n-1,m);
    if(m>0) ans+=unique_path(n,m-1);

    return dp[n][m]=ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            dp[i][j]=-1;
    }
    cout<<unique_path(n-1,m-1)<<endl;
    return 0;
}
