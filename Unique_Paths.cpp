#include<bits/stdc++.h>
using namespace std;
int const N=102;
int dp[N][N];

int unique_path(int n,int m)
{
    if(n==0 && m==0)
        return 1;
    if(dp[n][m]!=-1)
        return dp[n][m];

    int ans=0;
    if(n>0)
        ans+=unique_path(n-1,m);
    if(m>0)
        ans+=unique_path(n,m-1);

   dp[n][m]=ans;
   return ans;
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

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            dp[i][j]=0;
    }
    dp[0][0]=1;
    if(n==1 && m==1){
        cout<<1<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
          int ans=0;
          if(i!=0){
            ans+=dp[i-1][j];
          }
          if(j!=0){
            ans+=dp[i][j-1];
          }
          if(ans!=0)
            dp[i][j]=ans;
        }
    }
    cout<<dp[n-1][m-1]<<endl;
    return 0;
}
