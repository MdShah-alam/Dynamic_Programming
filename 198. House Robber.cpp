#include<bits/stdc++.h>
using namespace std;
const int N=101;
int dp[N];
int h[N];

int rob(int n)
{
    if(n==1) h[1];
    if(dp[n]!=-1)
        return dp[n];

    int ans1=rob(n-1)+h[n];

    if(n==2){
        dp[n]=ans1;
        return dp[n];
    }
    int ans2=rob(n-2)+h[n];
    cout<<ans1<<" "<<ans2<<" "<<n<<endl;
    int ans = max(ans1,ans2);
    dp[n] = ans;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }

    for(int i=1;i<=n;i++)
        dp[i]=-1;

    for(int i=1;i<=n;i++)
        cout<<h[i]<<" "<<dp[i]<<endl;

    cout<<rob(n)<<endl;
}

/**
1 <= nums.length <= 100
0 <= nums[i] <= 400 */
