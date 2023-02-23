#include<bits/stdc++.h>
using namespace std;

char lcs(char *x,char *y,int n,int m,vector<vector<char>>&dp)
{
    if(m==0 || n==0) return '\0';
    if(x[n-1]==y[m-1])
        return dp[n][m]=x[n-1]+lcs(x,y,n-1,m-1,dp);
    if(dp[n][m]!=-1) return dp[n][m];
    return dp[n][m]=max(lcs(x,y,n,m-1,dp),lcs(x,y,m-1,n,dp));
}

int main()
{
   char x[]="AGGTAB";
   char y[]="GXTXAYB";
   int n=strlen(x);
   int m=strlen(y);
   vector<vector<char>>dp(m+1,vector<int>(n+1,-1));
//   for(int i=0;i<n;i++){
//    for(int j=0;j<m;j++)
//        cout<<dp[i][j]<<" ";
//    cout<<endl;
//   }
   cout<<"LCS is : "<<lcs(x,y,n,m,dp)<<endl;
   return 0;
}
