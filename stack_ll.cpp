#include <iostream>
#define endl '\n'
using namespace std;
struct stack
{
  int data;
  stack* next;
};
void push(stack** top)
{
  stack* s=new stack;
  if(!s)
  {
    cout<<"Memory allocation error\n";
    return;
  }
  int data;
  cout<<"Enter data\n";
  cin>>data;
  s->data=data;
  s->next=*top;
  *top=s;
}
void pop(stack** top)
{
  if(*top==NULL)
  {
    cout<<"Stack underflow\n";
    return;
  }
  stack* temp=new stack;
  temp=*top;
  *top=temp->next;
  cout<<"Popped "<<temp->data<<endl;
  delete temp;
}
void printStack(stack** top)
{
  if(*top==NULL)
  {
    cout<<"Stack empty\n";
    return;
  }
  stack* temp=new stack;
  temp=*top;
  while(temp!=NULL)
  {
    cout<<temp->data<<endl;
    temp=temp->next;
  }
  delete temp;
}
void deleteStack(stack** top)
{
  stack *p=new stack;
  p=*top;
  while(p->next)
  {
    stack *temp=new stack;
    temp=p->next;
    p->next=temp->next;
    delete temp;
  }
  delete p;
}
int main()
{
  int ch;
  stack* top=NULL;
  do
  {
    cout<<"1. Push\n2. Pop\n3. Print\n4. Exit\n";
    cin>>ch;
    switch (ch)
    {
      case 1: push(&top);
              break;
      case 2: pop(&top);
              break;
      case 3: printStack(&top);
              break;
    }
  }while(ch!=4);
  deleteStack(&top);
  return 0;
}
