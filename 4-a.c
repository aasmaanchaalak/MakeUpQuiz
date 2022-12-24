#include <stdio.h>
int size=0;

void heapify(int a[], int L[], int size, int i){
    int max = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < size && L[l] > L[max])
        max = l;
    if (r < size && L[r] > L[max])
      max = r;
    if (max != i)
    {
      int temp = a[i];
      a[i] = a[max];
      a[max] = temp;
      heapify(a, L, size, max);
    }
}

void insert(int a[], int L[], int c){
    if (size == 0){
        a[0] = 0;
        size += 1;
    } else {
        a[size] = size;
        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--){
            heapify(a, L, size, i);
        }
    }
}

void krank(int *L, int *A, int n, int k){
    printf("\n%d", A[L[k]]);
}

void printHeap(int a[], int n){
    for (int i=0; i<n; ++i){
        printf("%d", a[i]);
    }
}

int main(){
    int n,c;
    printf("Enter size- ");
    scanf("%d", &n);
    int a[n], L[n];

    for (int i=0; i<n; i++){
        scanf("%d", &c);
        L[i] = c;
        insert(a, L, c);
    }

    printHeap(a, size);

    int k;
    printf("Enter rank- ");
    scanf("%d", &k);
    krank(L, a, n, k);

    return 0;
}