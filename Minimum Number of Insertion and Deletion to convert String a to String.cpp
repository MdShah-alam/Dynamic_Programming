#include<bits/stdc++.h>
using namespace std;

int dp[10005][10005];
int LCS(string s, string t , int n, int m)
{
    if(n==0 || m==0) return 0;
    if(dp[n][m]!=-1) return dp[n][m];

    if(s[n-1]==t[m-1]) return dp[n][m] = 1 + LCS(s , t, n-1 , m-1);
    else return dp[n][m]= max(LCS(s , t , n-1 , m), LCS(s, t, n , m-1));
}
int main()
{
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++)
            dp[i][j]=-1;
    }
    int a=LCS(s,t,n,m);

    cout<<"Minimum Insertion : "<<m-a<<endl;
    cout<<"Minimum Deletion : "<<n-a<<endl;

    return 0;
}
/**

heap
pea

*/
