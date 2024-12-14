
#include <bits/stdc++.h>
using namespace std;


// Note:- Basically we must need a inorder to construct a binary tree

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        // 2 means it is inorder
        
        if( a == b) return false;
        
        if(a == 2 || b == 2) return true;
        
        return false;
    }
};  

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int a,b; 
        cin>>a>>b;
        Solution obj;
        bool ans=obj.isPossible(a,b);
        cout<<ans<<"\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends