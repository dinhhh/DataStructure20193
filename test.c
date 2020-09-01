// C implementation to find leaf count of a given Binary tree 
#include <stdio.h> 
#include <stdlib.h> 
  
/* A binary tree node has data, pointer to left child  
   and a pointer to right child */
struct node  
{ 
    int data; 
    struct node* left; 
    struct node* right; 
}; 
  
/* Function to get the count of leaf nodes in a binary tree*/
unsigned int getLeafCount(struct node* node) 
{ 
  if(node == NULL)        
    return 0; 
  if(node->left == NULL && node->right==NULL)       
    return 1;             
  else 
    return getLeafCount(node->left)+ 
           getLeafCount(node->right);       
} 
// Function to calculate sum of odd numbers in tree
int oddSum(struct node* root){
    if(root == NULL)
        return 0;
    if(root->data %2 == 1)
        return oddSum(root->left) + oddSum(root->right) + root->data;
    else    
        return oddSum(root->left) + oddSum(root->right);
}
// Function find MAX NUMBER in tree
int maxNode(struct node* root){
    if(root == NULL)
        return -9999;
    int res = root->data;
    int lres = maxNode(root->left);
    int rres = maxNode(root->right);
    if (lres < res && rres < res)  
        return res; 
    else if (rres > res && rres > lres)  
        return rres;  
    else
        return lres;   
}
// Function find MAX EVEN NUMBER in tree
int findMaxEven(struct node* root){
    if(root == NULL)
        return -9999;
    int res = root->data;
    int lres = findMaxEven(root->left);
    int rres = findMaxEven(root->right);
    if(res % 2 == 1){
        if(lres > rres)
            return lres;
        else
            return rres;
    }
    else{
        if (lres < res && rres < res)  
            return res; 
        else if (rres > res && rres > lres)  
            return rres;  
        else
            return lres;   
    }
}
/* Helper function that allocates a new node with the 
   given data and NULL left and right pointers. */
struct node* newNode(int data)  
{ 
  struct node* node = (struct node*) 
                       malloc(sizeof(struct node)); 
  node->data = data; 
  node->left = NULL; 
  node->right = NULL; 
    
  return(node); 
} 
  
/*Driver program to test above functions*/  
int main() 
{ 
  /*create a tree*/  
  struct node *root = newNode(1); 
  root->left        = newNode(2); 
  root->right       = newNode(3); 
  root->left->left  = newNode(4); 
  root->left->right = newNode(5);     
    
  /*get leaf count of the above created tree*/
  printf("Leaf count of the tree is %d\n", getLeafCount(root)); 
  int max = findMaxEven(root);
  printf("max = %d\n", max);  
  getchar(); 
  return 0; 
} 