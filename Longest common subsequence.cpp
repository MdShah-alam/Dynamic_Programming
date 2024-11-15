#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int ans(string s , string t , int n , int m)
{
    if(n==0 || m==0) return 0;

    if(dp[n][m]!=-1)  return dp[n][m];

    if(s[n-1]==t[m-1]){
        int ans2=1+ans(s,t, n-1 , m-1);
        dp[n][m]=ans2;
        return dp[n][m];
    }
    else{
        int ans1=max(ans(s,t,n-1,m) , ans(s, t , n , m-1));
        dp[n][m]=ans1;
        return dp[n][m] ;
    }
}
int LCS(string s, string t)
{
    int n=s.size();
    int m=t.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
    }
    return ans(s,t,n,m);
}
int main()
{
    string s,t;
    cin>>s>>t;
    cout<<LCS(s,t)<<endl;

    int n=s.size();
    int m=t.size();
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
    }

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][m]<<endl;

    return 0;
}
/**

abulhasan
ablsanhal

*/
