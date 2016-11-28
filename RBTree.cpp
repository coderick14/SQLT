#include <bits/stdc++.h>
using namespace std;

enum Color { RED, BLACK };

struct RBNode {
    int data;
    Color colour;
    RBNode* parent;
    RBNode* left;
    RBNode* right;
};

void rotate_left(RBNode* &root, RBNode* &x) {
    RBNode* y = x->right;
    x->right = y->left;
    y->left->parent = x;
    y->parent = x->parent;
    if(x->parent == NULL)
        root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void rotate_right(RBNode* &root, RBNode* &x) {
    RBNode* y = x->left;
    x->left = y->right;
    y->right->parent = x;
    y->parent = x->parent;
    if(x->parent == NULL)
        root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
}


void RBinsert_fixup(RBNode* &root, RBNode* &z) {
    if(z == root) {
        z->colour = BLACK;
        return;
    }
    while(z->parent->colour == RED) {
        if(z->parent == z->parent->parent->left) {
            RBNode* uncle = z->parent->parent->right;

            if(uncle->colour == RED) {
                z->parent->colour = BLACK;
                uncle->colour = BLACK;
                z->parent->parent->colour = RED;
                z = z->parent->parent;
            }
            else {
                if(z == z->parent->right) {
                    z = z->parent;
                    rotate_left(root, z);
                }
                z->parent->colour = BLACK;
                z->parent->parent->colour = RED;
                rotate_right(root, z->parent->parent);
            }
        }
        else {
            RBNode* uncle = z->parent->parent->left;

            if(uncle->colour == RED) {
                z->parent->colour = BLACK;
                uncle->colour = BLACK;
                z->parent->parent->colour = RED;
                z = z->parent->parent;
            }
            else {
                if(z == z->parent->left) {
                    z = z->parent;
                    rotate_right(root, z);
                }
                z->parent->colour = BLACK;
                z->parent->parent->colour = RED;
                rotate_left(root, z->parent->parent);
            }
        }
    }
    root->colour = BLACK;
}

void RBinsert(RBNode* &root, int data) {
    RBNode* z = new RBNode;
    z->data = data;
    z->left = z->right = NULL;
    z->colour = RED;

    RBNode* y = NULL;
    RBNode* x = root;

    while(x != NULL) {
        y = x;
        if(data < x->data)
            x = x->left;
        else
            x = x->right;
    }
    
    z->parent = y;
    if(y == NULL)
        root = z;
    else if(data < y->data)
        y->left = z;
    else
        y->right = z;
    RBinsert_fixup(root, z);
}

void preorder(RBNode* root) {
    if(root) {
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}

void deleteTree(RBNode* &root) {
    if(root) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    int ch, data;;
    RBNode* root = NULL;
    while(1) {
        cout<<"1. Insert  2. Preorder  3. Exit\n";
        cin>>ch;
        switch(ch) {
            case 1: cout<<"Enter data\n";
                    cin>>data;
                    RBinsert(root, data);
                    break;
            case 2: preorder(root);
                    cout<<"\n";
                    break;
        }
        if(ch == 3) 
            break;
    }
    deleteTree(root);
    return 0;
}
