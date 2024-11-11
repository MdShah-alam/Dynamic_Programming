#include<bits/stdc++.h>
using namespace std;

bool subset_sum(int i, vector<int>&v , int t)
{
    if(i==v.size()){
        if(t==0)
            return true;
        return false;
    }

    if(v[i]<=t)
        return (subset_sum(i+1,v,t-v[i]) || subset_sum(i+1,v,t));
    return subset_sum(i+1,v,t);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int sum;
    cin>>sum;
    cout<<subset_sum(0,v,sum)<<endl;

    int dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;i<=sum;j++){
            if(v[i-1]<=j)
                dp[i][j]=dp[i-1][j-v[i-1]] || dp[i-1][j];
            else
                dp[i][j]=dp[i-1][j];
        }
    }

    cout<<dp[n][sum]<<endl;
    return 0;
}
/**

5
2 3 7 8 10
11

*/
