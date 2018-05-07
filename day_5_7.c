//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//int main()
//{
//
//	int num = 0;
//	int count = 0;
//	printf("input\n");
//	scanf("%d",&num);
//
//	while(num)
//	{
//		num=num&(num-1);
//		count++;
//	}
//
//	printf("%d\n",count);
//	return 0;
//}


//void print(int num)
//{
//
//	if (num<=9)
//	{
//		printf("%d ",num);
//	}
//	else 
//	{
//		print(num/10);
//		printf("%d  ",num%10);
//	}
//}
//int main()
//{
//	int num = 0;
//
//	printf("input\n");
//	scanf("%d",&num);
//	print(num);
//	
//	return 0;
//}


//int main()
//{
//	int a=0;
//	int b=0;
//	int c=0;
//	int count =0;
//	scanf("%d%d",&a,&b);
//	c=a^b;
//	while(c>0)
//	{
//		c=c&(c-1);
//		count++;
//	}
//	printf("%d\n",count);
//	return 0;
//}
//
//int main()
//{
//	int num=0;
//	int i=0;
//	printf("input>\n");
//	scanf("%d",&num);
//
//	printf("奇数序列：\n");
//	for (i=31;i>=0;i=i-2)
//	{
//		printf("%d",(num>>i)&1);
//	}
//	printf("\n");
//	printf("偶数序列：\n");
//	for (i=30;i>=0;i=i-2)
//	{
//		printf("%d",(num>>i)&1);
//	}
//	printf("\n");
//	return 0;
//}

//int main()
//{
//
//	int i=2;
//	int num=10;
//	printf("%d\n",num&i);//10>>1  1010
//	return 0;			  //	   0101		
//}	


//struct Stu
//{
//	char name[10];
//	int age;
//	char sex[5];
//	double score;
//};
//
//void set_age1(struct Stu stu)
//{
//	stu.age = 18;
//}
//
//void set_age2(struct Stu* pStu)
//{
//	pStu->age =18;
//}
//int main()
//{
//	struct Stu stu;
//	struct Stu* pStu =&stu;
//	
//	stu.age = 20;
//	set_age1(stu);
//
//	pStu->age = 20;
//	set_age2(pStu);
//	return 0;
//}

//int main()
//{
//
//	int i=1;
//	int ret = (++i) + (++i) + (++i);
//	printf("%d\n",ret);
//	printf("%d\n",i);
//	return 0;
//}