#include<bits/stdc++.h>
using namespace std;

int dp[100005];
int arr[100005];
int stone(int n)
{
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];

    int ans1=stone(n-1)+abs(arr[n]-arr[n-1]);
    int ans2=INT_MAX;
    if(n-2!=0) ans2=stone(n-2)+abs(arr[n]-arr[n-2]);

    dp[n]=min(ans1,ans2);
    return dp[n];

}
int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
        cin>>arr[i];

    for(int i=0;i<=n;i++)
        dp[i]=-1;

    cout<<stone(n)<<endl;
    return 0;
}
