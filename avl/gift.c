#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct AVLNode_t
{
    long long data;
    long long key;
    struct AVLNode_t *left,*right;
    long long height;
}AVLNode;

typedef struct AVL_t
{
    AVLNode *_root;
    unsigned int _size;
}AVL;

AVLNode* _avl_createNode(long long value, long long kunci) {
    AVLNode *newNode = (AVLNode*) malloc(sizeof(AVLNode));
    newNode->data = value;
    newNode->key = kunci;
    newNode->height=1;
    newNode->left = newNode->right = NULL;
    return newNode;
}

AVLNode* _search(AVLNode *root, long long value) {
    while (root != NULL) {
        if (value < root->data)
            root = root->left;
        else if (value > root->data)
            root = root->right;
        else
            return root;
    }
    return root;
}

long long _getHeight(AVLNode* node){
    if(node==NULL)
        return 0; 
    return node->height;
}

long long _max(long long a,long long b){
    return (a > b)? a : b;
}

AVLNode* _rightRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->left;
    pivotNode->left=newParrent->right;
    newParrent->right=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftRotate(AVLNode* pivotNode) {

    AVLNode* newParrent=pivotNode->right;
    pivotNode->right=newParrent->left;
    newParrent->left=pivotNode;

    pivotNode->height=_max(_getHeight(pivotNode->left),
                      _getHeight(pivotNode->right))+1;
    newParrent->height=_max(_getHeight(newParrent->left),
                       _getHeight(newParrent->right))+1;
    
    return newParrent;
}

AVLNode* _leftCaseRotate(AVLNode* node){
    return _rightRotate(node);
}

AVLNode* _rightCaseRotate(AVLNode* node){
    return _leftRotate(node);
}

AVLNode* _leftRightCaseRotate(AVLNode* node){
    node->left=_leftRotate(node->left);
    return _rightRotate(node);
}

AVLNode* _rightLeftCaseRotate(AVLNode* node){
    node->right=_rightRotate(node->right);
    return _leftRotate(node);
}

long long _getBalanceFactor(AVLNode* node){
    if(node==NULL)
        return 0;
    return _getHeight(node->left)-_getHeight(node->right);
}

AVLNode* _insert_AVL(AVL *avl,AVLNode* node,long long value,long long kunci) {
    
    if(node==NULL) // udah mencapai leaf
        return _avl_createNode(value, kunci);
    if(value < node->data)
        node->left = _insert_AVL(avl,node->left,value,kunci);
    else if(value > node->data)
    	node->right = _insert_AVL(avl,node->right,value,kunci);
    
    node->height= 1 + _max(_getHeight(node->left),_getHeight(node->right)); 

    long long balanceFactor=_getBalanceFactor(node);
    
    if(balanceFactor > 1 && value < node->left->data) // skewed kiri (left-left case)
        return _leftCaseRotate(node);
    if(balanceFactor > 1 && value > node->left->data) // 
		return _leftRightCaseRotate(node);
    if(balanceFactor < -1 && value > node->right->data)
        return _rightCaseRotate(node);
    if(balanceFactor < -1 && value < node->right->data)
        return _rightLeftCaseRotate(node);
    
    return node;
}

AVLNode* _findMinNode(AVLNode *node) {
    AVLNode *currNode = node;
    while (currNode && currNode->left != NULL)
        currNode = currNode->left;
    return currNode;
}

AVLNode* _remove_AVL(AVLNode* node,long long value){
    if(node==NULL)
        return node;
    if(value > node->data)
    	node->right=_remove_AVL(node->right,value);
    else if(value < node->data)
    	node->left=_remove_AVL(node->left,value);
    else{
        AVLNode *temp;
        if((node->left==NULL)||(node->right==NULL)){
            temp=NULL;
            if(node->left==NULL) temp=node->right;  
            else if(node->right==NULL) temp=node->left;
            
            if(temp==NULL){
                temp=node;
                node=NULL;
            }
            else
                *node=*temp;   
            
            free(temp);
        }
        else{
            temp = _findMinNode(node->right);
            node->data=temp->data;
            node->right=_remove_AVL(node->right,temp->data);
        }    
    }

	if(node==NULL) return node;
    
    node->height=_max(_getHeight(node->left),_getHeight(node->right))+1;

    long long balanceFactor= _getBalanceFactor(node);
    
    if(balanceFactor>1 && _getBalanceFactor(node->left)>=0) 
        return _leftCaseRotate(node);

    if(balanceFactor>1 && _getBalanceFactor(node->left)<0) 
        return _leftRightCaseRotate(node);
  
    if(balanceFactor < -1 && _getBalanceFactor(node->right)<=0) 
        return _rightCaseRotate(node);

    if(balanceFactor < -1 && _getBalanceFactor(node->right)>0) 
        return _rightLeftCaseRotate(node);
    
    return node;
}

void avl_init(AVL *avl) {
    avl->_root = NULL;
    avl->_size = 0u;
}

bool avl_isEmpty(AVL *avl) {
    return avl->_root == NULL;
}

bool avl_find(AVL *avl, long long value) {
    AVLNode *temp = _search(avl->_root, value);
    if (temp == NULL)
        return false;
    
    if (temp->data == value)
        return true;
    else
        return false;
}

void avl_insert(AVL *avl,long long value,long long kunci){
    if(!avl_find(avl,value)){
        avl->_root=_insert_AVL(avl,avl->_root,value,kunci);
        avl->_size++;
    }

}

void avl_remove(AVL *avl,long long value){
    if(avl_find(avl,value)){
        avl->_root=_remove_AVL(avl->_root,value);
        avl->_size--;
    }

}

void avl_preorder(AVLNode *root) {
    if (root){
        printf("%llu %llu\n",root->key, root->data);
        avl_preorder(root->left);
        avl_preorder(root->right);
    }
}

int primecheck(unsigned long long n)
{
    long long flag = 1;
    for (long long i = 2 ; i <= sqrt(n) ; i++) {
        if(n % i == 0) {
            flag = 0;
            break;
        }
    }

    if (n <= 1)
        flag = 0;
    return flag;
}

int main(){

    AVL avlmain, avlprima;
    avl_init(&avlmain);
    avl_init(&avlprima);

    int n;
    unsigned long long angka, prima, minimal, maks;
    unsigned long long largest, smallest, jumlah, tengah;
    
    scanf("%d", &n);
    for (long long i = 0 ; i < n ; i++) //loop sebanyak n
    {
        scanf("%llu", &angka); //input
        avl_insert(&avlmain, angka, i+1);
        prima = sqrt(angka);
        if (prima % 2 == 0){
            prima += 1;
        }
        tengah = prima;
        while(1)
        {
            if (primecheck(tengah) == 1)
            {
                maks = tengah;
                break;
            }
            tengah -= 2;
        }
        largest = tengah + 2;
        smallest = tengah - 2;
        while (1)
        {
            if (primecheck(largest) == 1)
            {
                maks = largest;
                break;
            }
            largest += 2;
        }
        while (1)
        {
            if (primecheck(smallest) == 1)
            {
                minimal = smallest;
                break;
            }
            smallest -= 2;
        }

        if (maks * tengah <= angka)
        {
            jumlah = maks * tengah;
        }
        else
        {
            jumlah = minimal * tengah;
        }
        avl_insert(&avlprima, jumlah, i+1);
    }
    printf("Hint :\n");
    avl_preorder(avlmain._root);

    printf("Kode Rahasia :\n");
    avl_preorder(avlprima._root);
}