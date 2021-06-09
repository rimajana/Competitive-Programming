#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9 + 7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

/*postorder traversal  left right root 
        1
    2         3
4       5   6    7
8

8 4 5 2 6 7 3 1
*/

struct node
{                  //creating a struct node which contains data and 2 pointers left and right
    int data;
    struct node *left, *right;
};

node *newNode(int data)        
{
    struct node *node = (struct node *)malloc(sizeof(struct node));   
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void postorder(node* root)
{
    stack<node*> s;
    node *prev = NULL;
    s.push(root);
    node *extra = NULL;
    //HERE WE ARE DELETING THE NODE(EQUATING TO NULL) AFTER COMPLETELY VISITING IT AND GOING TO ITS PARENT NODE
    while (!s.empty())
    {
        if (root->left != NULL)
        {
            prev = root;
            s.push(root->left);
            root = root->left;
        }
        else if (root->right != NULL)
        {
            prev = root;
            s.push(root->right);
            root = root->right;
        }
        else
        {
            cout << s.top()->data <<"\n";
           
            
            if (prev->left == s.top())
                prev->left = NULL;

            else{
                
                if(prev==root)
                    extra = s.top();
                else
                {
                    prev->right = NULL;
                }
                
            }
            s.pop();
            if (!s.empty())
                root = s.top();

            if (!(extra = NULL) && root->left == extra)
                root->left = NULL;
            else if (!(extra = NULL) && root->right == extra)
            {
                root->right = NULL;
            }
            extra = NULL;
        }

    }
}

void solve()
{

    node *root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    root->left->left->left= newNode(8);
     postorder(root);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t = 1;
    solve();
}