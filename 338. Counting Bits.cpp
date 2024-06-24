#include<bits/stdc++.h>
using namespace std;

 vector<int>countBits(int n)
 {
     vector<int>v;
     v.push_back(0);
     for(int i=1;i<=n;i++){
        if(i%2==0){
            v.push_back(v[i/2]);
        }
        else{
            v.push_back(v[i/2]+1);
        }
     }
     return v;
 }

int main()
{
    int n;
    cin>>n;

    vector<int>v=countBits(n);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;

    return 0;
}
