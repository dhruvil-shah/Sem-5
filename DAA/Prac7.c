#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n=11;
int a[]={30,35,15,5,10,20,25,10,30,30,40};
long recur_mcm(int i,int j);
long memo_mcm(int i,int j,int dp[n][n]);
long dp_mcm();


void main(){
    for (int  i = 0; i < n-1; i++)
    {
        printf("%d * %d || ",a[i],a[i+1]);
    }
    
    clock_t begin = clock();
    long ans_rec=recur_mcm(1,n-1);
    clock_t end = clock();  
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("\nTime Spent For Recursion Approach:%lf\n",time_spent);
    printf("Ans(Recur):%d\n",ans_rec);


    int dp[n][n];
    for (int i = 0; i <=n; i++)
    {
        for (int j = 0; j <=n; j++)
        {
            dp[i][j]=-1;
        }
    }
    
    begin = clock();
    long ans_memo=memo_mcm(1,n-1,dp);
    end = clock();  
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("\nTime Spent For Memoization Approach:%lf\n",time_spent);
    printf("Ans(Memo):%d\n",ans_memo);

    begin = clock();
    long ans_dp=dp_mcm();
    end = clock();  
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    // printf("\nTime Spent For DP Approach:%lf\n",time_spent);
    printf("Ans:%d",ans_dp);
}




long recur_mcm(int i,int j){
    if(i>=j)
        return 0l;
    long ans=1000000000;
    for (int  k = i; k <=j-1; k++)
    {
        long temp_ans=recur_mcm(i,k)+recur_mcm(k+1,j)+a[i-1]*a[j]*a[k];
        if (temp_ans<ans)
        {
            ans=temp_ans;
        }
    }
    return ans; 
}


long memo_mcm(int i,int j,int dp[n][n]){
    if(i>=j)
        return 0l;
    if (dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    
    long ans=1000000000;
    for (int  k = i; k <=j-1; k++)
    {
        long temp_ans=memo_mcm(i,k,dp)+memo_mcm(k+1,j,dp)+a[i-1]*a[j]*a[k];
        if (temp_ans<ans)
        {
            ans=temp_ans;
        }
    }
    return dp[i][j]=ans; 
}

long dp_mcm(){
    long dp[n][n];
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;
    for (int len = 2; len < n; len++){
        for (int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;
            dp[i][j] = 10000000l;
            for (int k = i;k <= j - 1;k++)
            {
                int z =a[i - 1] * a[k] * a[j]+dp[i][k] + dp[k + 1][j] ;
                if (z < dp[i][j])
                    dp[i][j] = z;
            }
        }
    }
    // for (int  i = 0; i<n; i++)
    // {
    //     for (int  j = 0; j <n; j++)
    //     {
    //         printf("%d ",dp[i][j]);
    //     }
    //     printf("\n");
        
    // }
    
    return dp[1][n - 1];
}