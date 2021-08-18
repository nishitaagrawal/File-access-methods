#include <stdio.h>  //Direct file access
#include <stdlib.h>
typedef struct student  // structure of student
{
    char name[20];
    int prn;
}st;
void create_index(long index[], int prn, long relative_add){  //address of record - relative add
    index[prn]=relative_add;
}
void write_rec(FILE *fptr, st rec)
{
    fwrite(&rec,sizeof(rec),1,fptr);
}
int main() {
    long relative_add=0;
    long index[20]; // stores relative address
    int prn,num,choice,i;
    st f_rec;
    FILE *rec_file=NULL,*index_file=NULL;
    for(i=0;i<20;i++)
	{
        index[i]=-1;  //-1 = record empty
    }
    printf("DIRECT \n ");
    rec_file=fopen("FILE.txt","w");
    if(rec_file==NULL)
	{
        printf("Error in opening file.\n");
        exit(0);
    }
    printf("Enter number of records: ");
    scanf("%d",&num);
    for(i=0;i<num;i++)
	{
        printf("\nEnter student name: ");
        scanf("%s",f_rec.name);
        printf("Enter prn: ");
        scanf("%d",&f_rec.prn);
        create_index(index, f_rec.prn, relative_add);
        write_rec(rec_file, f_rec);
        relative_add=ftell(rec_file);
    }
    index_file=fopen("Index_File.txt","w");
    if(index_file==NULL)
	{
        printf("Error in opening index file.\n");
        exit(1);
    }
    fwrite(index, sizeof(index), 1, index_file);
    fclose(rec_file);
    fclose(index_file);
    index_file=fopen("Index_File.txt","r");
    if(index_file==NULL)
	{
        printf("Error in opening file.\n");
        exit(3);
    }
    fread(index, sizeof(index), 1, index_file); 
    rec_file=fopen("FILE.txt","r");
    if(rec_file==NULL)
	{
        printf("Error in opening file.\n");
        exit(3);
    }
    printf("\n----MENU----\nPress 1 to Print all records.\nPress 2 to Search for a record with prn.\nPress 3 to exit");
    while(choice!=3){
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch (choice) {
            case 1:
                printf("\nDISPLAY RECORDS  \n");
                while((fread(&f_rec,sizeof(f_rec),1,rec_file))!=0){
                    printf("\nNAME : %s \nPRN : %d \n\n**********",f_rec.name,f_rec.prn);
                }
                break;
            case 2:
                printf("\nEnter the prn to search : ");
                scanf("%d",&prn);
                relative_add=index[prn];
                if((fseek(rec_file,relative_add,SEEK_SET))!=0){
                    printf("\nERROR!\n");
                    exit(4);
                }
                fread(&f_rec, sizeof(f_rec), 1, rec_file);
                printf("\nRECORD EXISTS\n \nNAME : %s \nPRN : %d",f_rec.name,f_rec.prn);
                break;
            case 3: break;
            default:
                printf("Invalid Choice!\n");
                break;
        }
    }
    fclose(index_file);
    fclose(rec_file);
    return 0;
}
