#include <iostream>
#include <climits>
#define endl '\n'
using namespace std;
struct stack
{
  int top;
  int capacity;
  int* array;
};
stack* createNode()
{
  stack* s=new stack;
  if(!s)
    return NULL;
  s->top=-1;
  s->capacity=10;
  s->array=new int[s->capacity];
  if(!s->array)
    return NULL;
  return s;
}
void push(stack* s,int data)
{
  if(s->top==s->capacity-1)
  {
    cout<<"Stack overflow"<<endl;
    return;
  }
  s->array[++(s->top)]=data;
}
int pop(stack* s)
{
  if(s->top==-1)
  {
    cout<<"Stack underflow"<<endl;
    return INT_MIN;
  }
  int p=s->array[(s->top)--];
  return p;
}
int getTop(stack* s)
{
  if(s->top==-1)
  {
    cout<<"Stack underflow"<<endl;
    return INT_MIN;
  }
  return s->array[s->top];
}
void printStack(stack* s)
{
  if(s->top==-1)
  {
    cout<<"Stack empty"<<endl;
    return;
  }
  for(int i=s->top;i>=0;i--)
    cout<<s->array[i]<<endl;
}
void insertAtBottom(stack* s,int data)
{
  if(s->top==-1)
  {
    push(s,data);
    return;
  }
  int temp=pop(s);
  insertAtBottom(s,data);
  push(s,temp);
}

void reverseStack(stack* s)
{
  if(s->top==-1)
    return;
  int data=pop(s);
  reverseStack(s);
  insertAtBottom(s,data);
}
int main()
{
  int ch,p,data;
  stack* s=createNode();
  while(1)
  {
    cout<<"1. Push\n2. Pop\n3. GetTop\n4. Reverse Stack\n5. Print Stack\n6. Exit\n";
    cin>>ch;
    switch(ch)
    {
      case 1: cout<<"Enter data\n";
              cin>>data;
              push(s,data);
              break;
      case 2: p=pop(s);
              cout<<"Popped "<<p<<endl;
              break;
      case 3: cout<<getTop(s)<<endl;
              break;
      case 4: reverseStack(s);
              cout<<"Stack reversed\n";
              break;
      case 5: printStack(s);
              break;
      case 6: break;
    }
    if(ch==6)
      break;
  }
  delete s->array;
  delete s;
  return 0;
}
