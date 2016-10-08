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
        BSTNode* temp = NULL;
        //if data == root->data => this is the node to be deleted
        if(root->leftChild && root->rightChild) {
            BSTNode* temp = findMin(root->rightChild);
            root->data = temp->data;
            root->rightChild = deleteFromBST(root->rightChild,root->data);
        }
        //only has left child
        else if(root->leftChild)    {
            temp = root;
            root = root->leftChild;
            delete temp;
        }
        //only has right child
        else if(root->rightChild)   {
            temp = root;
            root = root->rightChild;
            delete temp;
        }
        //leaf node
        else    {
            delete root;
            return NULL;
        }
    }
    return root;
}

BSTNode* search(BSTNode* root, int data)    {
    if(root == NULL)
        return NULL;
    if(data < root->data)
        return search(root->leftChild, data);
    else if(data > root->data)
        return search(root->rightChild, data);
    return root;
}

BSTNode* LCA(BSTNode* root, int data1, int data2)       {
    BSTNode* node1 = search(root, data1);
    BSTNode* node2 = search(root, data2);
    
    //If either of the values do not exist in the tree, return NULL
    if(node1 == NULL || node2 == NULL)
        return NULL;

    while(root) {
        /*if root data lies between the two node values,
          then one of the nodes exists in left subtree and 
          other in the right subtree of root. Thus root is the LCA*/
        if((root->data > node1->data && root->data < node2->data) || (root->data > node2->data && root->data < node1->data))
            return root;
        //if both node values are less than root data, then LCA lies in left subtree of root. Else it lies in right subtree.
        if(node1->data < root->data)
            root = root->leftChild;
        else
            root = root->rightChild;
    }
    return NULL;
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
    int ch,data,val;
    BSTNode *root = NULL, *temp = NULL;
    while(1)    {
        cout<<"1. Insert 2. Delete 3. Preorder 4. Inorder 5. Postorder 6. Search 7. LCA 8. Exit\n";
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
            case 6: cout<<"Enter data\n";
                    cin>>data;
                    temp = search(root, data);
                    if(temp)
                        cout<<"Found\n";
                    else
                        cout<<"Not found\n";
                    break;
            case 7: cout<<"Enter two node values\n";
                    cin>>data>>val;
                    temp = LCA(root, data, val);
                    cout<<temp->data<<endl;
                    break;
        }
        if(ch == 8)
            break;
    }
    deleteTree(root);
    return 0;
}
