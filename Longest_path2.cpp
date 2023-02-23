#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N],visited[N];
vector<int>adj_list[N];

void dfs(int node)
{
    visited[node]=1;
    dp[node]=0;
    for(int adj_node:adj_list[node])
    {
        if(visited[adj_node]==0)
            dfs(adj_node);
        dp[node]=max(dp[node],1+dp[adj_node]);
    }
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj_list[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(visited[i]==0)
            dfs(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++)
        ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
