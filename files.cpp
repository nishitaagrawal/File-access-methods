#include<stdio.h>
int main(int argc ,char *argv[])
{
	if(argc!=3)
	{
		printf("Error Plaese enter reqd arguements");
	}
	else
	{
		FILE *fp1=fopen(argv[1],"r");
		FILE *fp2=fopen(argv[2],"w");
		if(fp1==NULL)
		{
			printf("Error opening source file ");
		}
		if(fp2==NULL)
		{
			printf("Error opening dest file");
		}
		char ch=fgetc(fp1);
		while(ch!=EOF)
		{
			fputc(ch,fp2);
			ch=fgetc(fp1);
		}
		if (feof(fp1))
		{
			printf("\n Eof of soucre file reached");
		}
		else
		{
			printf("\nSometing went wrong with eof");
			printf("Sucessfully copied file ");
		}
		fclose(fp1);
		fclose(fp2);
	}
	getchar();
	return 0;
}


