#include<stdio.h>

#define N 5

int main()
{
int i,p,q,t,arr[N];
for(i=0;i<N;i++) 
arr[N] = i;
while(scanf("%d %d",&p,&q)==2)
{
if(arr[p] == arr[q])
    continue;
for(t = arr[p],i=0;i<N;i++)
    if(arr[i] == t)
	arr[i] = arr[q];
printf("%d %d\n",p,q);
}
}
