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
int partion( int p, int r)
{
    int pivotIndex = p + rand()%(r - p + 1);
    int pivot;
    int i = p - 1;
    int j;
    pivot = a[pivotIndex];
    swap(&a[pivotIndex], &a[r]);
    for (j = p; j < r; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
 
    }
    swap(&a[i+1], &a[r]);
    
    return i + 1;
}
void quick_sort( int p, int q,int n)
{
    int j;
    if (p < q)
    {
        j = partion( p, q);
        printf("Pivot Element:%d\n",a[j]);
        for(int i=0;i<n;i++){
            printf("%d ",a[i]);
        }
        printf("\n");
        quick_sort( p, j-1,n);
        quick_sort( j+1, q,n);
       
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    // int a[n];
    // for (int i = 0; i < n; i++) {
    //     a[i]=rand();
    // }
    // int n=10;
    a=(int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) {
        a[i]=rand();
    }
    clock_t begin = clock();
    quick_sort( 0, n-1,n);
    clock_t end = clock();  
    double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time Spent:%lf\n",time_spent);
    printf("\nFinal Sorted Array:\n");
    for (int i = 0; i < n; i++)
         printf("%d ", a[i]);
    return 0;
}





