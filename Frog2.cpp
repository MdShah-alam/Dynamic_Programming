#include<bits/stdc++.h>
using namespace std;
int const N=2e5+5;
int h[N];
int dp[N];

int stone(int n,int k)
{
    if(n==1)
        return 0;
    if(dp[n]!=-1)
        return dp[n];

    vector<int>v;
    for(int i=0;i<k;i++){
        if(n-1-i==0)
            break;
        int ans = stone(n-i-1,k)+abs(h[n]-h[n-i-1]);
        v.push_back(ans);
    }

    sort(v.begin(),v.end());
    dp[n]=v[0];
    return v[0];
}

int main()
{
     int n,k;
     cin>>n>>k;
     for(int i=1;i<=n;i++){
        cin>>h[i];
     }

     for(int i=1;i<=n;i++){
        dp[i]=-1;
     }
     cout<<"Memoization :"<<stone(n,k)<<endl;
    dp[1]=0;
    for(int i=2;i<=n;i++){
        vector<int>v;
        for(int j=1;j<=k;j++){
            if((i-j)<1)
                break;
            int ans=dp[i-j]+abs(h[i]-h[i-j]);
            v.push_back(ans);
        }
        sort(v.begin(),v.end());
        dp[i]=v[0];
    }
    cout<<"Tabular :"<<dp[n]<<endl;
     return 0;
}
