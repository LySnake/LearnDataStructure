#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Compare(i, j) ((i) > (j)? 1 : 0)

typedef int ElementType;


void Merge(ElementType *pSrc, ElementType *pDest,int iLeftIndex, int iMiddle, int iRightIndex)
{
    int i = iLeftIndex;
    int z = iLeftIndex;
    int j = iMiddle + 1;
   for(; i <=iMiddle && j <= iRightIndex;)
   {
       if(Compare(*(pSrc + i), *(pSrc + j)))
       {
           pDest[z++] = pSrc[j++];
       }
       else
       {
           pDest[z++] = pSrc[i++];
       }
   }

   if(i <= iMiddle)
   {
       memcpy(pDest + z, pSrc + i, (iMiddle - i + 1) * sizeof(ElementType));
   }
   else if(j <= iRightIndex)
   {
       memcpy(pDest + z, pSrc + j, (iRightIndex - j + 1) * sizeof(ElementType));
   }
}

void MergeSort( ElementType Data[], int n)
{
    int iStep;
    int iLeftIndex;
    int iRightIndex;
    ElementType *pCopyArr1 = NULL;
    ElementType *pCopyArr2 = NULL;
    ElementType *pData = (ElementType *)malloc(n * sizeof(ElementType));
    pCopyArr1 = Data;
    pCopyArr2 = pData;

    if(pData)
    {
        for(iStep = 2; iStep < n ; iStep <<= 1)
        {
            for(iLeftIndex = 0, iRightIndex = iLeftIndex + iStep; iRightIndex < n ; iLeftIndex = iRightIndex, iRightIndex += iStep)
            {
                Merge(pCopyArr1, pCopyArr2, iLeftIndex, (iLeftIndex + iRightIndex - 1) / 2, iRightIndex - 1);
            }
            Merge(pCopyArr1, pCopyArr2, iLeftIndex, (iLeftIndex + n - 1) / 2, n - 1);

            pData = pCopyArr1;
            pCopyArr1 = pCopyArr2;
            pCopyArr2 = pData;
        }
        Merge(pCopyArr1, pCopyArr2, 0, iLeftIndex - 1, n - 1);
    }
    else
    {
        printf("Out of memory!");
    }
    if(pCopyArr2 != Data )
    {
        memcpy(pCopyArr2, pCopyArr1, sizeof(ElementType) * n);
    }
}



void main()
{
    int i;
    ElementType Data[] = {2,1,12,34,5,54,3,5,7,4};

    MergeSort(Data, sizeof(Data)/sizeof(ElementType));

    for(i = 0; i < sizeof(Data)/sizeof(ElementType); i++)
    {
        printf("%d  ",Data[i]);
    }
}

