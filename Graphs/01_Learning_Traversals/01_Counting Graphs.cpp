// Counting Graphs

int countingGraphs(int N)
{   
    if(N == 1)  return 1 ;

    int edges = N * (N - 1)/ 2 ;
    return 1 << (edges) ;   // 2^edges
}