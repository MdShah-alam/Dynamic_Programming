
//int stone_2(int n)
//{
//    if(n==1) return 0;
//    if(dp[n]!=-1) return dp[n];
//    int ans=INF;
//    for(int i=1;i<=k;i++){
//        if(n-i <=0)
//            break;
//        int candidate_ans=stone_2(n-i)+abs(h[n]-h[n-i]);
//        ans=min(ans,candidate_ans);
//    }
//    dp[n]=ans;
//    return ans;
//}

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int INF=1e9;
int h[N],dp[N];

int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>h[i];

    dp[1]=0;

    for(int i=2;i<=n;i++)
        dp[i]=INF;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            int from_stone=i-j;
            if(from_stone<=0)
                break;
            int candidate_ans=dp[from_stone]+abs(h[i]-h[from_stone]);
            dp[i]=min(dp[i],candidate_ans);
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}
