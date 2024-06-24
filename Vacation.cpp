#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int happiness[N][4];
int dp[N][4];

int fun(int day , int current_task)
{
    //1. handle base case
    if(day == 1)
        return happiness[day][current_task];

    //2. if answer is already calculated return it
    if(dp[day][current_task] != -1)
        return dp[day][current_task];

    int max_profit = 0;

    //3. calculate the answer from smaller sub problems
    for(int last_task = 1; last_task<=3; last_task++){
        if(last_task!=current_task){
            int candidate_profit=fun(day-1,last_task)+happiness[day][current_task];
            max_profit=max(max_profit,candidate_profit);
        }
    }
    dp[day][current_task]=max_profit;
    return max_profit;
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=3;j++)
            cin>>happiness[i][j];
    }

//    for(int i=1;i<=n;i++){
//        for(int j=1;j<=3;j++)
//            dp[i][j]=-1;
//    }
//    int ans1=fun(n,1);
//    int ans2=fun(n,2);
//    int ans3=fun(n,3);
//    cout<<max({ans1,ans2,ans3})<<endl;



    return 0;
}
/**

3
10 40 70
20 50 80
30 60 90

7
6 7 8
8 8 3
2 5 2
7 8 6
4 6 8
2 3 4
7 5 1

*/
