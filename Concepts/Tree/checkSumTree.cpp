#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

//Should return true if tree is Sum Tree, else false
class Solution
{
   
private:
    pair<bool,int> sumTree(Node* root) {
        if(root == NULL) {
            pair<bool,int> p = make_pair(true, 0);
            return p;
        }

        if(root->left == NULL && root->right == NULL) {
            pair<bool,int> p = make_pair(true, root->data);
            return p;
        }
            
        pair<bool,int> lt = sumTree(root->left);
        pair<bool,int> rt = sumTree(root->right);
        
        int rd = root->data;
        int ld = lt.second + rt.second;
        
        pair<bool,int> p;
        p.first = (rd == ld) && lt.first && rt.first;
        p.second = rd + ld;
        return p;
    }
    public:
    bool isSumTree(Node* root)
    {
         // Your code here
        return sumTree(root).first;
    }
};
int main(){

    

    return 0;
}