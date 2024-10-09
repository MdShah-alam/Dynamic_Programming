#include<bits/stdc++.h>
using namespace std;

int findans(int n, vector<int>&v,int target)
{
    if(n==-1){
        if(target==0) return 1;
        return 0;
    }
    return findans(n-1,v,target-v[n])+findans(n-1,v,target+v[n]);
}
int findTargetSumWays(vector<int>&v, int target)
{
    return findans(v.size()-1,v,target);
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];

    cout<<findTargetSumWays(v,target)<<endl;
}
