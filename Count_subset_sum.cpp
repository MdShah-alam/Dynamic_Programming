#include<bits/stdc++.h>
using namespace std;
const int N=1005;
const int W=1005;
int dp[N][W];

int count_subset(int i, vector<int>&v, int t)
{
    if(i==v.size()){
        if(t==0)
            return 1;
        return 0;
    }
    if(dp[i][t]!=-1) return dp[i][t];

    if(t<v[i]){
        dp[i][t]=count_subset(i+1,v,t);
        return dp[i][t];
    }
    dp[i][t]=count_subset(i+1,v,t-v[i])+count_subset(i+1,v,t);
    return dp[i][t];
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
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)
            dp[i][j]=-1;
    }
    cout<<count_subset(0,v,sum)<<endl;
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int j=1;j<=sum;j++)
        dp[0][j]=0;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=sum;j++){
            if(v[i-1]<=j){
                dp[i][j]=dp[i-1][j-v[i-1]]+dp[i-1][j];
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<dp[n][sum]<<endl;
    return 0;
}
/**

5
2 3 7 8 10
10

*/
