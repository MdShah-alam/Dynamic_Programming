#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int total = accumulate(v.begin(),v.end(),0);

    int s=total/2;
    int dp[n+1][total+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=total;j++)
            dp[i][j]=0;
    }

    for(int i=0;i<=n;i++)
        dp[i][0]=1;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=s;j++){
            if(j>=v[i-1])
                dp[i][j]=dp[i-1][j] || dp[i-1][j-v[i-1]];
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    vector<int>v1;
    for(int i=0;i<=s;i++){
        if(dp[n][i])
            v1.push_back(i);
    }
    int maxm=INT_MAX;
    for(int x:v1){
        maxm=min(maxm,(total-2*x));
    }
    cout<<maxm<<endl;
    return 0;
}
/**

4
1 6 11 5

*/
