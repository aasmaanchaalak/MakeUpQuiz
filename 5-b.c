#include <stdio.h>
#include <stdlib.h>

int partition(int *arr, int k, int low, int high){
    int pivot = arr[high];
    int i = low-(k/2);

    //loop to segregate elements smaller than pivot
    for (int j = low; j <=high - 1; j+=((k/2))){
        if (arr[j] < pivot){
            i+=(k/2);
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    //bringing smaller elements to the front
    int temp = arr[high];
    arr[high] = arr[i+(k/2)];
    arr[i+(k/2)] = temp;
    return (i+(k/2));
}

void quicksort(int *arr, int k, int low, int high){
    if (low < high){
        int p = partition(arr, k, low, high);
        quicksort(arr, k, low, p - (k/2));
        quicksort(arr, k, p+(k/2), high);
    }
}

int* returnUntouched(int *a, int n, int k){
    quicksort(a, k, 0, n-1);
    printf("Output- \n");
    int *M = malloc((n/k)*sizeof(int));
    int count  = 0;
    for (int i=(k/2); i<n; i+=k){
        M[count] = a[i];
        printf("%d\n", M[count]);
        count += 1;
    }
    return M;
};

int main(){
    int k;
    printf("Enter chunk size: ");
    scanf("%d", &k);

    int n;
    printf("\nEnter number of elements: ");
    scanf("%d", &n);

    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    returnUntouched(a, n, k);
}