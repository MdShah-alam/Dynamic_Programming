#include<bits/stdc++.h>
using namespace std;
const int N=101;
int dp[N][N],arr[N][N];

int minimun_path(int n,int m)
{
    if(n==0 && m==0) return arr[0][0];

    if(dp[n][m]!=-1) return dp[n][m];

    int a,b;
    if(n>0) a= minimun_path(n-1,m)+arr[n-1][m-1];
    if(m>0) b= minimun_path(n,m-1)+arr[n-1][m-1];

    dp[n][m] = min(a,b);
    return dp[n][m];
}/**
3 3

1 3 1
1 5 1
4 2 1

*/
int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>arr[i][j];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
    }

    cout<<minimun_path(n,m)<<endl;
    return 0;
}
