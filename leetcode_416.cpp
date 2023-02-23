#include<bits/stdc++.h>
using namespace std;
const int N=205;
const int M=105;
int dp[N][M],nums[N];

bool subset(int n,int target)
{
    if(n==0){
        if(target==0) return true;
        else return false;
    }
    if(dp[n][target]!=-1)
        return dp[n][target];

    int ans1=subset(n-1,target);
    if(target<nums[n]){
        dp[n][target]=ans1;
        return ans1;
    }
    int ans2=subset(n-1,target-nums[n]);
    int ans=ans1 or ans2;
    dp[n][target]=ans;
    return ans;

}/**
4
1 5 11 5
*/
int main()
{
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>nums[i];
        sum+=nums[i];
    }
    int target=sum/2;
    if(sum%2!=0){
        cout<<"False"<<endl;
        return 0;
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=target;j++)
            dp[i][j]=-1;
    }
    if(subset(n,target))
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;
    return 0;

}
