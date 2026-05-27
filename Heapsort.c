#include <stdio.h>
#include <time.h>

/* Function to build max heap */
void heapcom(int a[], int n)
{
    int i, j, k, item;

    for(i = 1; i <= n; i++)
    {
        item = a[i];
        j = i;
        k = j / 2;

        while(k >= 1 && item > a[k])
        {
            a[j] = a[k];
            j = k;
            k = j / 2;
        }

        a[j] = item;
    }
}

/* Function to adjust heap */
void adjust(int a[], int n)
{
    int item, i, j;

    j = 1;
    item = a[j];
    i = 2 * j;

    while(i <= n)
    {
        /* Select larger child */
        if(i < n && a[i] < a[i + 1])
        {
            i++;
        }

        if(item < a[i])
        {
            a[j] = a[i];
            j = i;
            i = 2 * j;
        }
        else
        {
            break;
        }
    }

    a[j] = item;
}

/* Heap Sort Function */
void heapsort(int a[], int n)
{
    int i, temp;

    heapcom(a, n);

    for(i = n; i >= 2; i--)
    {
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;

        adjust(a, i - 1);
    }
}

int main()
{
    int i, n, a[20], ch = 1;
    clock_t start, end;
    double cpu_time;

    while(ch)
    {
        printf("\nEnter the number of elements to sort: ");
        scanf("%d", &n);

        printf("Enter the elements:\n");

        for(i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }

        start = clock();

        heapsort(a, n);

        end = clock();

        cpu_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("\nSorted elements are:\n");

        for(i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }

        printf("\n\nTime taken: %f seconds\n", cpu_time);

        printf("\nDo you wish to run again? (1/0): ");
        scanf("%d", &ch);
    }

    return 0;
}