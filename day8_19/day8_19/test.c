#include <stdio.h>


int myAtoi(char* s) {
	int i,n,sign;
	for(i=0;isspace(s[i]);i++)//�����հ׷�;
		sign=(s[i]=='-')?-1:1;
	if(s[i]=='+'||s[i]==' -')//��������
		i++;
	for(n=0;isdigit(s[i]);i++)
		n=10*n+(s[i]-'0');//�������ַ�ת������������
	return sign *n;
}

int main()
{	
	char s[100];
	gets(s);
	printf("integer=%d\n",atoi(s));
	return 0;

}