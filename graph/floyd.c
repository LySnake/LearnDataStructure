#define MAXINDEX   1024   //最大节点数
typedef struct mgraph
{
    int G[MAXINDEX][MAXINDEX];  //邻接矩阵表示图
    int iNodeNum;               //实际节点数

}MGraph;
/*
Graph :邻接矩阵表示的图
D：     输出多源节点最短路径的图
path:   二节点间最短路径，可用递归打印输出
*/
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
                path[i][j] = k;
            }

    return 0;
}

