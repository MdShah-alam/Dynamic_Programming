#include<bits/stdc++.h>
using namespace std;
const int N=55;
const int M=1005;
const int MOD=100000007;
int dp[N][M],limit[N],coin[N];

int main()
{
    int t,tst=0;
    cin>>t;
    while(t--){
        int n,K;
        cin>>n>>K;
        for(int i=1;i<=n;i++)
            cin>>coin[i];
        for(int i=1;i<=n;i++)
            cin>>limit[i];
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int target=0;target<=K;target++){
                dp[i][target]=dp[i-1][target];

                for(int j=1;j<=limit[i];j++)
                {
                    if(target<j*coin[i])
                        break;
                    int ret=dp[i-1][target-j*coin[i]];
                    dp[i][target]=(ret+dp[i][target])%MOD;
                }
            }
        }
        cout<<"Case "<<++tst<<": "<<dp[n][K]<<endl;
    }
}
