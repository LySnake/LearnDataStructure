#ifndef __BINTREE_H__
#define __BINTREE_H__
typedef int DATA;
typedef struct  node
{
    DATA  value;
    struct node *pLeft;
    struct node *pRight;
    int   iHigh;
}Node;
typedef Node Tree;

#define CreateNode()  ((Node*)calloc(1,sizeof(Node)))
#define ABS(x,y)  ((x) > (y)? (x)-(y) : (y) - (x))
#define GetHight(ptree) ((ptree) == NULL? -1:(ptree)->iHigh)
#define BalanceFactor(ptree)  ABS(GetHight((ptree)->pLeft), GetHight((ptree)->pRight))

Tree* Rotation(Tree *pTree, Node* pNode );
int InsertNode(Tree**,Node*);
void FreeTree(Tree*);
void PrintTreeForDLR(Tree*);
void PrintTreeForLDR(Tree*);
void PrintTreeForLRD(Tree*);

#endif


