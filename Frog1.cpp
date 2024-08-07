#include<bits/stdc++.h>
using namespace std;
int const N=1e5+5;
int h[N];
int dp[N];

int stone(int n)
{
    if(n==1)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    int ans1 = stone(n-1)+abs(h[n]-h[n-1]);
    if(n==2){
        dp[n]=ans1;
        return ans1;
    }

    int ans2 = stone(n-2)+abs(h[n]-h[n-2]);
    int ans = min(ans1,ans2);
    dp[n]=ans;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>h[i];
    for(int i=1;i<=n;i++)
        dp[i]=-1;

    cout<<"Memoization :"<<stone(n)<<endl;
    dp[1]=0;

    for(int i=2;i<=n;i++){
        int ans1=dp[i-1]+abs(h[i]-h[i-1]);
        if(i-2==0){
            dp[i]=ans1;
            continue;
        }
        int ans2=dp[i-2]+abs(h[i]-h[i-2]);
        dp[i]=min(ans1,ans2);
    }
    cout<<"Tabulation :"<<dp[n]<<endl;

    return 0;
}
