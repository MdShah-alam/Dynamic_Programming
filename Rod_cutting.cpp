#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>price(n);
    for(int i=0;i<n;i++)
        cin>>price[i];
    int dp[n+1];
    for(int i=0;i<=n;i++)
        dp[i]=0;

    for(int i=1;i<=n;i++){
        for(int j=0;j<i;j++)
            dp[i]=max(dp[i],price[j]+dp[i-j+1]);
    }
    for(int i=0;i<=n;i++)
        cout<<dp[i]<<" ";
    cout<<endl;

    cout<<dp[n];
}
/**

8
1 5 6 9 11 12 14 16

*/
