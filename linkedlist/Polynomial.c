/*************************************
 *按指数从大到小，存储的Polynomial结构体，
 *实现对二个Polynomial结构体进行加减法。
 * ************************************/
#include<stdio.h>
#define MAXNUM  1001

typedef struct
{
    int coeff[MAXNUM];//多项式系数
    int exp[MAXNUM];//多项式指数
    int sum;         //多项式项数
}Polynomial;

//打印一个Polynomial
int print(Polynomial z)
{
    int loop;
    printf("%d ", z.sum);
    for(loop = 0; loop < z.sum;loop ++)
    {
        printf("%d %d ",z.coeff[loop], z.exp[loop]);
    }
    printf("\n");
    return 0;
}
//加法
int add(const Polynomial *x, const Polynomial *y,Polynomial *z)
{
    unsigned int indexForX = 0;
    unsigned int indexForY = 0;
    unsigned int indexForZ = 0;
    for(;indexForX < x -> sum && indexForY < y -> sum; )
    {
        if(x -> exp[indexForX] > y -> exp[indexForY])
        {
           z -> coeff[indexForZ]  = x -> coeff[indexForX];
           z -> exp[indexForZ]  = x -> exp[indexForX];
           indexForX ++;
           indexForZ ++;
        }
        else if(x -> exp[indexForX] < y -> exp[indexForY])
        {
           z -> coeff[indexForZ]  = y -> coeff[indexForY];
           z -> exp[indexForZ]  = y -> exp[indexForY];
           indexForY ++;
           indexForZ ++;
        }
        else
        {
            z -> coeff[indexForZ] = x -> coeff[indexForX] + y -> coeff[indexForY];
            z -> exp[indexForZ]  = y -> exp[indexForY];
            indexForX ++;
            indexForY ++;
            indexForZ ++;
        }
    }

    for (; indexForX < x -> sum; )
    {
       z -> coeff[indexForZ]  = x -> coeff[indexForX];
       z -> exp[indexForZ]  = x -> exp[indexForX];
       indexForX ++;
       indexForZ ++;
    }
    for(; indexForY < y -> sum;)
    {
       z -> coeff[indexForZ]  = y -> coeff[indexForY];
       z -> exp[indexForZ]  = y -> exp[indexForY];
       indexForY ++;
       indexForZ ++;
    }
    z -> sum = indexForZ;
    return 0;
}
//乘法
int mult(const Polynomial *x, const Polynomial *y,Polynomial *z)
{
    unsigned int indexForX = 0;
    unsigned int indexForY = 0;
    Polynomial Temp1 = {};
    Polynomial Temp2 = {};

    for (indexForX = 0; indexForX < x -> sum; indexForX ++)
    {
        for(indexForY = 0;indexForY < y -> sum; indexForY ++)
        {
            Temp1.coeff[indexForY] = x -> coeff[indexForX] * y -> coeff[indexForY];
            Temp1.exp[indexForY] = x -> exp[indexForX] + y -> exp[indexForY];
        }
        Temp1.sum = y -> sum;
        add(&Temp1, &Temp2, z);
        Temp2 = *z;
    }

    return 0;
}

int main()
{
    Polynomial x = {{3,-5,6,-2},{4,2,1,0},4};
    print(x);
    Polynomial y = {{5,-7,3},{20,4,1},3};
    print(y);
    Polynomial z = {};
    //add(&x, &y, &z);
    mult(&x, &y, &z);

    print(z);
    return 0;
}
