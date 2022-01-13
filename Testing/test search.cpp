// Headers files
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>	//to use system pause and clear
#include<windows.h>	//to use coordinates, sleep

int gotoxy(int, int);
int FileToReadAndWrite(char);
int TitleAndWelcomeTo(char);


int	Step1Customer();
int SleepAndClear4000();
int SearchCustomerDetails();


FILE *fptr;
char c, FileName[100]; 

//for title
char words_for_welcomeTo[50];	

int dataFound=0, recordNo=0;
char name_to_search[20];

//graphics part
COORD coord={0,0};

//defining sturctures
struct Customer		//customer data
{
	char cus_first_name[30], cus_last_name[30], cus_address[100], cus_email[50];
	long unsigned  cus_phone_no;
}cus;



int main()
{
	system("cls");
	//Step1Customer();
	SearchCustomerDetails();
getch();
return 0;
}


int SleepAndClear4000()
{
	Sleep(4000);
	system("cls"); 
	return 0;
}


//coordinates function
int gotoxy(int x , int y)
{
	coord.X=x,coord.Y=y; //x and y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	
return 0;
}

//Title and Welcome to part
int TitleAndWelcomeTo(char words_for_welcomeTo[])
{
	
	printf("\n\n\t\t\t\t\t\t  ------------------------------------------------\n");
	printf("\t\t\t\t\t\t  %s",words_for_welcomeTo);
	printf("\n\t\t\t\t\t\t  ------------------------------------------------\n");	

return 0;
}

//file function to display file if exists, else create new
int FileToReadAndWrite(char FileName[])
{
	fptr=fopen(FileName,"r+");
	if(fptr==NULL)
	{
		fptr=fopen(FileName,"w+");
		if(fptr==NULL)
		{
			printf("File cannnot be created!!!\n");
			exit(1);
		}
	}
return 0;	
}

// step to record customer details
int	Step1Customer()
{
	char words_for_welcomeTo[50]="\t\tStep 1: Customer Details";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS Lite\\Customer Details test.txt";
	FileToReadAndWrite(FileName);
	
	gotoxy(50,12);
	printf("Please provide the required details:");
	gotoxy(50,13);	
	printf("First Name:");
	gotoxy(63,13);
	scanf("%s",cus.cus_first_name);
	gotoxy(50,14);
	printf("Last Name: ");
	gotoxy(63,14);
	scanf("%s",cus.cus_last_name);
	gotoxy(50,15);
	printf("Address:");
	gotoxy(63,15);
	scanf("%s",cus.cus_address);
	gotoxy(50,16);
	printf("Email:");
	gotoxy(63,16);
	scanf("%s",cus.cus_email);
	gotoxy(50,17);
	printf("Phone No:");
	gotoxy(64,17);
	printf("98");
	gotoxy(66,17);	
	scanf("%08lu",&cus.cus_phone_no);
	
	
			fseek(fptr,0,SEEK_END); //to the end of file and then add new data from there
			fwrite(&cus,sizeof(cus),1,fptr);				
 	 
 	gotoxy(50,19);
	printf("Customer Details have been submitted successfully.");
	
	SleepAndClear4000();		
return 0;	
}

int SearchCustomerDetails()
{
	dataFound=0;
	char words_for_welcomeTo[50]="\t\t Search Customer Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS Lite\\Customer Details test.txt";
	FileToReadAndWrite(FileName);
	
	gotoxy(50,12);
	printf("Enter the full name of customer which is to be searched: ");
	gets(name_to_search);
	fseek(fptr,0,SEEK_SET);
	while(fread(&cus,sizeof(cus),1,fptr)==1)
	{	
		if(strcmp(cus.cus_first_name,name_to_search)==0)
		{
			dataFound=1;
			printf("\n-----------------------------------------------------------------------------------\n");
			printf(" First Name : %s \n Last Name  : %s \n Address    : %s \n Email      : %s \n Phone No   : 98%08lu",cus.cus_first_name, cus.cus_last_name, cus.cus_address, cus.cus_email,cus.cus_phone_no);
			return 0;
		}
	}
	if(dataFound==0)
	{
	gotoxy(50,14);
	printf("    No Data Found. Try Again!!!");
	}
return 0;
}

