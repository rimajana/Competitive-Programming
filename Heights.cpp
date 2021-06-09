#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int arr[100100];
int T[500100];
int n;

void build(int index, int l, int r)
{
    if (l == r)
    {
        T[index] = 1;
        return;
    }
    int mid = l + (r - l) / 2;
    build(2 * index, l, mid);
    build(2 * index + 1, mid + 1, r);
    T[index] = T[2 * index] + T[2 * index + 1];
}
int height(int index, int l, int r, int k)
{
    if (l == r)
    {
        T[index] = 0;
        return l;
    }
    int mid = (l  +r) / 2;
    int b;
    if (k <= T[2 * index])
        b = (height(2 * index, l, mid, k));
    else
        b = (height(2 * index + 1, mid + 1, r, k - T[2 * index]));
    T[index] = (T[2 * index] + T[2 * index + 1]);
    return b;
}
// void update(int index,int l,int r,int k)
// {
//     if(l==r)
//     {

//         return;
//     }
//     int mid=l+(r-l)/2;
//     if(k<=T[2*index]) update(2*index,l,mid,k);
//     else update(2*index+1,mid+1,r,k-T[2*index]);
//     T[index]=(T[2*index]+T[2*index+1]);
// }

void view_tree(){
    for(int i=1;i<2*n+1;i++){
        cout << T[i] << " ";

    }
    cout << "\n";

}

void solve(){

    cin >> n;
    pair<int, int> p[n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first;
        p[i].second = i;
    }
    int P[n];
    for (int i = 0; i < n; i++)
        cin >> P[i];

    sort(p, p + n);
    build(1, 0, n - 1);
    view_tree();
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int j = p[i].second;
        int k = height(1, 0, n - 1, P[j] + 1);
        cout <<  P[j] + 1 << "ef" << j<<"\n";
        //cout << "iteration no: " << i << "\n";
        view_tree();
        
        arr[k] = j + 1;
    }
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}






int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    
    return 0;
}
