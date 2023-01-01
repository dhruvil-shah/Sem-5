#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int max_dp(int *a,int n);
int max_bf(int *a,int n);
int max1(int arr[], int l, int m, int h);
int max2(int arr[], int l, int h) ;
int k=-1,m=-1;
void main(){
    int a[]={0,4,5,-1,4,8,-15,13,6,0,-81};
     int n=11;
    // scanf("%d",&n);
    // int *a=(int*)malloc(sizeof(int)*n);
    // for (int i = 0; i < n; i++) {
    //     a[i]=rand()%n-(n/2);
    // }
    // for (int i = 0; i < n; i++) {
    //     printf("%d ",a[i]);
    // }
    // printf("\n");

    clock_t begin = clock();
    int mx_bf=max_bf(a,n);
    clock_t end = clock();  
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time Spent For Brute Force:%lf\n",time_spent);



    begin = clock();
    int mx_dp=max_dp(a,n);
    end = clock();  
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time Spent For DP Approach:%lf\n",time_spent);


    begin = clock();
    int mx_divCon=max2(a,0,n-1);
    end = clock();  
    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time Spent For Divide and Conquer Approach:%lf\n",time_spent);


    printf("Max Subarray Sum:%d",mx_dp);
    printf("Max Subarray Sum:%d",mx_divCon);
    
    printf("Indices:%d %d",k,m);


    
}
int max_dp(int *a,int n){
    int temp=0;
    int ans=0;
    int start=0;
    k=0;
    for (int i = 0; i < n; i++)
    {
        temp+=a[i];
        if (temp>ans){
            ans=temp;
            k=start;
            m=i;
        }
        if (temp<0){
            start=i+1;
            temp=0;
        }
    }
    return ans;
}
int max_bf(int *a,int n){
    int temp=0;
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        temp=0;
        for (int j = i; j < n; j++)
        {
            temp+=a[j];
            if (temp>ans)
                ans=temp;   
        }
    }
    return ans;
}
int m1(int a, int b) 
{ 
    return (a > b)? a : b; 
} 
  
int m2(int a, int b, int c) 
{
    return m1(m1(a, b), c);
 } 
   
int max1(int arr[], int l, int m, int h) 
{ 
    int sum = 0; 
    int left_sum = -100000; 
    for (int i = m; i >= l; i--) 
    { 
        sum = sum + arr[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    } 
  
    sum = 0; 
    int right_sum = -100000; 
    for (int i = m+1; i <= h; i++) 
    { 
        sum = sum + arr[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    } 
  
    return left_sum + right_sum; 
} 
  
int max2(int arr[], int l, int h) 
{ 
   if (l == h) 
     return arr[l]; 
   int m = (l + h)/2; 
   return m2(max2(arr, l, m), 
              max2(arr, m+1, h), 
              max1(arr, l, m, h)); 
} 