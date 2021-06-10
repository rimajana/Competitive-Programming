#include <iostream>
#include <bits/stdc++.h>
#define MOD 1e9+7
#define fo(i, a, p) for (int i = (a); i < p; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define endl '\n'

/*POSTORDER TRAVERSAL IS NOTHING BUT VISITING THE PARENT ROOT AFTER VISITING ITS LEFT ROOT AND RIGHT ROOT

example 1:
               1
        2             3
    4       5     6       7

ans:  4 5 2 6 7 3 1
*/

//POSTORDER TRAVERSAL WITHOUT RECURSION (BY USING 2 STACKS)
/* Here first we are adding the root node to stack1 and then we are pushing the node present at the top of stack 1 into s2 
and popping it from s1 and then pushing its left and right node into the stack 1 
and we are continuing the process unless s1 becomes empty*/

//when s1 becomes empty we finally print the stack 2 in reverse order(top to bottom) by popping the element and printing it until s2 becomes empty


//creating a struct node
struct Node
{
    int data;
    struct Node *left, *right;
};

//for creating new node
Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

stack<Node *> s1,s2;


void post_order(Node* root){
    s1.push(root);
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
        if(s2.top()->left!=NULL){
            s1.push(s2.top()->left);
        }
        if(s2.top()->right!=NULL){
            s1.push(s2.top()->right);
        }
    }
    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << "\n";
}


void solve()
{
    // constructing the tree by using the above example
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    // //example 2
    // Node *root = newNode(8);
    // root->left = newNode(3);
    // root->right = newNode(10);
    // root->left->left = newNode(1);
    // root->left->right = newNode(6);
    // root->left->right->left = newNode(4);
    // root->left->right->right = newNode(7);
    // root->right->right = newNode(14);
    // root->right->right->left = newNode(13);


    post_order(root);
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}