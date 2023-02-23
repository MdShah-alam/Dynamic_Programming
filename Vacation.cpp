
//int fun(int day,int current_task)
//{
//    if(day==1)
//        return happiness[day][current_task];
//
//    if(dp[day][current_task]!=-1)
//        return dp[day][current_task];
//
//    int max_profit=0;
//    for(int last_task=1;last_task<4;last_task++)
//    {
//        if(last_task!=current_task)
//        {
//            int candidata_task=fun(day-1,last_task)+happiness[day][current_task];
//            max_profit=max(max_profit,candidata_task);
//        }
//    }
//    dp[day][current_task]=max_profit;
//    return dp[day][current_task];
//
//}
//
//int ans_1=fun(n,1);
//int ans_2=fun(n,2);
//int ans_3=fun(n,3);

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int dp[N][4],happiness[N][4];

int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<4;j++)
            cin>>happiness[i][j];
    }
    for(int task=1;task<4;task++)
        dp[1][task];

    for(int day=1;day<=n;day++)
    {
        for(int current_task=1;current_task<4;current_task++)
        {
            int max_task=0;
            for(int last_task=1;last_task<4;last_task++)
            {
                if(current_task!=last_task)
                {
                   int candidate_task=dp[day-1][last_task]+happiness[day][current_task];
                    max_task=max(max_task,candidate_task);
                }
            }
            dp[day][current_task]=max_task;
        }
    }
    cout<<max({dp[n][1],dp[n][2],dp[n][3]})<<endl;
    return 0;
}
