#include <iostream>
using namespace std;

struct BSTNode  {
    int data;
    BSTNode* leftChild;
    BSTNode* rightChild;
};

BSTNode* findMin(BSTNode* root) {
    if(root == NULL)
        return NULL;
    while(root->leftChild != NULL)
        root = root->leftChild;
    return root;
}

BSTNode* insertIntoBST(BSTNode* &root,int data)  {
    if(root == NULL)    {
        BSTNode* temp = new BSTNode;
        if(!temp)   {
            cout<<"Memory allocation error"<<endl;
            return NULL;
        }
        temp->data = data;
        temp->leftChild = temp->rightChild = NULL;
        root = temp;
    }
    else {
        if(data < root->data)   {
            root->leftChild = insertIntoBST(root->leftChild,data);
        }
        else if(data > root->data)  {
            root->rightChild = insertIntoBST(root->rightChild,data);
        }
    }
    return root;
}

BSTNode* deleteFromBST(BSTNode* &root,int data) {
    if(root == NULL)    
        return NULL;
    else if(data < root->data)
        root->leftChild = deleteFromBST(root->leftChild,data);
    else if(data > root->data)
        root->rightChild = deleteFromBST(root->rightChild,data);
    else    {
        //if data == root->data => this is the node to be deleted
        if(root->leftChild && root->rightChild) {
            BSTNode* temp = findMin(root->rightChild);
            root->data = temp->data;
            root->rightChild = deleteFromBST(root->rightChild,root->data);
        }
        else if(root->leftChild)    {
            root = root->leftChild;
        }
        else if(root->rightChild)   {
            root = root->rightChild;
        }
        else
            return NULL;
    }
    return root;
}

void preOrder(BSTNode *root)   {
    if(root != NULL)    {
        cout<<(root)->data<<" ";
        preOrder((root)->leftChild);
        preOrder((root)->rightChild);

    }

}

void inOrder(BSTNode *root)    {
    if(root != NULL)    {
        inOrder((root)->leftChild);
        cout<<(root)->data<<" ";
        inOrder((root)->rightChild);

    }

}

void postOrder(BSTNode *root)  {
    if(root != NULL)    {
        postOrder((root)->leftChild);
        postOrder((root)->rightChild);
        cout<<(root)->data<<" ";

    }

}

void deleteTree(BSTNode *root) {
    if(root == NULL)
        return;
    deleteTree((root)->leftChild);
    deleteTree((root)->rightChild);
    delete root;

}

int main()  {
    int ch,data;
    BSTNode* root = NULL;
    while(1)    {
        cout<<"1. Insert 2. Delete 3. Preorder 4. Inorder 5. Postorder 6. Exit\n";
        cin>>ch;
        switch(ch)  {
            case 1: cout<<"Enter data\n";
                    cin>>data;
                    root = insertIntoBST(root,data);
                    break;
            case 2: cout<<"Enter data\n";
                    cin>>data;
                    root = deleteFromBST(root,data);
                    break;
            case 3: preOrder(root);
                    cout<<endl;
                    break;
            case 4: inOrder(root);
                    cout<<endl;
                    break;
            case 5: postOrder(root);
                    cout<<endl;
                    break;
        }
        if(ch == 6)
            break;
    }
    deleteTree(root);
    return 0;
}
