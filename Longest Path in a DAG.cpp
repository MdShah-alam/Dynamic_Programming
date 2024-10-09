#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>parent_list[N];
int dp[N],root,target;

int longest_distance(int node)
{
    if(node==root) return 0;

    if(dp[node]!=-1) return dp[node];

    int ans=INT_MAX;
    for(int parent:parent_list[node]){
        int parent_dist = longest_distance(parent);
        ans = min(ans,parent_dist);
    }
    dp[node]=ans+1;
    return dp[node];
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        parent_list[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        dp[i]=-1;

    cin>>root>>target;
    cout<<longest_distance(target)<<endl;

    return 0;
}/**

4 4

1 3
3 4
1 4
4 2

1 2

*/
