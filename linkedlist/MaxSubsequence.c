/**************************************************************
 *算法功能 ：对一个数据，求它最大子列和。
 *算法描述 ：从下标为0开始扫描数据，CurrMax为最大子列合，ThisMax是当前扫描的子列合。
 *           当ThisMax < 0时，ThisMax总是会使下一个数最小，则记ThisMax为0，重新记录。
 *           当ThisMax > CurrMax 时，更新CurrMax
 *算法优点： 时间复杂度为O(n)
 **************************************************************/
#include<stdio.h>
int main()
{
    unsigned int loop = 0;
    unsigned int k = 0;
    int CurrMax = 0;
    int ThisMax = 0;
    int arr[100001] = {};
	 unsigned int i;
	 unsigned MaxLeftIndex , MaxRightIndex; //记录CurrMax的左右index
	do
	{
		scanf("%u",&k);
	} while(k > 100000);
	for(loop = 0; loop < k; loop ++)
	{
		scanf("%d",&arr[loop]);
	}

	for(loop = 0, i = 0, MaxLeftIndex = 0, MaxRightIndex = 0; loop < k ;loop ++)
	{
		ThisMax += arr[loop];


		if(ThisMax > CurrMax )
		{
			MaxRightIndex = loop;
			MaxLeftIndex = i;
		    CurrMax = ThisMax;

		}
		else if(ThisMax  < 0 )
		{
			i = loop + 1;
			ThisMax = 0;
		}
	}

	return  0 ;
}





