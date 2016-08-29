#include <iostream>
#define endl '\n'
using namespace std;
struct DLLNode
{
  int data;
  struct DLLNode *next;
  struct DLLNode *prev;
};
void insert(DLLNode **head,int data,int pos)
{
  struct DLLNode *p,*newNode;
  newNode=new DLLNode;
  if(!newNode)
  {
    cout<<"Memory allocation error\n";
    return;
  }
  int k=1;
  newNode->data=data;
  p=*head;
  if(pos==1)
  {
    newNode->next=*head;
    newNode->prev=NULL;
    if(*head!=NULL)
      (*head)->prev=newNode;
    *head=newNode;
  }
  else
  {
    while((p->next!=NULL) && k<pos-1)
    {
      p=p->next;
      k++;
    }
    if((p->next)==NULL)
    {
      p->next=newNode;
      newNode->next=NULL;
      newNode->prev=p;
    }
    else
    {
      newNode->next=p->next;
      newNode->prev=p;
      p->next->prev=newNode;
      p->next=newNode;
    }

  }

}
void del(DLLNode **head,int pos)
{
  if(*head==NULL)
  {
    cout<<"List empty\n";
    return;
  }
  DLLNode *temp=*head;
  int k=1;
  if(pos==1)
  {
    *head=(*head)->next;
    if(*head!=NULL)
      (*head)->prev=NULL;
    delete temp;
  }
  else
  {
    while((temp->next!=NULL) && k<pos-1)
    {
      temp=temp->next;
      k++;
    }
    if((temp->next)==NULL)
    {
      cout<<"Position exceeds list length\n";
      return;
    }
    else
    {
      temp=temp->next;
      temp->prev->next=temp->next;
      if(temp->next!=NULL)
        temp->next->prev=temp->prev;
      delete temp;
    }
  }
}
void traversal(DLLNode **head)
{
  if(*head==NULL)
  {
    cout<<"List empty\n";
    return;
  }
  struct DLLNode *temp=new DLLNode;
  temp=*head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
  cout<<endl;
  delete temp;
}
void deleteList(DLLNode ** head)
{
  if(*head==NULL)
    return;
  DLLNode *p=*head;
  while(p->next!=NULL)
  {
    DLLNode *temp=p->next;
    p->next=temp->next;
    delete temp;
  }
  delete p;
}
int main()
{
  int pos,ch,val;
  struct DLLNode *head=NULL;
  do
  {
    cout<<"1. Insertion\n2. Deletion\n3. Traversal\n4. Exit\n";
    cin>>ch;
    switch (ch)
    {
      case 1: cout<<"Enter value and postion\n";
              cin>>val>>pos;
              insert(&head,val,pos);
              break;
      case 2: cout<<"Enter position\n";
              cin>>pos;
              del(&head,pos);
              break;
      case 3: traversal(&head);
              break;
    }
  }while(ch!=4);
  deleteList(&head);
  return 0;
}
