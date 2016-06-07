#include<stdio.h>
#define Copmare(i,j)  ((i) > (j)? 1 : 0)
typedef int ElementType;
//冒泡算法:复杂度O（n^2），无额外空间
void BubbleSort(ElementType Data[], int n)
{
    int i = 0;
    int j = 0;
    ElementType temp;

    for( i = 0; i < n - 1; i ++)
    {
        for(j = 0; j < n - i - 1; j ++  )
        {
            if(Copmare(Data[j], Data[j + 1]))
            {
                temp = Data[j + 1];
                Data[j + 1] = Data[j];
                Data[j] = temp;
            }
        }
    }

}

void main()
{
    int i;
    ElementType Data[] = {2,1,12,34,5,54,3,5,7,4};

    BubbleSort(Data, sizeof(Data)/sizeof(ElementType));

    for(i = 0; i < sizeof(Data)/sizeof(ElementType); i++)
    {
        printf("%d  ",Data[i]);
    }
}
