#include<stdio.h>
#include<stdlib.h>
#define Compare(i, j) ((i) > (j)? 1 : 0)

typedef int ElementType;


void MergeSort( ElementType Data[], int n)
{
    int iStep;
    int iLeftIndex;
    int iRightIndex;
    int iMiddle;
    int i;
    int j;
    int z;
    ElementType *pCopyArr1 = NULL;
    ElementType *pCopyArr2 = NULL;
    ElementType *pData = (ElementType *)malloc(n * sizeof(ElementType));
    pCopyArr1 = pData;
    pCopyArr2 = Data;

    if(pData)
    {
        for(iStep = 1; iStep < n ; iStep << 1)
        {
            for(iLeftIndex = 0, iRightIndex = iLeftIndex + iStep; iRightIndex < n; iLeftIndex += iStep, iRightIndex += iStep)
            {
                iMiddle = iLeftIndex + iRightIndex;
                for(i = iLeftIndex, z = iLeftIndex, j = iMiddle + 1; i <= iMiddle && j <= iRightIndex; i++, j++)
                {
                    if(Compare(i, j))
                    {
                        pCopyArr1[z++] = pCopyArr2[j];
                    }
                    else
                    {
                        pCopyArr1[z++] = pCopyArr2[i];
                    }
                    if(i <= iMiddle)
                    {
                        memcpy(pCopyArr1 + z, pCopyArr2 + i, iMiddle - i + 1);
                    }
                    else if(j <= iRightIndex)
                    {
                        memcpy(pCopyArr1 + z, pCopyArr2 + j, iRightIndex - i + 1);
                    }

                }
            }

        }

    }
    else
    {
        printf("Out of memory!");
    }
}
