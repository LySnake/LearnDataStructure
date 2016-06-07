#include<stdio.h>
#define Compare(i, j) ((i) > (j) ? 1 : 0)
typedef int ElementType;
//希尔排序：效率上主要在于增量的选择，这里使用Sedgewick增量。
/********************************************************************************
 * 函数功能：把增量作为一个step，把Arr中的每个相邻step下标的元素进行排序，然后再使用更小的step。
 * Data:排序数组
 * n：数组元素个数
 *******************************************************************************/
void ShellSort(ElementType Data[], int n)
{
    int i;
    int D;
    int p;
    ElementType temp;
    int ShellIndex = 0;
    int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};

    for(ShellIndex = 0; Sedgewick[ShellIndex] >= n ; ShellIndex ++)
        ;

    for(D = Sedgewick[ShellIndex]; D > 0; D = Sedgewick[++ ShellIndex] )
    {
        //插入排序
        for( p = D; p < n ; p ++)
        {
            temp = Data[p];
            for(i = p ; i >= D && Data[i - D] > temp; i -= D)
            {
                Data[i] = Data[i - D];
            }
            Data[i] = temp;
        }

    }
}


void main()
{
    int i;
    ElementType Data[] = {2,1,12,34,5,54,3,5,7,4};

    ShellSort(Data, sizeof(Data)/sizeof(ElementType));

    for(i = 0; i < sizeof(Data)/sizeof(ElementType); i++)
    {
        printf("%d  ",Data[i]);
    }
}
