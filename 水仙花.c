#include<stdio.h>
int main()
	{
	int i,sum;
	int a,b,c;
	for(i=0;i<999;i++)
	{	
	a=i/100;   //  153����100�õ�1 
	b=(i%100)/10;  //	153��100ȡ��õ�53,53��10ȡ��õ�3
	c=i%10;
	sum = a*a*a+b*b*b+c*c*c;
	if (i == sum && i != 0 && i !=1)
	{
	printf("%d  ",i);
	}
	}
	return 0;
	}