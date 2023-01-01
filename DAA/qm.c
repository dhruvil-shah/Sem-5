#include <stdio.h>
#include <time.h>
#include<stdlib.h>
int *a;
void quick_sort(int p, int q,int n);
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int partion( int l, int r,int n)
{
    // printf("Inside");
    int pivotIndex = l + rand()%(r - l+ 1);
    int *lp=(int *)malloc(sizeof(int)*n);
    int k=0,k1=0;
    for (int i = l; i <=r; i++)
    {
        if (a[i]<a[pivotIndex])
        {
            lp[k++]=a[i];
        }
    }
    int z=l+k;
    lp[k++]=a[pivotIndex];
    for (int i = l; i <=r; i++)
    {
        if (a[i]>a[pivotIndex])
        {
            lp[k++]=a[i];
        }
    }
    k=0;
    for(int i=l;i<=r;i++){
        a[i]=lp[k++];
    }
    return z;
}
void quick_sort( int p, int q,int n)
{
    int j;
    if (p < q)
    {
        j = partion( p, q,n);
        // printf("Pivot Element:%d\n",a[j]);
        // for(int i=0;i<n;i++){
        //     printf("%d ",a[i]);
        // }
        // printf("\n");
        quick_sort( p, j-1,n);
        quick_sort( j+1, q,n);
       
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    a=(int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        a[i]=rand();
    }
    clock_t begin = clock();
    quick_sort( 0, n-1,n);
    clock_t end = clock();  
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("Time Spent:%lf\n",time_spent);

    // printf("\nFinal Sorted Array:\n");
    
    // for (int i = 0; i < n; i++)
    //      printf("%d ", a[i]);

    return 0;
}





