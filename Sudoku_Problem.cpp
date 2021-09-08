class Solution 
{
    public:
     
    bool isSafe(int grid[N][N], int i, int j, int n)
    {
        for(int k=0 ; k<N ; k++)
        {
            if(grid[i][k] == n || grid[k][j] == n)
                return false;
        }
        
        int s = sqrt(N);
        int rs = i - i%s;
        int cs = j - j%s;
        
        for(int i=0 ; i<s ; i++)
        {
            for(int j=0 ; j<s ; j++)
            {
                if(grid[i+rs][j+cs] == n)
                    return false;
            }
        }
        
        return true;
    }
    
    bool SolveSudoku(int grid[N][N])  
    { 
        
        int i,j;
        for(i=0 ; i<N ; i++)
        {
            bool flag=false;
            for(j=0 ; j<N ; j++)
            {
                if(grid[i][j]==0)
                {
                    flag=true;
                    break;
                }
            }
            if(flag==true)
                break;
        }
        
        if(i==N && j==N)
            return true;
        
        for(int n=1 ; n<=N ; n++)
        {
            if(isSafe(grid,i,j,n)==true)
            {
                grid[i][j] = n;
                
                if(SolveSudoku(grid)==true)
                    return true;
                
                grid[i][j] = 0;
            }
        }
        
        return false;
    }
    
    void printGrid (int grid[N][N]) 
    {
        
        for(int i=0 ; i<N ; i++)
        {
            for(int j=0 ; j<N ; j++)
            {
                cout << grid[i][j] << " ";
            }
        }
    }
};