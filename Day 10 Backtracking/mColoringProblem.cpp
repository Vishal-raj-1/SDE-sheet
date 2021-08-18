bool isSafe(int node, int color[], bool graph[101][101], int col, int N){
    for(int i=0; i<N; i++){
        if(i != node && graph[i][node] == 1 && color[i] == col)
            return false;
    }
    return true;
}
bool solve(int node, int color[], bool graph[101][101], int m, int N){
    if(node == N)
        return true;
        
    //try for every color
    for(int i=1; i<=m; i++){
        if(isSafe(node, color, graph, i, N)){
            color[node] = i;
            if(solve(node+1, color, graph, m, N) == true)
                return true;
            else 
                color[node] = 0;
        }
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int N)
{
    // your code here
    int color[N] = {0};
    return solve(0, color, graph, m, N);
}