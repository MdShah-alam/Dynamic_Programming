#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int arr[n+1];
    int sum=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    int target=sum+m;
    if(target%2!=0){
        cout<<0<<endl;
        return 0;
    }
    target=target/2;
    int dp[n+1][target+1];
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++){
        for(int cap=0;cap<=target;cap++){
            int ans1=dp[i-1][cap];
            if(cap<arr[i])
                dp[i][cap]=ans1;
            else
                dp[i][cap]=max((arr[i]+dp[i-1][cap-[arr[i]]),ans1);
        }
    }
    cout<<dp[n][target]<<endl;
    return 0;
}
