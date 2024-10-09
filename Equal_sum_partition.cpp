#include<bits/stdc++.h>
using namespace std;

int dp[202][20005];
int subset_sum(int n,int target , vector<int>&v)
{
    if(n==-1){
        if(target==0) return 1;
        return 0;
    }
    if(dp[n][target]!=-1) return dp[n][target];
    int ans1=subset_sum(n-1,target,v);
    if(target<v[n]){
        dp[n][target]=ans1;
        return ans1;
    }
    int ans2=subset_sum(n-1,target-v[n],v);
    dp[n][target]=ans1 || ans2;
    return dp[n][target];
}
bool canPartition(vector<int>&v)
{
    int n=v.size();
    int target=0;
    for(int i=0;i<n;i++)
        target+=v[i];

    if(target%2!=0) return false;

    int sum=target/2;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)
            dp[i][j]=-1;
    }
    return subset_sum(n-1,sum,v);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<canPartition(v)<<endl;
    return 0;
}
