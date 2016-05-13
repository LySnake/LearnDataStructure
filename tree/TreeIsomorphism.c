/****************************************
 *
 *
 *
 * **************************************/
#include<stdio.h>

#define  FindValue(tree,index)  (*(tree+index*3))
#define  FindLeftSonIndex(tree, index) (*(tree + index * 3 + 1))
#define  FindRightSonIndex(tree, index) (*(tree + index * 3 + 2))
#define  FindLeftSonValue(tree, index)  (FindLeftSonIndex(tree, index) == '-'? 20 : FindValue(tree, FindLeftSonIndex(tree, index)))
#define  FindRightSonValue(tree, index)  (FindRightSonIndex(tree, index) == '-'? 20 : FindValue(tree, FindRightSonIndex(tree, index)))
//判断是否同构树
int IsIsomorphism( char* tree1,  char* tree2, int sum)
{
    int iRet = 1;
    int loop1 = 0;
    int loop2 = 0;

    for(loop1 = 0; loop1 < sum; loop1 ++)
    {
        for(loop2 = 0; loop2 < sum; loop2 ++ )
        {
            if(FindValue(tree1, loop1) == FindValue(tree2, loop2))
            {
                break;
            }
        }

        if(loop2 < sum)//find
        {
            if(FindLeftSonValue(tree1 , loop1) == FindLeftSonValue(tree2, loop2))
            {
                if(FindRightSonValue(tree1 , loop1) == FindRightSonValue(tree2, loop2))
                {
                    continue;
                }
            }
            else if(FindRightSonValue(tree1 , loop1) == FindLeftSonValue(tree2, loop2))
            {
                if(FindLeftSonValue(tree1 , loop1) == FindRightSonValue(tree2, loop2))
                {
                    continue;
                }

            }

            iRet = 0;
            break;
        }
        else if(loop2 == sum)//not find
        {
            iRet = 0;
            break;
        }

    }

    return iRet;
}


int main()
{
  //树说明：char  *tree每三个char为一个node,每个node的第一个char为data,第二个char为左子树在tree中的索引，第三个char为右子索引，步进为sizof(node)==3
#if 0  //No      
    char tree1[] = {'B',5,7,'F','-','-','A',0, 3,'C',6,'-','H','-','-','D','-','-','G',4,'-','E',1,'-'};
    char tree2[] = {'D',6,'-','B',5,'-','E','-','-','H','-','-','C',0,2,'G','-',3,'F','-','-','A',1,4};
#else  //Yes
    char tree1[] = {'A',1,2,'B',3,4,'C',5,'-','D','-','-','E',6,'-','G',7,'-','F','-','-','H','-','-'};
    char tree2[] = {'G','-',4,'B',7,6,'F','-','-','A',5,1,'H','-','-','C',0,'-','D','-','-','E',2,'-'};
#endif

    printf("%s",IsIsomorphism(tree1, tree2 , 8) ? "Yes":"No");
    return 0;
}
