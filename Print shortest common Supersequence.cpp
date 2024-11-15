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
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

    string k="";

    while(dp[n][m]){
        if(s[n-1]==t[m-1]){
            k+=s[n-1];
            n--;
            m--;
        }
        else{
            if(dp[n-1][m]>dp[n][m-1]){
                n--;
                k+=s[n];
            }
            else{
                m--;
                k+=t[m];
            }
        }
    }

    reverse(k.begin(),k.end());
    cout<<endl<<"shortest common supersequence : "<<k<<endl;

    return 0;
}
/**

abcdgf
acbcf

*/
