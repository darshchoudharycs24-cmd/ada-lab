#include <stdio.h>
#include <time.h>
void swap(int *a, int *b)
{
    int temp= *a;
    *a= *b;
    *b = temp;
}
int partition(int arr[],int low, int high)
{
    int pivot =arr[low];
    int i = low+1;
    int j=high;
    while(1)
    {
        while( i<=high && arr[i]<=pivot)i++;
        while(arr[j]>pivot) j--;
        if(i>=j)break;
        swap(&arr[i],&arr[j]);
    }
    swap(&arr[low],&arr[j]); return j;
}
void quicksort(int arr[],int low, int high)
{
    if(low<high)
    {
        int P=partition(arr,low,high);
        quicksort(arr,low,P-1);
        quicksort(arr,P+1,high);
    }
}
int main()
{
    int i,n,k;
    printf("Enter the number of elements");
    scanf("%d",&n);
    int arr[n],temp[n];
    printf("Enter elements:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    clock_t start=clock();
    for(k=0;k<50000;k++)
    {
        for(i=0;i<n;i++)
        {
            temp[i]=arr[i];
        }
        quicksort(temp,0,n-1);
    }
    clock_t end=clock();
    double tt=(double)(end-start)/CLOCKS_PER_SEC;
    printf("Sorted Array");
    for(i=0;i<n;i++)
    {
        printf("%d", temp[i]);
    }
    printf("\nTime taken %f", tt);
    return 0;
}