#include <iostream>
using namespace std;

struct node {
    int coeff;
    int power;
    node* next;
};

void insert(node **head,node **rear,int ce,int power)    {
    node* newNode = new node;
    if(!newNode)    {
        cout<<"Sorry! Memory allocation error"<<endl;
        return;
    }
    newNode->coeff = ce;
    newNode->power = power;
    if(*head == NULL)   {
        newNode->next = NULL;
        *head = newNode;
        *rear = newNode;
    }
    else    {
       (*rear)->next = newNode;
       newNode->next = NULL;
       *rear = newNode;
    }
}

void traversal(node **head) {
    node *temp = *head;
    cout<<"C(x) = A(x) + B(x) = "<<endl;
    while(temp!=NULL)   {
        cout<<temp->coeff<<" "<<temp->power<<endl;
        temp = temp->next;
    }
}

void deleteList(node **head)    {
    node* p  = *head;
    if(p == NULL)
        return;
    while(p->next != NULL)  {
        node* temp = new node;
        temp = p->next;
        p->next  = temp->next;
        delete temp;
    }
    delete p;
}

int main()  {
    int ce,pw;
    node *headA,*headB,*headC,*rearA,*rearB,*rearC;
    headA = headB = headC = rearA = rearB = rearC = NULL;
    cout<<"Enter A(x)"<<endl;
    do  {
        cin>>ce>>pw;
        insert(&headA,&rearA,ce,pw);
    }while(pw!=0);

    cout<<"Enter B(x)"<<endl;
    do  {
        cin>>ce>>pw;
        insert(&headB,&rearB,ce,pw);
    }while(pw!=0);
    
    node *cursorA = headA,*cursorB = headB;

    while(cursorA != NULL && cursorB != NULL) {
        if(cursorA->power > cursorB->power) {
            insert(&headC,&rearC,cursorA->coeff,cursorA->power);
            cursorA = cursorA->next;
        }
        else if(cursorA->power < cursorB->power)    {
            insert(&headC,&rearC,cursorB->coeff,cursorB->power);
            cursorB = cursorB->next;
        }
        else if(cursorA->coeff + cursorB->coeff != 0)   {
            insert(&headC,&rearC,cursorA->coeff + cursorB->coeff,cursorA->power);             
            cursorA = cursorA->next;
            cursorB = cursorB->next;
        }
    }

    while(cursorA != NULL)  {
         insert(&headC,&rearC,cursorA->coeff,cursorA->power);
         cursorA = cursorA->next;
    }
    while(cursorB != NULL)  {
         insert(&headC,&rearC,cursorB->coeff,cursorB->power);
         cursorB = cursorB->next;
    }

    traversal(&headC);
    deleteList(&headA);
    deleteList(&headB);
    deleteList(&headC);
    return 0;
}
