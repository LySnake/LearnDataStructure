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
