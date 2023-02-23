#include<bits/stdc++.h>
using namespace std;
long long dp[1001];

long long solve(int n,int k)
{
    if(k<=n) return 1;
    if(dp[k]!=-1)
        return dp[k];
    dp[k]=0;
    for(int i=1;i<=n;i++)
    {
        dp[k]+=solve(n,k-i);
    }
    return dp[k];
}
/**

1  2  3  4  5  6   7   8
1, 1, 1, 1, 4, 7, 13, 25, 49,
*/
int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<=k;i++)
        dp[i]=-1;

    cout<<solve(n,k)<<endl;
    return 0;
}
