#include<bits/stdc++.h>
using namespace std;
int const N=1e8;
int dp[N];

int tribo(int n)
{
    if(n<=3)
        return 1;
    if(dp[n]!=-1)
        return dp[n];

    int ans = tribo(n-1)+tribo(n-2)+tribo(n-3);
    dp[n]=ans;
    return ans;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
        dp[i]=-1;
    cout<<tribo(n)<<endl;
    return 0;
}
