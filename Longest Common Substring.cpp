#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();

    int dp[n+1][m+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(s[i-1]==t[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=0;
        }
    }

    int mx=0;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            mx=max(mx,dp[i][j]);
    }
    cout<<mx<<endl;
    return 0;
}
/**

abulhasan
abuhaslna

*/
