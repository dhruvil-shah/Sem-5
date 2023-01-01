#include<stdio.h>
#include<stdlib.h>
int getMaxProfit(int *weight, int *profit,int n,int max_capacity);
int max(int a,int b);

void main(){
    int weight[]={1,2,5,6,7};
    int profit[]={1,6,18,22,28};
    int max_capacity=10;
    int ans=getMaxProfit(weight,profit,5,10);
    printf("%d",ans);
}
int getMaxProfit(int *weight, int *profit,int n,int max_capacity){
    int dp[max_capacity+1][n+1];
    for (int i = 0; i <=max_capacity; i++)
    {
        for (int  j = 0; j <= n; j++)
            dp[i][j]=0;
    }
    for (int  i = 1; i<=max_capacity; i++)
    {
        for (int  j = 1; j <= n; j++)
        {
            if(weight[j-1]<=i){
                dp[i][j]=max(dp[i][j-1],profit[j-1]+dp[i-weight[j-1]][j-1]);
            }else{
                dp[i][j]=dp[i][j-1];
            }
        }
    }
    for (int i = 0; i <=max_capacity; i++)
    {
        for (int  j = 0; j <= n; j++)
            printf("%d ",dp[i][j]);
        printf("\n");
    }
    return dp[max_capacity][n];
}
int max(int a,int b){
    return a>=b?a:b;
}