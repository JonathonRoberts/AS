#include <stdio.h>

#define MAXLINECOUNT 1000

int main(int argc, char *argv[])
{
	FILE *fp;
	char a = ' ';
	char b;
	char line[MAXLINECOUNT][5][30];
	int linelc[MAXLINECOUNT];
	short int opcount;
	int i;
	int lineno=0;
	int lc=0;
	char tmp[30];

	fp=fopen("main.asm", "r");
	if(fp==0)
	{
		printf("cannot open main.asm\n");
	}

	/* First Pass */
	while(a!=EOF)
	{
		opcount = i = 0;
		a = ' ';
		while(a!='\n'&&a!=EOF)
		{
			b = a;
			a=getc(fp);

			switch(a)
			{
				case EOF:
					break;
				case '\n':
					linelc[lineno]=lc;
					if(opcount!=0)lc+=8;
					printf("LC=%d\n",linelc[lineno]);
					for(i=0;i<=opcount;i++)
						printf("%s ",line[lineno][i]);
					printf("\n");
					lineno++;

					break;
				case ' ':
				case '\t':
				case ',':
					a = ' ';
					if(b!=' ') opcount++;
					i = 0;
					break;
				default:
			line[lineno][opcount][i++] = a;
			}
		}

	}
	fclose(fp);
	return 0;
}
