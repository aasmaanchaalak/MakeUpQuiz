#include <stdio.h>
#include <stdlib.h>

struct Node{
    int val;
    struct Node* next;
    struct Node* prev2;
};

typedef struct Node* NodeAddress;

NodeAddress arrayToLLWithPrev2(int *a, int n){
    NodeAddress p, head, prev, prev2;
    p = malloc(sizeof(struct Node));

    for (int i=0; i<n; i++){
        if (head == NULL){
            p->val = a[i];
            p->next = NULL;
            p->prev2 = NULL;
            head = p;
            prev2 = head;
        } else if (i == 1){
            p->val = a[i];
            p->next = NULL;
            p->prev2 = NULL;
            head->next = p;
            prev = p;
        } else {
            p->val = a[i];
            p->next = NULL;
            p->prev2 = prev2;
            prev->next = p;
            prev2 = prev;
        }
    }

    return head;
}

NodeAddress reverseLLWithPrev2(NodeAddress head){
    NodeAddress prev = NULL;
    NodeAddress curr = head;
    NodeAddress next = NULL;
    NodeAddress prev2 = NULL;

    while (curr != NULL) {
        //storing next
        next = curr->next;
 
        //reversing current node's pointer
        curr->next = prev;
        curr->prev2 = prev2;

 
        // moving pointers one position ahead.
        prev2 = prev;
        prev = curr;
        curr = next;
    }

    return head;
}

int main(){
    int n;
    printf("Enter number of elements- ");
    scanf("%d", &n);

    int a[n];
    for (int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }

    NodeAddress array = arrayToLLWithPrev2(a, n);

    return 0;
}