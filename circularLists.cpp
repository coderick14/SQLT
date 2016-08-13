#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

void insert(node **head,int data,bool beg)   {
    node *newNode = new node;
    if(!newNode)    {
        cout<<"Memory allocation error"<<endl;
        return;
    }
    newNode->data = data;
    newNode->next = newNode;
    if(*head == NULL)   {
        *head = newNode;
        return;
    }
    node *current = *head;
    while(current->next != *head)
        current = current->next;
    newNode->next = *head;
    current->next = newNode;
    if(beg)
        *head = newNode;
}

void delAtEnd(node **head)    {
    if(*head == NULL)   {
        cout<<"List empty"<<endl;
        return;
    }
    int isOnlyOneNode = 0;
    node *current = *head;
    if(current->next == *head)
        isOnlyOneNode = 1;
    while(current->next->next != *head)
        current = current->next;
    node *temp = new node;
    temp = current->next;
    current->next = temp->next;
    delete temp;
    if(isOnlyOneNode)
        *head = NULL;
}


void delAtBeg(node **head)    {
    if(*head == NULL)   {
        cout<<"List empty"<<endl;
        return;
    }
    int isOnlyOneNode = 0;
    node *current = *head;
    if(current->next == *head)
        isOnlyOneNode = 1;
    while(current->next != *head)
       current = current->next;
    node *temp = new node;
    temp = *head;
    current->next = temp->next;
    if(isOnlyOneNode)
        *head = NULL;
    else
        *head = current->next;
    delete temp;
}

void traversal(node **head) {
    if(*head == NULL)   {
        cout<<"List empty"<<endl;
        return;
    }
    node *current = *head;
    do  {
        cout<<current->data<<" ";
        current = current->next;
    }while(current != *head);
    cout<<endl;
}

void delList(node **head)   {
    if(*head == NULL)
        return;
    node *current = *head;
    while(current->next != *head)   {
        node *temp = current->next;
        current->next = temp->next;
        delete temp;
    }
    delete current;
}

int main()  {
    int ch,data;
    node *head = NULL;
    while(1)    {
        cout<<"1. InsertAtBeg  2. InsertAtEnd  3. DeleteAtBeg  4. DeleteAtEnd  5. Traversal  6. Exit\n";
        cin>>ch;
        switch(ch)  {
            case 1: cout<<"Enter data"<<endl;
                    cin>>data;
                    insert(&head,data,true);
                    break;
            case 2: cout<<"Enter data\n";
                    cin>>data;
                    insert(&head,data,false);
                    break;
            case 3: delAtBeg(&head);
                    break;
            case 4: delAtEnd(&head);
                    break;
            case 5: traversal(&head);
                    break;
        }
        if(ch == 6) 
            break;
    }
    delList(&head);
    return 0;
}
