#include <iostream>
#include <queue>
using namespace std;

struct treeNode {
    int data;
    treeNode *leftChild;
    treeNode *rightChild;
};

void insertIntoTree(treeNode **root,int data)    {
    treeNode* newNode = new treeNode;
    if(!newNode)    {
        cout<<"Memory allocation error"<<endl;
        return;
    }
    newNode->data = data;
    newNode->leftChild = newNode->rightChild = NULL;
    if(*root == NULL)    {
        *root = newNode;
        return;
    }
    queue<treeNode*> q;
    q.push(*root);
    treeNode *temp = NULL;
    while(!q.empty())   {
        temp = q.front();
        q.pop();
        if(temp->leftChild) {
            q.push(temp->leftChild);
        }
        else    {
            temp->leftChild = newNode;
            return;
        }
        if(temp->rightChild)    {
            q.push(temp->rightChild);
        }
        else    {
            temp->rightChild = newNode;
            return;
        }
    }
}

void preOrder(treeNode *root)   {
    if(root != NULL)    {
        cout<<(root)->data<<" ";
        preOrder((root)->leftChild);
        preOrder((root)->rightChild);
    }
}

void inOrder(treeNode *root)    {
    if(root != NULL)    {
        inOrder((root)->leftChild);
        cout<<(root)->data<<" ";
        inOrder((root)->rightChild);
    }
}

void postOrder(treeNode *root)  {
    if(root != NULL)    {
        postOrder((root)->leftChild);
        postOrder((root)->rightChild);
        cout<<(root)->data<<" ";
    }
}

treeNode* search(treeNode *root,int data)   {
    if(root == NULL)
        return NULL;
    if(root->data == data)
        return root;
    treeNode *temp = search(root->leftChild,data);
    if(temp)
        return temp;
    else
        return search(root->rightChild,data);
}

treeNode* findDeepestNode(treeNode **root)   {
    if(*root == NULL)    
        return NULL;
    queue<treeNode*> q;
    q.push(*root);
    treeNode *temp = NULL;
    while(!q.empty())   {
        temp = (q.front());
        q.pop();
        if(temp->leftChild) 
            q.push(temp->leftChild);
        if(temp->rightChild)
            q.push(temp->rightChild);
    }
    return temp;
}

int leafCount(treeNode *root)   {
    if(root == NULL)
        return 0;
    if(!root->leftChild && !root->rightChild)
        return 1;
    return (leafCount(root->leftChild)+leafCount(root->rightChild));
}

void deleteTree(treeNode *root) {
    if(root == NULL)
        return;
    deleteTree((root)->leftChild);
    deleteTree((root)->rightChild);
    delete root;
}

int main()  {
    treeNode *root = NULL,*temp = NULL;
    int ch,data;
    while(1)    {
        cout<<"1. Insert 2. Search 3. PreOrder 4. InOrder 5. PostOrder 6. LeafCount 7. Exit\n";
        cin>>ch;
        switch(ch)  {
            case 1: cout<<"Enter data"<<endl;
                    cin>>data;
                    insertIntoTree(&root,data);
                    break;
            case 2: cout<<"Enter node value to be searched for"<<endl;
                    cin>>data;
                    temp = search(root,data);
                    if(temp == NULL)
                        cout<<"Not found"<<endl;
                    else
                        cout<<temp->data<<" found"<<endl;
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
            case 6: cout<<leafCount(root)<<endl;
                    break;
        }
        if(ch == 7)
            break;
    }
    deleteTree(root);
    return 0;
}
