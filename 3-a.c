#include <stdio.h>
#include <stdlib.h>

struct binaryTree{
    int val;
    struct binaryTree* left;
    struct binaryTree* right;
};

typedef struct binaryTree * NodeAddress;

NodeAddress createNode(int i){
    NodeAddress new = malloc(sizeof(struct binaryTree));
    new->val = i;
    new->right = NULL;
    new->left = NULL;
    return new;
}

NodeAddress insert(NodeAddress root, int i){
    if (root==NULL){
        return createNode(i);
    } else {
        if ( i > root->val ){
            printf("%d ", root->val);
            if (root->left){
                return insert(root->left, i);
            } else {
                root->left = createNode(i);
            }
            return root->left;
        } else if ( i < root->val ){
            if (root->right){
                return insert(root->right, i);
            } else {
                root->right = createNode(i);
            }
            return root->right;
        }
    }
    return root;
}

NodeAddress arrayToReverseBST(int *a, int n){
    NodeAddress root = NULL;
    for(int i=0; i<n; i++){
        root = insert(root, a[i]);
    }
    return root;
}

void prefixPrint(NodeAddress tree)
{
    if (tree == NULL) // If the tree points to nothing, just return
    {
        return;
    }
    else // Else, print the smaller elements first, then print the node's value, then print the bigger elements
    {
        prefixPrint(tree->left);
        printf("%d ", tree->val);
        prefixPrint(tree->right);
    }
}

int main(){

    //taking number of elements in array
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    for (int i=0; i<n; i++){
        //taking each element in array
        scanf("%d", &a[i]);
    }

    NodeAddress tree = arrayToReverseBST(a, n);

    prefixPrint(tree);
}
