#include<bits/stdc++.h>
using namespace std;
long long dp[101];
long long tribo(int n)
{
    if(n<=3) return 1;
    if(dp[n]!=-1) return dp[n];

    dp[n]=tribo(n-1)+tribo(n-2)+tribo(n-3);
    return dp[n];
}
/**
1 2 3 4 5 6 7  8  9  10
1 1 1 3 5 9 17 31 57 105
*/
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<=n;i++)
        dp[i]=-1;
    cout<<tribo(n)<<endl;
    return 0;
}
