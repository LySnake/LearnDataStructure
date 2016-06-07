#include<stdio.h>
#define Compare(i,j) ((i) > (j) ? 1: 0)
typedef int ElementType;
//插入排序:复杂度O（n^2），无额外空间开支
//模拟抓牌
void InsertionSort(ElementType Data[], int n)
{
    int i;
    int j;
    ElementType temp;

    for(i = 1; i < n; i ++ )
    {
        for( j = i; j > 0; j --)
        {
            if(!Compare(Data[j], Data[j - 1]))
            {
                temp = Data[j];
                Data[j] = Data[j - 1];
                Data[j - 1] = temp;
            }
        }

    }
}


void main()
{
    int i;
    ElementType Data[] = {2,1,12,34,5,54,3,5,7,4};

    InsertionSort(Data, sizeof(Data)/sizeof(ElementType));

    for(i = 0; i < sizeof(Data)/sizeof(ElementType); i++)
    {
        printf("%d  ",Data[i]);
    }
}
