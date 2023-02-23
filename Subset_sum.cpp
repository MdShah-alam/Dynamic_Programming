#include<bits/stdc++.h>
using namespace std;
const int N=105;
const int M=1e5;
int dp[N][M], nums[N];

//bool subset(int n,int target)
//{
//    if(n==0){
//        if(target==0) return 1;
//        else return 0;
//    }
//    if(dp[n][target]!=-1)
//        return dp[n][target];
//
//    int ans1=subset(n-1,target);
//    if(target<nums[n]){
//        dp[n][target]=ans1;
//        return ans1;
//    }
//    int ans2=subset(n-1,target-nums[n]);
//    int ans=ans1 or ans2;
//    dp[n][target]=ans;
//    return ans;
//
//}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>nums[i];

//    for(int i=0; i<=n; i++)
//    {
//        for(int j=0; j<=m; j++)
//            dp[i][j]=-1;
//    }
    //if(subset(n,m))
    dp[0][0]=1;
    for(int i=1; i<=m; i++)
        dp[0][i]=0;
//    for(int i=1; i<=n; i++)
//    {
//        for(int j=1; j<=m; j++)
//        {
//            int ans1=dp[i-1][j];
//            if(j<nums[i])
//                dp[i][j]=ans1;
//            else{
//                int ans2=dp[i-1][j-nums[i]];
//                dp[i][j]=ans1 || ans2;
//            }
//        }
//    }
        for(int i = 1 ; i <= n ;i++) {
        for(int target = 1 ; target <= m ; target++) {

            // 2.1. calculate answer from smaller sub-problems
            int ans1 = dp[i-1][target];
            if(target < nums[i]) {
                dp[i][target] = ans1;
            }
            else {
                int ans2 = dp[i-1][target - nums[i]];
                dp[i][target] = ans1 or ans2;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    if(dp[n][m]==1)
        cout<<"True"<<endl;
    else
        cout<<"False"<<endl;

    return 0;
}
