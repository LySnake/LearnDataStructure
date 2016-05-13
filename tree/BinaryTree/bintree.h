#ifndef __BINTREE_H__
#define __BINTREE_H__
typedef int DATA;
typedef struct  node
{
    DATA  value;
    Node *pLeft;
    Node *pRight;
    Node *pRoot;
    int   iHigh;
}Node;
typedef Node Tree;

#define CreateNode()  ((Node*)calloc(1,sizeof(Node)))
#define ABS(x,y)  ((x) > (y)? (x)-(y) : (y) - (x))
#define BalanceFactor(pTree)  ABS((pTree) -> pLeft -> iHigh ,(pTree) -> pRight -> iHigh)

Tree* Rotation(Tree *pTree, Node* pNode );
Tree *InsertNode(Tree*);
void FreeTree(Tree*);
void PrintTreeForDLR(Tree*);
void PrintTreeForLDR(Tree*);
void PrintTreeForLRD(Tree*);

#endif


