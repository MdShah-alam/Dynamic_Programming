#include<bits/stdc++.h>
using namespace std;

int count_number_of_subset(vector<int>&v, int n, int t)
{
    if(n==0){
        if(t==0)
            return 1;
        else
            return 0;
    }
    return count_number_of_subset(v,n-1,t-v[n-1])+count_number_of_subset(v,n-1,t);
}

int main()
{
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int diff;
    cin>>diff;
    int total = accumulate(v.begin(),v.end(),0);
    int subset=(total+diff)/2;
    int ans1 = count_number_of_subset(v,n,subset);
    int subset1=(total+diff)-subset;
    cout<<subset<<" "<<subset1<<endl;
    int ans2 = count_number_of_subset(v,n,subset1);
    cout<<min(ans1,ans2)<<endl;
    return 0;
}
/**

4
1 1 2 3
1

*/
