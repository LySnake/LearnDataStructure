#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int   DATA;
typedef  struct Node{
    DATA   value;
    int    flag;
    struct Node*  pLeft;
    struct Node*  pRight;
}Node;

#define compare( x, y)   ((x)>(y)?1:0)
#define CreateNode()    ((Node*)calloc(1, sizeof(Node)))
#define SetNodeValue(Node, Value)  ((Node) -> value = (Value))



Node* Insert(Node *pTree, Node *pNewNode)
{
    Node *pNode = pTree;

    if(!pTree)
    {
        pTree = pNewNode;
    }

    while(pNode)
    {
        if(compare(pNode -> value, pNewNode -> value))
        {
            if(pNode -> pLeft)
                pNode = pNode -> pLeft;
            else
            {
                pNode -> pLeft = pNewNode;
                break;
            }
        }
        else
        {
            if(pNode -> pRight)
                pNode = pNode -> pRight;
            else
            {
                pNode -> pRight = pNewNode;
                break;
            }
        }
    }


    return pTree;

}

void DestroyTree(Node *pTree)
{
    if(pTree)
    {
        DestroyTree(pTree -> pLeft);
        DestroyTree(pTree -> pRight);
        free(pTree);
    }
}

int Exist(Node* pTree , DATA value)
{
    while(pTree)
    {
        if(pTree -> flag == 1)
        {
            if(compare(pTree -> value, value))
            {
                pTree = pTree -> pLeft;
            }
            else if(compare(value, pTree -> value))
            {
                pTree = pTree -> pRight;
            }

        }
        else if(pTree -> value == value)
        {
            pTree -> flag = 1;
            break;
        }
        else
        {
            return 0;
        }
    }
    return 1;

}

int IsEquallyTree( DATA *arr1, DATA *arr2, int num)
{
    Node * pHead1 = NULL;
    Node * pHead2 = NULL;
    Node * pNewNode = NULL;
    Node * pNode1 = NULL;
    int loop;

    for(loop = 0; loop < num; loop ++ )
    {
        pNewNode = CreateNode();
        if(!pNewNode)
        {
            printf("Can`t calloc mem!");
        }
        SetNodeValue(pNewNode, arr1[loop]);
        pHead1 = Insert(pHead1 , pNewNode);
    }


    for(loop = 0; loop < num; loop ++ )
    {
        if(!Exist(pHead1 , arr2[loop]))
            break;
    }
    DestroyTree(pHead1);
    DestroyTree(pHead2);

    if(loop == num)
        return 1;
    else
        return 0;
}
int main()
{
    DATA arr1[] = {3,1,4,2};
    DATA arr2[] = {3,4,1,2};

    printf("%s\n",IsEquallyTree(arr1, arr2, sizeof(arr1)/sizeof(DATA))?"Yes":"No");

    DATA arr3[] = {2,1};
    DATA arr4[] = {1,2};
    printf("%s\n",IsEquallyTree(arr3, arr4, sizeof(arr3)/sizeof(DATA))?"Yes":"No");
}
