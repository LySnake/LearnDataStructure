#define MAXINDEX   1024
typedef struct mgraph
{
    int G[MAXINDEX][MAXINDEX];
    int iNodeNum;

}MGraph;

int Floyd(const MGraph *Graph, WeightTye D[][MAXINDEX], Vertex path[][MAXINDEX])
{
    Verter i, j, k ;

    /*Init*/
    for(i = 0; i< Graph -> iNodeNum; i ++ )
        for(j = 0; j< Graph -> iNodeNum; j ++ )
        {
            D[i][j] = Graph -> G[i][j];
            path [i][j] = -1;
        }

    for(k = 0; k< Graph -> iNodeNum; k ++ )
        for(i = 0; i< Graph -> iNodeNum; i ++ )
            for(j = 0; j< Graph -> iNodeNum; j ++ )
            {
                if( D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
                if(i == j && D[i][j] < 0)
                    return -1;
                path[i][j] = k;
            }

    return 0;
}

