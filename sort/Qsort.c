#include<stdio.h>
#define Compare(i, j) ((i) > (j) ? 1: 0)
typedef int ElementType;

void swap(ElementType *a , ElementType *b)
{
    ElementType temp ;
    temp = *a;
    *a = *b;
    *b = temp;
}
/*******************************************************
 * 函数功能：在Arr[Left],Arr[(Left + Right)/2],Arr[Right]中，取中间值作为基数
 * Data:排序的数组
 * Left:被找基数的子Arr的最左Index
 * Right:被找基数的子Arr的最右Index
 *****************************************************/
ElementType Median3(ElementType Data[], int Left, int Right)
{
    int Center = (Left + Right) / 2;
    if(Compare(Data[Left], Data[Center]))
    {
        swap(Data + Left, Data + Center);
    }
    if(Compare(Data[Left], Data[Right]))
    {
        swap(Data + Left, Data + Right);
    }
    if(Compare(Data[Center], Data[Right]))
    {
        swap(Data + Center, Data + Right);
    }
    swap(Data + Center , Data + Right - 1);

    return Data[ Right - 1];
}
/*********************************************************************
 * 函数功能:快排，对于一个数组，选用一个基数，比基数大的，放于相对右，比基数小的，放于相对左边，中间放基数。左右二边再分边Qsort。可以设置当arr的元素个数不足100时使用冒泡算法，n相对小时，复杂排序反而优势不足。
 *平均复杂度（O(nlogn)）,最坏复杂度（O(n^2)）,额外空间（O（logn）），稳定性:不稳定 
 Data:被排数组
 * Left:最左元素
 * Right:最右元素
 ******************************************************************/

void Qsort(ElementType Data[], int Left, int Right)
{
    ElementType Pivot; //
    //int Cutoff;
    int Low;
    int High;

    if(Right - Left < 1)
        return ;
    Pivot = Median3(Data , Left, Right);
    Low = Left ;
    High = Right - 1;

    while(Low < High)
    {
        while(Compare(Pivot,Data[++Low]));
        while(Compare(Data[-- High], Pivot));
        if(Low < High)
        {
           swap(Data + Low, Data + High);
        }
        else
        {
            break;
        }
    }
    swap(Data + Low , Data + Right - 1);

    Qsort(Data, Left , Low - 1);
    Qsort(Data, Low + 1, Right);
}

void main()
{
    int i;
    ElementType Data[] = {2,1,12,34,5,54,3,5,7,4};

    Qsort(Data, 0, sizeof(Data)/sizeof(ElementType) - 1);

    for(i = 0; i < sizeof(Data)/sizeof(ElementType); i++)
    {
        printf("%d  ",Data[i]);
    }
}
