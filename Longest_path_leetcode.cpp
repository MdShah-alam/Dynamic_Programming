#include<bits/stdc++.h>
using namespace std;
const int N=1002;
int matrix[N][N],dp[N][N];

int lip(int i,int j,int n,int m)
{
    if(i<0 || j<0 || i>=n || j>=m)
        return 0;
    if(dp[i][j]!=0) return dp[i][j];
    int current_max=1;

    // check down --> i+1 , j
    if(i+1<n && i+1>=0 && matrix[i+1][j]>matrix[i][j])
        current_max=max(current_max,1+lip(i+1,j,n,m));

    // right neighbour -->i , j+1 ;
    if(j+1<m && j+1>=0 && matrix[i][j+1]>matrix[i][j])
        current_max=max(current_max,1+lip(i,j+1,n,m));

    // left neighbour --> i ,j-1

    if(j-1<m && j-1>=0 && matrix[i][j-1]>matrix[i][j])
        current_max=max(current_max,1+lip(i,j-1,n,m));

    // top neighbour --> i-1 , j
    if(i-1<n && i-1>=0 && matrix[i-1][j]>matrix[i][j])
        current_max=max(current_max,1+lip(i-1,j,n,m));

    dp[i][j]=current_max;
    return current_max;
}/**

3 3

9 9 4
6 6 8
2 1 1

*/
int longest_path(int n,int m)
{
    int Max=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            Max=max(Max,lip(i,j,n,m));
    }
    return Max;
}

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>matrix[i][j];
    }
    cout<<longest_path(n,m)<<endl;
    return 0;
}
