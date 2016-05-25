#include <iostream>
#define endl '\n'
using namespace std;
struct stack
{
  int top;
  int capacity;
  int* array;
};
stack* createStack()
{
  stack* s=new stack;
  if(!s)
    return NULL;
  s->top=-1;
  s->capacity=20;
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
void pop(stack* s)
{
  (s->top)--;
}
bool isEmptyStack(stack* s)
{
  return s->top==-1;
}
void findSpans(int* arr,int* span,int n)
{
  stack* s=createStack();
  int i,p;
  for(i=0;i<n;i++)
  {
    while(!isEmptyStack(s) && arr[i] > arr[s->array[s->top]])
        pop(s);
    if(isEmptyStack(s))
        p=-1;
    else
        p=s->array[s->top];
    span[i]=i-p;
    push(s,i);
  }
  delete s;
  //delete []s->array;
}
int main()
{
  int i,n;
  cin>>n;
  int* arr=new int[n];
  int* span=new int[n];
  for(i=0;i<n;i++)
    cin>>arr[i];
  findSpans(arr,span,n);
  for(i=0;i<n;i++)
    cout<<span[i]<<" ";
  cout<<endl;
  delete []arr;
  delete []span;
  return 0;
}
