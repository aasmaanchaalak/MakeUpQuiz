#include <stdio.h>

int partition(int *arr, int low, int high){
    int pivot = arr[high];
    int i = low-1;

    //loop to segregate elements smaller than pivot
    for (int j = low; j <=high - 1; j++){
        if (arr[j] < pivot){
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }

    //bringing smaller elements to the front
    int temp = arr[high];
    arr[high] = arr[i+1];
    arr[i+1] = temp;
    return (i+1);
}

void quicksort(int *arr, int low, int high){
    if (low < high){
        int p = partition(arr, low, high);
        quicksort(arr, low, p - 1);
        quicksort(arr, p+1, high);
    }
}

void advancedFizzBuzz(int *A, int lenA, char **b, int lenB, int x){
    int sortedA[lenA];
    quicksort(sortedA, 0, lenA-1);

    int l = 0;
    int r = lenA - 1;
    while(l<r){
        if (sortedA[l] + sortedA[r] == x){
            break;
        } else if (sortedA[l] + sortedA[r] < x){
            l++;
        } else{
            r--;
        }
    }

    for (int i=0; i<lenA; i++){
        if (A[i] == sortedA[l]){
            l = i;
        }
        if (A[i] == sortedA[r]){
            r = i;
        }
    }

    printf("\n");
    if (lenA >= lenB){
        l = l%lenB;
        printf("%s ", A[l]);
        r = r%lenB;
        printf("%s", A[r]);
    }
}

int main(){
    int A[] = {3, 100, 7, 8, 16, 19};
    char *B[] = {"gone", "with", "the", "wind"};

    int x;
    printf("Enter number- ");
    scanf("%d", &x);
    advancedFizzBuzz(A, 6, B, 4, x);

    return 0;
}