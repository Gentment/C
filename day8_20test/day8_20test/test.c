#define   _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

typedef enum{
	CODE,	// ����״̬
	YU_DAO_XIE_GANG,	// ���� /
	C_COMMENT,			// C ���ע��
	CPP_COMMENT,		// C++ ���ע��
	YU_DAO_XING			// C ��������� *
} Stata;


void Convert(FILE *fIn,FILE *fOut)
{
	Stata stata = CODE;
	const char *stata_desc[]=
	{
		"����״̬",
		"���� /",
		"C���ע��",
		"C++���ע��",
		"C�������*"
	};

	int ch;
	int nextCh;

	while (1)
	{
		ch = getc(fIn);

		if (ch == EOF)
		{
			break;
		}
		switch(stata)
		{
		case CODE:
			if (ch == '/')
			{
				stata = YU_DAO_XIE_GANG;
			}
			fputc(ch,fOut);
			break;
		case YU_DAO_XIE_GANG:
			if (ch == '*')
			{
				stata = C_COMMENT;
				fputc(ch,fOut);
			}
			else
			{
				stata = CODE;
			}
			break;
		case C_COMMENT:
			if (ch == '*')
			{
				stata = YU_DAO_XIE_GANG;
			}
			else
			{
				fputc(ch,fOut);
				if (ch == '\n')
				{
					fprintf(fOut,"//");
				}
			}
			break;
		case CPP_COMMENT:
			if (ch == '\n')
			{
				stata = CODE;
			}
			fputc(ch,fOut);
			break;
		case YU_DAO_XING:
			if (ch == '/')
			{
				stata = CODE;
				nextCh = fgetc(fIn);
				if (nextCh != '\n')
				{
					fputc('\n',fOut);
				}
				ungetc(nextCh,fIn);
			}
			else if (ch != '*' )
			{
				stata = C_COMMENT;
				fputc('*',fOut);
				fputc(ch,fOut);
			}
			else
			{
				fputc('*',fOut);
			}
			break;
		}
		printf("%s\n",stata_desc[stata]);
	}

}


int main()
{
	FILE *fIn = fopen("input.c","r");
	FILE *fOut = fopen("output.c","w");
	if (fIn == NULL)
	{
		perror("fopen input");
		return 1;
	}
	
	if (fOut == NULL)
	{
		perror("fopen output");
		return 1;
	}

	Convert(fIn,fOut);

	fclose(fOut);
	fclose(fIn);
	return 0;
}