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
    private:
        pair<bool, int> isBalancedPair(Node* root) {
            if (root == NULL) {
                pair<bool,int> p = make_pair(true,0);
                return p;
            }
            
            pair<bool,int> left = isBalancedPair(root->left);
            pair<bool,int> right = isBalancedPair(root->right);
            
            bool leftHeightBalanced = left.first;
            bool rightHeightBalanced = right.first;
            int height = max(left.second, right.second) + 1;
            bool heightDiff = abs(left.second - right.second) <= 1;
            
            pair<bool,int> p;
            p.second = height;
            if (leftHeightBalanced && rightHeightBalanced && heightDiff) {
                p.first = true;
            } else {
                p.first = false;
            }
            return p;
        }
    public:
    //Function to check whether a binary tree is balanced or not.
    bool isBalanced(Node *root)
    {
        //  Your Code here
        return isBalancedPair(root).first;
    }
};

int main(){

    

    return 0;
}