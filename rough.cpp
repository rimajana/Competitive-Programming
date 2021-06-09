#include <bits/stdc++.h>
using namespace std;

int main()
{
    // no of cookies
    int b;
    cin >> b;

    // int arr[b][6]; 
    int mini=INT_MAX, maxx=INT_MIN,mi=INT_MAX,ma=INT_MIN;

    vector<pair<int, int>> x, y;

    int co;
    //taking input
    for (int i = 0; i < b; i++)
    {
        mini = INT_MAX;
        maxx = INT_MIN;
        mi = INT_MAX;
        ma = INT_MIN;
        for (int j = 0; j < 6; j++)
        {
            cin >> co;

            if(j%2 == 0){
                mini = min(mini, co);
                maxx = max(maxx, co);
            }
            else{
                mi = min(mi, co);
                ma = max(ma, co);
               
            }
            
        }
        x.push_back({mini, maxx});
        y.push_back({mi, ma});
    }
    
    int q;
    cin >> q;
    string dummy;

    getline(cin, dummy);
    while (q--)
    {
        string a;

        getline(cin, a);

        int n = a.size();
        string sub = a.substr(4, n - 4);

        int last = stoi(sub);
        int count = 0;

        if (a[0] == 'x')
        {   
            for (int i = 0; i < b;i++){
                
                if(last>x[i].first and last<x[i].second)
                    count++;
            }
            cout << count << "\n";
        }
               
        else
        {
            for (int i = 0; i < b; i++)
            {
                
                if (last > y[i].first and last < y[i].second)
                    count++;
                // cout << y[i].first << "   n " << y[i].second <<" c "<<count<< "\n";
            }
            cout << count << "\n";
        }
    }
    return 0;
}
