#include <iostream>
#include<bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define nl cout<<"\n"

//QUEUE USING 2 STACKS
/*Maintain two stacks and also a variable called front which is used to know what number is at the front of the queue
for push  --> If the stack one is empty then the front variable becomes number that we are pushing into the stack 1 and then push the number to the stack 1
for pop  ---> If stack 2 is not empty then push all the elements from stack 1 to stack 2 then pop and print the top element in the stack which would be the front in the queue
for front --> if stack 2 is not empty then the top element of stack would be the front element but if the stack is element then directly print the front variable
*/

void solve(){
    int q;
    cin>>q;
    stack <int>s1,s2;
    int front = 0;
    fo(i,0,q){
        string s;
        cin >> s;
        if(s=="push"){
            int c;
            cin>>c;
            if(s1.empty()){
                front =c;  
            }
            s1.push(c);
        }
        else if(s=="pop"){

            if(s2.empty()){
                while(!s1.empty()){
                	s2.push(s1.top());
                    s1.pop();
                }   
            }
            cout<<s2.top()<<"\n";
            s2.pop();
        }
        else{
            //This is for s ="front"
            if(s2.empty()){
                cout<<front<<"\n";
            }
            else{
                cout<<s2.top()<<"\n";
            }
            
        }
    }
} 

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t ;
    cin >> t;
    //string s;
    //getline(cin,s);
    while (t--)
    {
        solve();
    }
}