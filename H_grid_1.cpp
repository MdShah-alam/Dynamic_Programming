#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
string s[1002];
int dp[1002][1002];

int main()
{
    int h,w;
    cin>>h>>w;
    for(int i=0;i<h;i++)
        cin>>s[i];
    dp[0][0]=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++)
        {
            if(s[i][j]=='#'){
                dp[i][j]=0;
                continue;
            }
            if(i>0) dp[i][j]+=dp[i-1][j];
            dp[i][j] %=MOD;
            if(j>0) dp[i][j]+=dp[i][j-1];
            dp[i][j] %=MOD;
        }
    }

    cout<<dp[h-1][w-1]<<endl;
    return 0;
}
