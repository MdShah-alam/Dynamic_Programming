#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s;
    t=s;
    reverse(t.begin(),t.end());

    int n=s.size();

    int dp[n+1][n+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
            dp[i][j]=0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    cout<<dp[n][n]<<endl;
    return 0;
}
/**

agbcba


*/
