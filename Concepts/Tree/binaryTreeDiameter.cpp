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

class Solution {
    private:
        // int treeHeight(Node* root) {
        //     if (root == NULL) return 0;
        //     int left = treeHeight(root->left);
        //     int right = treeHeight(root->right);
        //     int ans = max(left,right) + 1;
        //     return ans;
        // }
        int diameterOrHeight(Node* root, int* height) {
            int leftH, rightH = 0;
            if(root == NULL) {
                *height = 0;
                return 0;
            }
            
            int leftD = diameterOrHeight(root->left, &leftH);
            int rightD = diameterOrHeight(root->right, &rightH);
            *height = max(leftH, rightH) + 1;
            return max(leftH+1+rightH, max(leftD,rightD));
        }
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        // Your code here
        
        //O(n^2), first for diameter and then for height
        // if (root == NULL) return 0;
        // int left = diameter(root->left);
        // int right = diameter(root->right);
        // int height = treeHeight(root->left) + 1 + treeHeight(root->right);
        // int ans = max(height, max(left,right));
        // return ans;
        
        //O(n), calculating height and diameter at same time
        int height = 0;
        return diameterOrHeight(root, &height);
    }
};

int main(){

    

    return 0;
}