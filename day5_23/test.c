#include<stdio.h>
#define N 5

void show(int arr[N][N])
{
  int i = 0;
  int j = 0;
  for(i= 0;i<N;i++)
   {
	for(j=0;j<N;j++)
	{
	printf("%d",arr[i][j]);
	}
	printf("\n");
  } 
}

int main()
{
  int i = 0;
  int j = 0;
  int c =(N+1)/2;
  int k = 0;
  int num = 1;
  int arr[N][N] = {0};
  for(k=0;k<c;k++)
   {
	while(j<N-k)
	{
	arr[i][j] = num++;
	j++;
	}
	j++;
	i--;
	while(i<N-k)
	{
	arr[i][j] = num++;
	i++;	
	}
	j--;
	i--;
	while(j>=k)
	{
	arr[i][j] = num++;
	j--;
	}
	j++;
	i--;
	while(i>k)
	{
	arr[i][j] = num++;
	j++;
	}
	i++;
	j++;
   }

	show(arr);

}
