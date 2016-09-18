//Binary tree with non-recursive procedures for traversal

#include <iostream>
#include <queue>
#include <vector>
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

void preOrderNonRecursive(treeNode *root)   {
    vector<treeNode*> stack;
    while(1)    {
        while(root) {
            cout<<root->data<<" ";
            stack.push_back(root);
            root = root->leftChild;
        }
        if(stack.empty())   {
            break;
        }
        root = stack.back();
        stack.pop_back();
        root = root->rightChild;
    }
    cout<<endl;
}

void inOrderNonRecursive(treeNode *root)    {
    vector<treeNode*> stack;
    while(1)    {
        while(root) {
            stack.push_back(root);
            root = root->leftChild;
        }
        if(stack.empty())   {
            break;
        }
        root = stack.back();
        stack.pop_back();
        cout<<root->data<<" ";
        root = root->rightChild;
    }
    cout<<endl;
}

void postOrderNonRecursive(treeNode *root)  {
    vector<treeNode*> stack1;
    vector<treeNode*> stack2;
    stack1.push_back(root);
    while(!stack1.empty())  {
        stack2.push_back(stack1.back());
        stack1.pop_back();
        if(stack2.back()->leftChild)    {
            stack1.push_back(stack2.back()->leftChild);
        }
        if(stack2.back()->rightChild)   {
            stack1.push_back(stack2.back()->rightChild);
        }
    }
    while(!stack2.empty())  {
        cout<<stack2.back()->data<<" ";
        stack2.pop_back();
    }
    cout<<endl;
}

void deleteTree(treeNode *root) {
    if(root == NULL)
        return;
    deleteTree((root)->leftChild);
    deleteTree((root)->rightChild);
    delete root;

}

int main()  {
    treeNode *root = NULL;
    int ch,data;
    while(1)    {
        cout<<"1. Insert 2. PreOrder 3. InOrder 4. PostOrder 5. Exit\n";
        cin>>ch;
        switch(ch)  {
            case 1: cout<<"Enter data"<<endl;
                    cin>>data;
                    insertIntoTree(&root,data);
                    break;
            case 2: preOrderNonRecursive(root);
                    break;
            case 3: inOrderNonRecursive(root);
                    break;
            case 4: postOrderNonRecursive(root);
                    break;   
        }
        if(ch == 5)
            break;
    }
    deleteTree(root);
    return 0;
}
