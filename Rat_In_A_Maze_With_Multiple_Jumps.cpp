//Function to find the minimum number of Hops required for the rat to 
//reach from the source block to the destination block. 

/*

2 1 0 0
3 0 0 1
0 1 0 1
0 0 0 1

*/

bool isSafe(int i, int j, int N, vector<int> maze[])
{
    if(i<N && j<N && maze[i][j]!=0)
        return true;
    else
        return false;
}

bool solveRec(int i, int j, int N, vector<int> sol[], vector<int> maze[])
{
    if(i==N-1 && j==N-1)
    {
        sol[i][j]=1;
        return true;
    }
    
    if(isSafe(i,j,N,maze)==true)
    {
        sol[i][j]=1;
        int jumps = maze[i][j];
        
        for(int k=1 ; k<=jumps ; k++)
        {
            if(solveRec(i,j+k,N,sol,maze)==true)
                    return true;
            if(solveRec(i+k,j,N,sol,maze)==true)
                return true;
        }
        
        sol[i][j]=0;
    }
    
    return false;
}

void solve(int N, vector<int> maze[]) 
{
    // write code here
    vector<int> sol[N];
    for(int i=0 ; i<N ; i++)
    {
        sol[i].assign(N,0);
    }
    
    if(solveRec(0,0,N,sol,maze) == false)
        cout << "-1" << endl;
    else
        print(N,sol);
}
