#include<bits/stdc++.h>
using namespace std;
const int N=10^5;
int dp[N];
int h[N];

int stone(int n)
{
    //base case
    if(n==1) return 0;
    if(dp[n]!=-1) return dp[n];

    int ans1=stone(n-1)+abs(h[n]-h[n-1]);
    if(n==2){
        dp[n]=ans1;
        return ans1;
    }
    int ans2=stone(n-2)+abs(h[n]-h[n-2]);
    int ans=min(ans1,ans2);
    dp[n]=ans;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    cout<<endl;

    for(int i=0;i<n+1;i++)
        dp[i]=-1;

//    cout<<stone(n)<<endl;

    dp[1]=0;

    for(int i=2;i<=n;i++){
        int ans1 = dp[i-1] + abs(h[n]-h[n-1]);
        if(n==2){
            dp[n]=ans1;
            break;
        }
        int ans2 = dp[i-2] + abs(h[n]-h[n-2]);
        int ans = min(ans1 , ans2);
        dp[i]=ans;
    }

    cout<<dp[n]<<endl;
    return 0;
}
/**

4
10 30 40 20

*/
