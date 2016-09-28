//Right Inorder Threaded Binary Search Tree
#include <iostream>
using namespace std;

struct treeNode {
    int data;
    treeNode* left;
    treeNode* right;
    bool rightThreaded;
};

void insertNode(treeNode* &root, int data)  {
    treeNode* newNode = new treeNode;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    newNode->rightThreaded = false;

    if(root == NULL)    {
        root = newNode;
        return;
    }
    treeNode* current = root;
    treeNode* parent = NULL;

    while(current)  {
        parent = current;
        if(data < current->data)    {
            current = current->left;
            if(current == NULL) {
                parent->left = newNode;
                newNode->right = parent;
                newNode->rightThreaded = true;
                return;
            }
        }
        else    {
            if(current->rightThreaded == false) {
                current = current->right;
                if(current == NULL) {
                    parent->right = newNode;
                    return;
                }
            }
            else    {
                treeNode* temp = current->right;
                current->right = newNode;
                current->rightThreaded = false;
                newNode->right = temp;
                newNode->rightThreaded = true;
                return;
            }
        }
    }
}

treeNode* leftMostNode(treeNode* root)  {
    if(root == NULL)
        return NULL;
    while(root->left)
        root = root->left;
    return root;
}

void inorder(treeNode* root)    {
    treeNode* current = leftMostNode(root);
    while(current)  {
        cout<<current->data<<" ";
        if(current->rightThreaded)
            current = current->right;
        else
            current = leftMostNode(current->right);
    }
    cout<<endl;
}

void preorder(treeNode* root)   {
    while(root) {
        cout<<root->data<<" ";
        if(root->left)
            root = root->left;
        else    {
            while(root->rightThreaded)
                root = root->right;
            root = root->right;
        }
    }
    cout<<endl;
}

int main()  {
    int ch,data;
    treeNode* root = NULL;
    while(1)    {
        cout<<"1. Insert  2. Inorder  3. Preorder  4. Exit\n";
        cin>>ch;
        switch(ch)  {
            case 1: cout<<"Enter data\n";
                    cin>>data;
                    insertNode(root,data);
                    break;
            case 2: inorder(root);
                    break;
            case 3: preorder(root);
                    break;
        }
        if(ch == 4)
            break;
    }
    return 0;
}
