/**************************************************************
 *�㷨���� ����һ�����ݣ�����������к͡�
 *�㷨���� �����±�Ϊ0��ʼɨ�����ݣ�CurrMaxΪ������кϣ�ThisMax�ǵ�ǰɨ������кϡ�
 *           ��ThisMax < 0ʱ��ThisMax���ǻ�ʹ��һ������С�����ThisMaxΪ0�����¼�¼��
 *           ��ThisMax > CurrMax ʱ������CurrMax
 *�㷨�ŵ㣺 ʱ�临�Ӷ�ΪO(n)
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
	 unsigned MaxLeftIndex , MaxRightIndex; //��¼CurrMax������index
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





