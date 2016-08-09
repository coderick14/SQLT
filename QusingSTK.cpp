#include <iostream>
#define max 50
using namespace std;

void push(int* stack,int item,int* top)	{
	(*top)++;
	stack[*top] = item;
}

int pop(int* stack,int* top)	{
	int item = stack[*top];
	(*top)--;
	return item;
}
void nq(int* stack1,int* stack2,int* top1,int* top2,int item)	{
	if(*top1 == max-1)	{
		cout<<"Q Full"<<endl;
		return;
	}
	int val;
	while(*top1 != -1)	{
		val = pop(stack1,top1);
		push(stack2,val,top2);
	}
	push(stack1,item,top1);
	while(*top2 != -1)	{
		val = pop(stack2,top2);
		push(stack1,val,top1);
	}
}
int dq(int* stack1,int* top1)	{
	if(*top1 == -1)
		return -1;
	return pop(stack1,top1);
}
void show(int* stack1,int* top1)	{
	for(int i=(*top1);i>=0;i--)
		cout<<stack1[i]<<" ";
	cout<<endl;
}
int main()	{
	int* stack1 = new int[max];
	int* stack2 = new int[max];
	int ch,item,top1=-1,top2=-1;
	while(1)	{
		cout<<"1. Enqueue  2. Dequeue  3. Show  4. Exit\n";
		cin>>ch;
		switch(ch)	{
			case 1: cout<<"Enter item\n";
					cin>>item;
					nq(stack1,stack2,&top1,&top2,item);
					break;
			case 2: item = dq(stack1,&top1);
					if(item == -1)
						cout<<"Q empty"<<endl;
					else
						cout<<"Dequeued "<<item<<endl;
					break;
			case 3: show(stack1,&top1);
					break;						
		}
		if(ch == 4)
			break;
	}
	return 0;
}

