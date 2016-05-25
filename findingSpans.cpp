#include <iostream>
#define endl '\n'
using namespace std;
void findSpans(int* arr,int* span,int n)
{
  int i,j;
  for(i=0;i<n;i++)
  {
    span[i]=1;
    j=i-1;
    while(j>=0 && arr[j]<arr[i])
    {
      span[i]+=span[j];
      j=j-span[j];
    }
  }
}
int main()
{
  int n,i;
  cin>>n; //Size of array
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
