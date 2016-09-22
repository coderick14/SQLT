#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void swap(int &a,int &b)    {
    int temp = a;
    a = b;
    b = temp;
}

void heapify(vector<int> &arr,int i)    {
    int left = 2*i + 1;
    int right = 2*i + 2;
    int small = i;
    int n = arr.size();
    if(left < n && arr[left] < arr[small])
        small = left;
    if(right < n && arr[right] < arr[small])
        small = right;
    if(small != i)  {
        swap(arr[i],arr[small]);
        heapify(arr,small);
    }
}

int getMin(vector<int> &arr) {
    if(arr.size() > 0)
        return arr[0];
    else
        return INT_MAX;
}

int extractMin(vector<int> &arr)    {
    int n = arr.size();
    if(n<1)
        return INT_MAX;
    int min = arr[0];
    swap(arr[0],arr[n-1]);
    arr.erase(arr.end()-1);
    heapify(arr,0);
    return min;
}

void decreaseKey(vector<int> &arr,int i, int key)    {
    if(i<0) {
        cout<<"Invalid index\n";
        return;
    }
    if(key >= arr[i])   {
        cout<<"Key greater than existing key\n";
        return;
    }
    arr[i] = key;
    int parent = (i-1)/2;
    while(i>0 && arr[parent] > arr[i])    {
        swap(arr[parent],arr[i]);
        i = parent;
        parent = (i-1)/2;
    }
}

void insertIntoQ(vector<int> &arr,int key) {
    arr.push_back(INT_MAX);
    decreaseKey(arr,arr.size()-1,key);
}

void traverse(vector<int> &arr) {
    int n = arr.size();
    for(int i=0; i<n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}

int main() {
    int ch,data,index,res;
    vector<int> arr;
    while(1)    {
        cout<<"1. Insert  2. GetMinimum  3. ExtractMin  4. DecreaseKey  5. Traverse  6. Exit\n";
        cin>>ch;
        switch(ch)  {
            case 1: cout<<"Enter data\n";
                    cin>>data;
                    insertIntoQ(arr,data);
                    break;
            case 2: res = getMin(arr);
                    if(res == INT_MAX)
                        cout<<"Priority Queue empty\n";
                    else
                        cout<<res;
                    break;
            case 3: res = extractMin(arr);       
                    if(res == INT_MAX)
                        cout<<"Priority Queue empty\n";
                    else
                        cout<<res;
                    break;
            case 4: cout<<"Enter index and new key\n";
                    cin>>index>>data;
                    decreaseKey(arr,index,data);
                    break;
            case 5: traverse(arr);
                    break;
        }
        if(ch == 6)
            break;
    }
    return 0;
}
