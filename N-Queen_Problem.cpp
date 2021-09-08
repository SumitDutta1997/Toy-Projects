class Solution{
public:

    bool isSafe(int row, int col, vector<vector<int>>&board, int N)
    {
        for(int i=0 ; i<col ; i++)
        {
            if(board[row][i])
                return false;
        }
        
        for(int i=row, j=col ; i>=0 && j>=0 ; i--, j--)
        {
            if(board[i][j])
                return false;
        }
        
        for(int i=row, j=col ; j>=0 && i<N ; i++, j--)
        {
            if(board[i][j])
                return false;
        }
        
        return true;
    }

    void solve(int col, int N, vector<vector<int>>&board, vector<vector<int>>&res)
    {
        if(col==N)
        {
            vector<int>temp;
            for(int i=0 ; i<N ; i++)
            {
                for(int j=0 ; j<N ; j++)
                {
                    if(board[i][j]==1)
                        temp.push_back(j+1);
                }
            }
            res.push_back(temp);
            return;
        }    
            
        for(int i=0 ; i<N ; i++)
        {
            if(isSafe(i,col,board,N)==true)
            {
                board[i][col]=1;
                
                solve(col+1,N,board,res);
                
                board[i][col]=0;
            }
        }
        
    }
    
    vector<vector<int>> nQueen(int n) {
        
        vector<vector<int>> res;
        vector<vector<int>> board(n,vector<int>(n,0));
        
        solve(0,n,board,res);
        sort(res.begin(),res.end());
		
        return res;
    }
};