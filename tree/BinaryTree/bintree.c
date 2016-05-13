#include<stdio.h>
#include<malloc.h>
#include<bintree.h>

Tree* Rotation(Tree *pTree, Node* pNode );
{
    if(pNode -> value < (pTree) -> pLeft -> value)
    {
        //LL R
    }
    else if(pNode -> value < (pTree) -> value && pNode -> value > (pTree) -> pLeft -> value)
    {
        //LR R
    }
    else if(pNode -> value > (pTree) -> value && pNode -> value < (pTree) -> pRight-> value)
    {
        //RL R
    }
    else
    {
        //RRR
    }
    return pTree;
}
int *InsertNode(Tree* ppTree, Node* pNode)
{
    int iHigh;
    if(!*ppTree)
    {
        *ppTree = pNode;
        iHigh = 0;

    }
    else
    {
        if((*ppTree) -> value > pNode -> value)
        {
           if((*ppTree) -> iHigh == InsertNode((*ppTree) -> pLeft , pNode))
           {
                (*ppTree) -> iHigh ++;
           }
        }
        else
        {
            if((*ppTree) -> iHigh == InsertNode((*ppTree) -> pRight, pNode))
            {
                (*ppTree) -> iHigh ++;

            }
        }

        if(BalanceFactor(*ppTree) == 2)
        {
           *ppTree = Rotation(*ppTree, pNode );
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
        printf("%d ",pTree -> value);
        PrintTreeForDLR(pTree -> pLeft);
        PrintTreeForDLR(pTree -> pRight);
    }
}
void PrintTreeForLDR(Tree* pTree)
{
    if(pTree)
    {
        PrintTreeForDLR(pTree -> pLeft);
        printf("%d ",pTree -> value);
        PrintTreeForDLR(pTree -> pRight);
    }
}
void PrintTreeForLRD(Tree* pTree)
{
    if(pTree)
    {
        PrintTreeForDLR(pTree -> pLeft);
        PrintTreeForDLR(pTree -> pRight);
        printf("%d ",pTree -> value);
    }
}
