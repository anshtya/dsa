#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        // code here 
        if (node == NULL) return 0;
        
        int left = height(node->left);
        int right = height(node->right);
        
        int height = max(left, right) + 1;
        return height;
    }
};

int main(){

    

    return 0;
}