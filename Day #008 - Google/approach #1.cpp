#include <bits/stdc++.h>
using namespace std;

class Unival{
public:
    
    struct tree
    {
        int val;
        tree *left, *right;
    }*root;
    
    Unival()
    {
        root=nullptr;
    }
    
    tree* newNode(int value)
    {
        tree* ptr=new tree;
        ptr->val=value;
        ptr->left=ptr->right=nullptr;
        return ptr;
    }
    
    void create()
    {
        /*
           0
          / \
         1   0
            / \
           1   0
          / \
         1  1
        */
        root=newNode(0);
        root->left=newNode(1);
        root->right=newNode(0);
        root->right->left=newNode(1);
        root->right->right=newNode(0);
        root->right->left->left=newNode(1);
        root->right->left->right=newNode(1);
    }
    
    bool check(tree* root, int value)
    {
        // this function will check whether the subtree is unival or not
        
        if(!root) return true;
        if(root->val == value)
            return (check(root->left,root->val) & check(root->right,root->val));
        return false;
    }
    
    int count(tree* root) 
    {
        // this function will count how many subtrees are unival
    
        if(root && !root->left && !root->right) return 1;
        
        int c=count(root->left) + count(root->right);
        if(check(root,root->val))
            return c+1;
        return c;
    }
    
    void driver()
    {
        create();
        cout << "The tree has " << count(root) << " unival subtrees!" << endl;
    }
};

int main()
{
    Unival* obj=new Unival();
    obj->driver();
    return 0;
}
