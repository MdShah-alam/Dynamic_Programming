#include<bits/stdc++.h>
using namespace std;
const int N=10^5;
int dp[N];
int h[N];
const int INF=2e9;
int n,k;

int stone_2(int n)
{
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans=INF;

    for(int i=1;i<=k;i++){
        if(n-i<=0)
            break;

        int candidate_ans=stone_2(n-i)+abs(h[n]-h[n-i]);
        ans = min(ans , candidate_ans);
    }
    dp[n]=ans;
    return ans;
}

int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++)
        dp[i]=-1;

//    cout<<stone_2(n)<<endl;

    dp[1]=0;
    for(int j=2;j<=n;j++){
        int ans = INF;
        for(int i=1;i<=k;i++){
            if(j-i<=0)
                continue;
            int candidate_ans=dp[j-i]+abs(h[j]-h[j-i]);
            ans = min(ans , candidate_ans);
        }
        dp[j]=ans;
    }
    cout<<dp[n];
}
/**

10 4
40 10 20 70 80 10 20 70 80 60

*/
