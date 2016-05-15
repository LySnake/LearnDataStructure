#include<stdio.h>
#include<malloc.h>
#include"bintree.h"

Tree* Rotation(Tree *pTree, Node* pNode )
{
    Tree* pTemp = NULL;

    if((pTree) -> pLeft != NULL &&pNode -> value < (pTree) -> pLeft -> value)
    {//LL R
        pTemp = (pTree) -> pLeft -> pRight;
        (pTree) -> pLeft -> pRight = pTree ;
        pTree = (pTree) -> pLeft;
       (pTree) -> pRight -> pLeft = pTemp;

       pTree -> pRight -> iHigh -= 2;
    }
    else if((pTree) -> pLeft != NULL && pNode -> value < (pTree) -> value && pNode -> value > (pTree) -> pLeft -> value)
    { //LR R
        Tree *pTreeTemp = pTree;
        pTree = pTree -> pLeft -> pRight;

        pTemp = pTree -> pLeft;
        pTree -> pLeft = pTreeTemp -> pLeft;
        pTreeTemp -> pLeft -> pRight = pTemp;

        pTemp = pTree -> pRight;
        pTree -> pRight = pTreeTemp;
        pTreeTemp -> pLeft = pTemp;

        pTree -> iHigh ++;
        pTree -> pLeft -> iHigh --;
        pTree -> pRight -> iHigh -=2;
    }
    else if((pTree) -> pRight != NULL && pNode -> value > (pTree) -> value && pNode -> value < (pTree) -> pRight-> value)
    { //RL R
        Tree *pTreeTemp = pTree;
        pTree = pTree -> pRight -> pLeft;

        pTemp = pTree -> pRight;
        pTree -> pRight = pTreeTemp -> pRight;
        pTreeTemp -> pRight -> pLeft = pTemp;

        pTemp = pTree -> pLeft;
        pTree -> pLeft = pTreeTemp;
        pTreeTemp -> pRight = pTemp;

        pTree -> iHigh ++;
        pTree -> pRight-> iHigh --;
        pTree -> pLeft-> iHigh -=2;
    }
    else
    { //RR R
        pTemp = (pTree) -> pRight -> pLeft;
        (pTree) -> pRight -> pLeft = pTree ;
        pTree = (pTree) -> pRight;
       (pTree) -> pLeft -> pRight = pTemp;

       pTree -> pLeft -> iHigh -= 2;
    }

    return pTree;
}

int InsertNode(Tree** ppTree, Node* pNode)
{
    int iHigh;
    if(!*ppTree)
    {
        *ppTree = pNode;
        iHigh = 0;

    }
    else
    {
        if((*ppTree) -> value > pNode -> value) //insert left
        {
           if((*ppTree) -> iHigh == InsertNode(&((*ppTree) -> pLeft) , pNode))
                 iHigh = ++((*ppTree) -> iHigh);
        }
        else //insert right
        {
             if((*ppTree) -> iHigh == InsertNode((&(*ppTree) -> pRight), pNode))
                 iHigh = ++((*ppTree) -> iHigh);
        }

        if(BalanceFactor(*ppTree) == 2) //check balance
        {
           *ppTree = Rotation(*ppTree, pNode );
           iHigh = (*ppTree) -> iHigh;
        }
    }

    return iHigh;
}

void FreeTree(Tree* pTree)
{
    if(pTree)
    {
        FreeTree(pTree -> pLeft);
        FreeTree(pTree -> pRight);
        free(pTree);
    }
}


void PrintTreeForDLR(Tree* pTree)
{
    if(pTree)
    {
        printf("%d--%d\n",pTree -> value, pTree -> iHigh);
        PrintTreeForDLR(pTree -> pLeft);
        PrintTreeForDLR(pTree -> pRight);
    }
}
void PrintTreeForLDR(Tree* pTree)
{
    if(pTree)
    {
        PrintTreeForLDR(pTree -> pLeft);
        printf("%d--%d\r\n",pTree -> value, pTree -> iHigh);
        PrintTreeForLDR(pTree -> pRight);
    }
}
void PrintTreeForLRD(Tree* pTree)
{
    if(pTree)
    {
        PrintTreeForLRD(pTree -> pLeft);
        PrintTreeForLRD(pTree -> pRight);
        printf("%d ",pTree -> value);
    }
}



int main()
{

    Tree * pTree = NULL;
    Node*  pNode = NULL;
    int loop = 0;

    for(loop = 10; loop > 0 ;loop --)
    {
        pNode = CreateNode();
        pNode -> value = loop;
        InsertNode(&pTree, pNode );
    }

    PrintTreeForLDR(pTree);

    FreeTree(pTree);
    pTree = NULL;
    return 0;
}
