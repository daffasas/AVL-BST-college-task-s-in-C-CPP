// source code: https://www.geeksforgeeks.org/sorted-array-to-balanced-bst/

#include<stdio.h>
#include<stdlib.h>
 
/* A Binary Tree node */
struct Node{
	
    int data;
    struct Node* left;
    struct Node* right;
    
};
 
struct Node* newNode(int data);
 
/* A function that constructs Balanced Binary Search Tree from a sorted array */
struct Node* sortedArrayToBST(int arr[], int start, int end){
	
    /* Base Case */
    if (start > end)
      return NULL;
 
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    struct Node *root = newNode(arr[mid]);
 
    /* Recursively construct the left subtree and make it
       left child of root */
    root->left =  sortedArrayToBST(arr, start, mid-1);
 
    /* Recursively construct the right subtree and make it
       right child of root */
    root->right = sortedArrayToBST(arr, mid+1, end);
 
    return root;
}
 
/* Helper function that allocates a new node with the
   given data and NULL left and right pointers. */
struct Node* newNode(int data){
	
    struct Node* node = (struct Node*)
                         malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
 
    return node;
    
}
 
/* A utility function to print preorder traversal of BST */
void preOrder(struct Node* node){
	
    if (node == NULL)
        return;
    printf("%d\n", node->data);
    preOrder(node->left);
    preOrder(node->right);
    
}
 

int main(){
	
	int N;
	scanf("%d", &N);
	
    int arr[N];
    
    int i;
    
    for(i = 0; i < N; i++){
    	
    	arr[i] = i + 2;
    	
	}
    
    int size = sizeof(arr)/sizeof(arr[0]);
 
    /* Convert List to BST */
    struct Node *root = sortedArrayToBST(arr, 0, size-1);
    
    preOrder(root);
 
    return 0;
    
}
