#include <bits/stdc++.h>
using namespace std;

class serializeDeserialize{
public:
    
    struct tree
    {
        int val;
        tree *left, *right;
    }*root;
    
    serializeDeserialize()
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
           8
          / \
         9   1
            / \
           4   3
          / \   \
         7  5   6
        */
        root=newNode(8);
        root->left=newNode(9);
        root->right=newNode(1);
        root->right->left=newNode(4);
        root->right->right=newNode(3);
        root->right->left->left=newNode(7);
        root->right->left->right=newNode(5);
        root->right->right->right=newNode(6);
    }
    
    string serialize(tree* root)
    {
        /* this function will serialize the tree into a string in the preorder format.
        Each leaf is followed by two *, denoting empty children.
        */
        
        if(!root) return "*";
        
        return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }
    
    void display(tree* root)
    {
        //printing in inorder pattern
        if(!root) return;
        display(root->left);
        cout << root->val << " ";
        display(root->right);
    }
    
    int deserialize(tree* nroot, string s, int i) 
    {
        /* This function will deserialize the tree from the string.
        For now, let us just focus on single digit numbers only!
        */
        
        i=i+2;
        if(s[i]=='*')
            nroot->left=nullptr;
        else
        {
            nroot->left=newNode(s[i]-'0');
            i=deserialize(nroot->left,s,i);
        }
        
        i=i+2;
        if(s[i]=='*')
            nroot->right=nullptr;
        else
        {
            nroot->right=newNode(s[i]-'0');
            i=deserialize(nroot->right,s,i);
        }
        return i;
    }
    
    void driver()
    {
        create();
        string s=serialize(root);
        cout << "Serialized tree: " << s << endl;
        tree* nroot=newNode(s[0]-'0');
        deserialize(nroot,s,0);
        cout << "\nInorder of deserialized tree: ";
        display(nroot);
    }
};

int main()
{
    serializeDeserialize* obj=new serializeDeserialize();
    obj->driver();
    return 0;
}
