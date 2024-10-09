#include<bits/stdc++.h>
using namespace std;
int dp[100005];
int arr[100005];
int INF=2e9;
int stone(int n, int k)
{
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];
    int ans = INF;
    for(int i=1;i<=k;i++){
        if(n-i<=0) break;
        int ans1=stone(n-i,k)+abs(arr[n]-arr[n-i]);
        ans=min(ans,ans1);
    }
    dp[n]=ans;
    return dp[n];
}

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>arr[i];
    for(int i=0;i<=n;i++)
        dp[i]=-1;
    //cout<<stone(n,k)<<endl;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int ans=INF;
        for(int j=1;j<=k;j++){
            if(i-j<=0) break;
            int ans1=dp[i-j]+abs(arr[i]-arr[i-j]);
            ans = min(ans1,ans);
        }
        dp[i]=ans;
    }
    cout<<dp[n]<<endl;
    return 0;
}
