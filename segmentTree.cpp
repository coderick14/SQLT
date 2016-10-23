#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

//function to build segment tree for RangeSum query
void build_rangesum_tree(ll* t, ll n) {
    ll i;
    for(ll i=n-1; i>0; i--) {
        t[i] = t[i<<1] + t[i<<1|1]; //t[i] = t[2*i] + t[2*i + 1];
    }
    /*for(i=1; i<2*n; i++)
        cout<<t[i]<<" ";
    cout<<endl;*/
}


//function to build segment tree for RangeMin query
void build_rangemin_tree(ll* t_min, ll n)   {
    ll i;
    for(i=n-1; i>0; i--)    {
        t_min[i] = min(t_min[i<<1], t_min[i<<1|1]);
    }
    /*for(i=1; i<2*n; i++)
        cout<<t_min[i]<<" ";
    cout<<endl;*/
}

//function to build segment tree for RangeMax query
void build_rangemax_tree(ll* t_max, ll n)   {
    ll i;
    for(i=n-1; i>0; i--)    {
        t_max[i] = max(t_max[i<<1], t_max[i<<1|1]);
    }
    /*for(i=1; i,2*n; i++)
        cout<<t_max[i]<<" ";
    cout<<endl;*/
}

//returns the sum in the range [l,r)
ll range_sum(ll* t, ll n, ll l, ll r)   {
    ll sum=0;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)    {
        if(l & 1)
            sum += t[l++];
        if(r & 1)
            sum += t[--r];
    }
    return sum;
}

//returns the minimum element in the range [l,r)
ll range_min(ll* t, ll n, ll l, ll r)   {
    ll minim = INT_MAX;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)  {
        if(l & 1)
            minim = min(minim, t[l++]);
        if(r & 1)
            minim = min(minim, t[--r]);
    }
    return minim;
}

//returns the maximum element in the range [l,r)
ll range_max(ll* t, ll n, ll l, ll r)   {
    ll maxim = INT_MIN;
    for(l+=n, r+=n; l<r; l>>=1, r>>=1)  {
        if(l & 1)
            maxim = max(maxim, t[l++]);
        if(r & 1)
            maxim = max(maxim, t[--r]);
    }
    return maxim;
}

//changes the value of array[index] to key and modifies the tree accordingly
void modify(ll* t, ll* t_min, ll* t_max, ll n, ll index, ll key)  {
    index += n;
    t[index] = t_min[index] = t_max[index] = key;
    for(; index>1; index>>=1)   {
        t[index>>1] = t[index] + t[index^1];
        t_min[index>>1] = min(t_min[index], t_min[index^1]);
        t_max[index>>1] = max(t_max[index], t_max[index^1]);
    }
}

int main()  {
    ll i,n,l,h,val;
    int ch;
    cout<<"Enter n\n";
    cin>>n;
    cout<<"Enter array\n";
    ll t[2*n + 1], t_min[2*n + 1], t_max[2*n + 1];
    for(i=0;i<n;i++)    {
        cin>>t[n+i];
        t_min[n+i] = t_max[n+i] = t[n+i];
    }
    build_rangesum_tree(t,n);
    build_rangemin_tree(t_min, n);
    build_rangemax_tree(t_max, n);
    while(1)    {
        cout<<"1. RangeSum[l,h)  2. RangeMin[l,h)  3. RangeMax[l,h)  4. Modify  5. Exit\n";
        cin>>ch;
        switch(ch)  {
            case 1: cout<<"Enter l and h\n";
                    cin>>l>>h;
                    cout<<range_sum(t,n,l,h)<<"\n";
                    break;

            case 2: cout<<"Enter l and h\n";
                    cin>>l>>h;
                    cout<<range_min(t_min,n,l,h)<<"\n";
                    break;

            case 3: cout<<"Enter l and h\n";
                    cin>>l>>h;
                    cout<<range_max(t_max,n,l,h)<<"\n";
                    break;

            case 4: cout<<"Enter index and new value\n";
                    cin>>i>>val;
                    modify(t,t_min,t_max,n,i,val);
                    break;
        }
        if(ch == 5)
            break;
    }
    return 0;
}
