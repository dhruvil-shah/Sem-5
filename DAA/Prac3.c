#include<stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *a, int *b);
void merge(int *a,int i1,int j1,int i2,int j2);
void mergesort(int *a,int i,int j);
void mergeArrays(int *arr1, int *arr2, int n1,int n2);

void main(){
    FILE *fp;
    fp=fopen("Prac3.txt","r");
    FILE *fp1;
    fp1=fopen("prac3_out.txt","w");
    FILE *fp2;
    fp2=fopen("prac3_inter.txt","wa");
    char dataToBeRead[10];
    int ct;
    int *a=(int*)malloc(sizeof(int)*500);
    int *fa=(int*)malloc(sizeof(int)*500);
    int ind=0;
    for (int i = 0; i < 10; i++)
    {
    ct=0;
    int *a1=(int*)malloc(sizeof(int)*50);
    while(fgets ( dataToBeRead, 50, fp ) != NULL){
        if(ct==49){
            ind++;
            a1[ct++]=atoi(dataToBeRead);
            break;
        }
        ind++;
        a1[ct++]=atoi(dataToBeRead);
    }
    mergesort(a1, 0, 49);
    mergeArrays(fa,a1,ind-50,50);
     for(int j=0;j<ind;j++){
    fprintf(fp2,"%d\n",fa[j]);
    }
    fprintf(fp2,"\n==========================\n");
}
    for(int i=0;i<500;i++)
    fprintf(fp1,"%d\n",fa[i]);
    
    fclose(fp);
    fclose(fp1);
    fclose(fp2);
}
void mergesort(int *a,int i,int j)
{
    int mid;
    if(i<j)
    {
    mid=(i+j)/2;
    mergesort(a,i,mid);
    mergesort(a,mid+1,j); 
    merge(a,i,mid,mid+1,j); 
}
}
 
void merge(int *a,int i1,int j1,int i2,int j2)
{
    int temp[50]; 
    int i,j,k;
    i=i1; 
    j=i2; 
    k=0;
    while(i<=j1 && j<=j2)
    {
    if(a[i]<a[j])
    temp[k++]=a[i++];
    else
    temp[k++]=a[j++];
    }
    while(i<=j1)
    temp[k++]=a[i++];
    while(j<=j2)
    temp[k++]=a[j++];
    
    for(i=i1,j=0;i<=j2;i++,j++)
    a[i]=temp[j];
}
void mergeArrays(int *arr1, int *arr2, int n1,
                             int n2)
{
    int *arr3=(int *)malloc(sizeof(int)*(n1+50));
    int i = 0, j = 0, k = 0;
    while (i<n1 && j <n2)
    {
        if (arr1[i] < arr2[j])
            arr3[k++] = arr1[i++];
        else
            arr3[k++] = arr2[j++];
    }
 
    while (i < n1)
        arr3[k++] = arr1[i++];
 
    while (j < n2)
        arr3[k++] = arr2[j++];
    for (i = 0; i < n1+50; i++)
    {
       arr1[i]=arr3[i];
    }
    
}
