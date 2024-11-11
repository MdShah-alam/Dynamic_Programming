#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>length(m),price(m);

    for(int i=0;i<m;i++)
        cin>>length[i];
    for(int i=0;i<m;i++)
        cin>>price[i];

    int dp[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++)
            dp[i][j]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(length[i-1]<=j){
                dp[i][j]=max(dp[i][j-length[i-1]]+price[i-1],dp[i-1][j]);
            }
            else{
                dp[i][j]=dp[i-1][j];
            }
        }
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }
    cout<<dp[m][n]<<endl;
    return 0;
}

/**

7 7
1 2 3 4 5 6 7 8
1 5 8 9 11 12 14 16

4 4
1 2 3 4
5 6 8 10

*/
