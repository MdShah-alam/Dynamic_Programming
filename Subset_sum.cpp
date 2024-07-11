#include<bits/stdc++.h>
using namespace std;
int const N=104;
int const target=1e5+5;
int ar[N] , dp[N][target];

int subsetsum(int n,int t)
{
    if(n==0){
        if(t==0)
            return 1;
        else
            return 0;
    }
    if(t==0)
        return 1;
    if(dp[n][t]!=-1)
        return dp[n][t];

    int ans1=subsetsum(n-1,t);
    if(t<ar[n]){
        return dp[n][t]=ans1;
    }
    int ans2 = subsetsum(n-1,t-ar[n]);
    dp[n][t]=ans1 || ans2 ;
    return dp[n][t];
}

int main()
{
    int n,t;
    cin>>n>>t;
    for(int i=1;i<=n;i++)
        cin>>ar[i];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=t;j++)
            dp[i][j]=-1;
    }
    cout<<subsetsum(n,t)<<endl;

    dp[0][0]=1;
    for(int i=1;i<=t;i++){
        dp[0][i]=0;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=t;j++){
            int ans1=dp[i-1][j];
            if(j<ar[i]){
                dp[i][j]=ans1;
                cout<<" 'i :"<<i<<" ,j:"<<j<<" , "<<dp[i][j]<<" '";
                continue;
            }
            int ans2=dp[i-1][j-ar[i]];
            dp[i][j]=ans1 || ans2;
            cout<<" 'i :"<<i<<", j:"<<j<<" , "<<dp[i][j]<<" '";
        }
        cout<<endl;
    }
    cout<<dp[n][t]<<endl;
    return 0;
}
