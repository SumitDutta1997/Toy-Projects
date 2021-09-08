//Function to find out the number of ways we can place a black and a 
//white Knight on this chessboard such that they cannot attack each other.

/*

i+2,j-1 \ i-2,j-1 \ i+1,j-2 \ i-1,j-2
i+2,j+1 \ i-2,j+1 \ i+1,j+2 \ i-1,j+2

        K - Knight Position
        X - Where Another Knight Can't be placed

        So we exclude X and K from main result
        
        +---+---+---+---+---+
        |   | X |   | X |   |
        +---+---+---+---+---+
        | X |   |   |   | X |
        +---+---+---+---+---+
        |   |   | K |   |   |
        +---+---+---+---+---+
        | X |   |   |   | X |
        +---+---+---+---+---+
        |   | X |   | X |   |
        +---+---+---+---+---+
    
*/

int noOfAttacks(int i, int j, int N, int M) 
{
    int res=0;
    
    if(i+2 <= N && j-1 > 0)
        res++;
    if(i-2 > 0 && j-1 > 0)
        res++;
    if(i+1 <= N && j-2 > 0)
        res++;
    if(i-1 > 0 && j-2 > 0)
        res++;
    if(i+2 <= N && j+1 <= M)
        res++;
    if(i-2 > 0 && j+1 <= M)
        res++;
    if(i+1 <= N && j+2 <= M)
        res++;
    if(i-1 > 0 && j+2 <= M)
        res++;
        
    return res;
}

long long numOfWays(int N, int M)
{
    // write code here
    long long sum = 0;
    
    for(long long i=1 ; i<=N ; i++)
    {
        for(long long j=1 ; j<=M ; j++)
        {
            int attacks = noOfAttacks(i,j,N,M);
            sum += (N*M-1)-attacks;
        }
    }
    
    return sum%1000000007; 
}
