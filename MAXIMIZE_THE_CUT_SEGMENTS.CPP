#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends



class Solution
{
    public:
    vector<int>v;
    int dp[3][10010];
    int recur(int index,int l){
        // cout<<l<<" "<<index<<"\n";
        if(l == 0 ){
            return 0;
        }
        if(l<0 || index==3)
            return INT_MIN;
            
        if(v[index]>l)
            return recur(index+1,l);
            
        if(dp[index][l]!=-1)
            return dp[index][l];

        int ans=max(1+recur(index,l-v[index]),recur(index+1,l));
        return dp[index][l]=ans;
    }



    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int X, int Y, int Z)
    {
        //Your code here
        v.push_back(X);v.push_back(Y);v.push_back(Z);
        for(int i=0;i<3;i++){
            for(int j=0;j<n+1;j++){
                dp[i][j]=-1;
            }
        }
        return max(0, recur(0, n));   //0 because if our program returns int_min as answer we should return 0 because negative cuts are not possible
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t=1;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}