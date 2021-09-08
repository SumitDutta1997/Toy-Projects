class Solution{
    public:
    
    bool isSafe(int i, int j, int n, vector<vector<int>>m)
    {
        if(i>=0 && i<n && j>=0 && j<n && m[i][j]==1)
            return true;
        else
            return false;
    }
    
    void solve(vector<vector<int>>m, int n, vector<string>&res, string s, int i, int j)
    {
        if(i==n-1 && j==n-1 && m[i][j]==1)
        {
            res.push_back(s);
            return;
        }
        
        if(isSafe(i,j,n,m)==true)
        {
            m[i][j]=0;
            solve(m,n,res,s+"D",i+1,j);
            solve(m,n,res,s+"R",i,j+1);
            solve(m,n,res,s+"U",i-1,j);
            solve(m,n,res,s+"L",i,j-1);
            m[i][j]=1;
        }
        return;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> res;
        string s="";
        solve(m,n,res,s,0,0);
        sort(res.begin(),res.end());
        return res;
    }
};