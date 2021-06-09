#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int arr[10100];

struct node{
    int min;
    int cnt;
    node(int m=INT_MAX,int c=0){
        min=m;
        cnt = c;
    
    }
};

node t[40400]; //tree should be 4 times the size of array

node merge(node a,node b){
    cout << "node a " << a.min << a.cnt << endl;
    cout << "node a" << b.min << b.cnt << endl;
    if (a.min == b.min)
    {
        node h = node(a.min, a.cnt + b.cnt);
        cout << h.min << h.cnt << "merge"
             << "\n";
        return h;
    }
    else if(a.min>b.min){
        cout << b.min << b.cnt<<"b"<<"\n";
        return b;
    }
    else {
        cout << a.min << a.cnt <<"a"<<"\n";
        return a;
    }

}


//here index is nothing but node number and it starts from 1

//root node is at  1
void build(int index, int l, int r)
{
    if (l == r)
    {
        //leaf node
        //Here the value of that node will be taken directly from the array
        t[index] = node(arr[l],1);
        return;
    }

    //IF the index node is i then the left node is 2*i and the right node would be 2*i+1 i.e index 1 left node 2 right node 3

    int mid = (l + r) / 2;

    //Building Left tree
    build(index * 2, l, mid);

    //Building right tree
    build(index * 2 + 1, mid + 1, r);

    //merge logic of segment tree
    t[index] = merge( t[2 * index], t[2 * index + 1]);

}

void update(int index, int l, int r, int pos, int val) //Here we are updating the position with value
{
    
    if (pos < l || pos > r)
    {
        return;
    }
    if (l == r)
    {
        //Leaf node
        arr[l] = val;
        t[index] = node(val,1);
        return;
    }
    int mid = (l + r) / 2;
    update(index * 2, l, mid, pos, val);
    update(index * 2 + 1, mid + 1, r, pos, val);

    t[index] = merge(t[2 * index], t[2 * index + 1]); //merge logic of segment tree
}


node query(int index, int l, int r, int lq, int rq) 
{
   

    if (l > rq || lq > r)         //check if two ranges intersect or not if they dont intersect then return 0
    {
        return INT_MAX;
    }
    

    if (lq <= l and r <= rq) //If l and r exist in between lq and rq then we are directly returning the node
    {
        //lq<=l<=r<=rq

        return t[index];
    }
    int mid = (l + r) / 2;   
    node y= merge(query(index * 2, l, mid, lq, rq) , query(index * 2 + 1, mid + 1, r, lq, rq)); //contribution of left child and right child(recurse on left size and right side)
    cout << y.min << " " << y.cnt <<"inside"<< "\n";
    return y;
}

void print_tree(){
    fo(i, 1, 10)
    {
        cout << t[i].min << " " << t[i].cnt << endl;
    }
}

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    
    build(1, 0, n - 1);
    print_tree(); //node 1 is root node and it is responsible from l to r

    int q;                       //  Taking the number of queries
    cin >> q;
    for (int i = 0; i < q; i++)
    {
        int ch;
        cin >> ch;
        if (ch == 1)            //updating any position(x) with value(v)
        {
           
            int x, v;
            cin >> x >> v;
            update(1, 0, n - 1, x, v);
        }
        else
        {                          //Here we are findind the sum from range (l to r including l and r)

            int l, r;
            cin >> l >> r;
            node x = query(1, 0, n - 1, l, r);
            print_tree();
            cout <<x.min<<" "<<x.cnt<<"\n";
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    cin >> t;
    //string s;
    //getline(cin,s);
    while (t--)
    {
        solve();
    }
}