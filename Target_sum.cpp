#include<bits/stdc++.h>
using namespace std;
const int N=100;
const int M=1000;
int arr[N],dp[N][M];

bool subset(int n,int target)
{
    if(n==0){
        if(target==0) return true;
        else return false;
    }
    if(dp[n][target]!=-1) return dp[n][target];

    int ans1=subset(n-1,target);

    if(arr[n]>target) return dp[n][target]=ans1;

    int ans2=subset(n-1,target-arr[n]);
    return dp[n][target]=ans1 || ans2;
}/**
6 10
2 3 5 6 8 10

*/
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
    }
    bool found=false;
    found=subset(n,m);

    if(found==false){
        cout<<0<<endl;
        return 0;
    }

    for(int i=0;i<=n;i++)
        dp[0][i]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int ans1=dp[i-1][j];
            if(j<=arr[i])
                dp[i][j]=ans1;
            else{
                int ans2=dp[i-1][j-arr[i-1]];
                dp[i][j]=ans1 + ans2;
            }
        }
    }
    cout<<dp[n][m]<<endl;
    return 0;
}
