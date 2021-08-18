#include<iostream>
using namespace std;
class sequential
{
	public:
	  int prn;
	  char name[20];
	  int m1,m2,m3;
}s;
void display(FILE *fp)
{
	rewind(fp);  //sets the file position to the beginning of the file for the stream pointed to by stream.
	while(fread(&s,sizeof(s),1,fp))
	{
		cout<<"\nPRN : "<<s.prn;
		cout<<"\nNAME : "<<s.name;
		cout<<"\nMarks 1 : "<<s.m1;
		cout<<"\nMarks 2 : "<<s.m2;
		cout<<"\nMarks 3 : "<<s.m3;
		cout<<"\n\n*************************************";
	}
}
int search(FILE *fp,int usn_key)
{
	rewind(fp);
	while(fread(&s,sizeof(s),1,fp))
	{
		if(s.prn == usn_key){ return 1; }	
	}
	return 0;
}
void read(FILE *fp,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		cout<<"\nSTUDENT No. "<<i+1<<" ";
		cout<<"\n\nEnter prn :";
		cin>>s.prn;
		cout<<"Enter Name:";
		cin>>s.name;
		cout<<"Enter Marks for 3 subjects : ";
		cin>>s.m1>>s.m2>>s.m3;
		fwrite(&s,sizeof(s),1,fp);
	}
}
int main()
{
    int i,n,key,ch;
	FILE *fp;
	char file[20];
	cout<<"SEQUENTIAL \n \nEnter filename : ";
	cin>>file;
	cout<<"\nMENU \nPress 1 to Enter Data \nPress 2 to Print data \nPress 3 to Search By prn \nPress 4 to Change File \nPress 5 to exit";
	while(ch!=5)
	{
		cout<<"\n\nEnter your choice : ";	
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"Enter the number of records : ";
	            cin>>n;
	            fp=fopen(file,"w");
	            read(fp,n);
	            fclose(fp);
				break;
			case 2:
				fp = fopen(file,"r");
				cout<<"\nDISPLAY RECORDS \n\n";
				display(fp);
				fclose(fp);
				break;
			case 3:
				fp = fopen(file,"r");
				cout<<"Enter the PRN to search : ";
				cin>>key;
				if(search(fp,key))
				{
					cout<<"\nRECORD FOUND\n\n";
					cout<<"PRN : "<<s.prn<<"\nNAME : "<<s.name<<"\nMarks 1 : "<<s.m1<<"\nMarks 2 : "<<s.m2<<"\nMarks 3 : "<<s.m3;
		            cout<<"\n";
				}
				else
				{
					cout<<"Record Not found";
			    }
			    fclose(fp);
			    break;
		    case 4:
		    	cout<<"\nEnter New File Name : ";
		    	cin>>file;
		    	break;
			case 5:break;
			default:
				cout<<"Invalid choice";
				break;
		}
			
	}
	fclose(fp);
	return 0;
}
