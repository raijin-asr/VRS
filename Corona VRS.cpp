/*         		VEHICLE RENTAL SYSTEM(VRS)  
  
   Team Members: Ameer Sampang Rai, Badri Tamang, Sandip Shreastha
   First Semester Project based on C programming
   College: Aryan School of Engineering and Management
   Faculty: BIT 2019

*/

//Headers files
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>	//to use system pause and clear
#include<windows.h>	//to use coordinates, sleep

//prototypes
int gotoxy(int, int);
int DisplayFile(char);
int FileToReadAndWrite(char);
int Welcome();
int Login();
int ReLoginOrExit();
int LogOut();
int TitleAndWelcomeTo(char);
int MainMenus();

//Two Wheeler prototypes
int TwoWheeler();
	int Bike();
			int HondaEngineList();
				int	Honda150ccList();
					int Honda150ccNo1501();
					int Honda150ccNo1502();
					int Honda150ccNo1503();
				int	Honda250ccList();
					int Honda250ccNo2501();
					int	Honda250ccNo2502();
					int	Honda250ccNo2503();
				int	Honda300ccList();
					int	Honda300ccNo3001();
					int	Honda300ccNo3002();
					int	Honda300ccNo3003();
			int PulsarEngineList();
				int Pulsar180ccList();
					int Pulsar180ccNo1801();
					int Pulsar180ccNo1802();
				int Pulsar220ccList();
					int Pulsar220ccNo2201();
					int Pulsar220ccNo2202();
			int YamahaEngineList();
				int Yamaha150ccList();
					int Yamaha150ccNo151();
					int Yamaha150ccNo152();
				int Yamaha300ccList();
					int Yamaha300ccNo301();
					int Yamaha300ccNo302();

	int Scooty();
		int HondaScooty();
			int Dio();
				int DioNo1101();
				int DioNo1102();
		int HeroScooty();
			int Pleasure();
				int PleasureNo1103();
				int PleasureNo1104();
		int SuzukiScooty();
			int SuzukiAccess();
				int AccessNo1251();
				int AccessNo1252();
			int SuzukiLets();
				int LetsNo1131();
				int LetsNo1132();
		
//Four Wheeler prototypes
int FourWheeler();
	int Car();
		int TataCar();
			int TataIndicaEv2();
				int IndicaEv2No1401();
				int IndicaEv2No1402();
			int TataIndicaVista();
				int IndicaVistaNo1255();
				int IndicaVistaNo1256();
		int ToyotaCar();
				int ToyotaHilux();
					int HiluxNo2447();
					int HiluxNo2448();
				int ToyotaLandCruiser();
					int LandCruiserNo3432();
					int LandCruiserNo3433();
	int Bus();
		int AshokBus();
			int AshokLeyland();
				int LeylandNo3840();
				int LeylandNo3841();
		int TataBus();
			int TataDeluxeVolvo();
				int DeluxeVolvoNo3201();
				int DeluxeVolvoNo3202();
			int TataMiniBus();
				int MiniBusNo2601();
				int MiniBusNo2602();

//Main menus more options
int MoreOptions();
		int ListCustomerDetails();
		int SearchCustomerDetails();
			int WritingCustomerDataForSearch();
		int ListBookingDetails();
		int SearchBookingDetails();
			int WritingBookingDataForSearch();


//Price and rent
int	Step1Customer();
	int CustomerMenu();
		int ModifyCustomerDetails();
		int DeleteCustomerDetails();
int	Step2Book();
	int DPBD();
	int WPBD();
	int BookingMenu();
		int ModifyBookingDetails();
		int DeleteBookingDetails();
int	Step3Calculate();
int	Step4Invoice();		


//Others
int Support();
int Help();
	int HowToUse();
	int About();
int ThankYou();
int SleepAndClear();
int SleepAndClear4000();
int Exit();

//global variables declaration-------------------------------------------------------------------------
//for file
FILE *fptr;
char c, FileName[100]; 	

int VehicleNo; //like primary key
int i;

int dataFound=0, recordNo=0;
char name_to_search[20];

//Login
char pass[10];
char un[10];
char username[10]="admin";
char password[10]="admin";

//for automatic getting vehicle type(e.g. Bike, Scooty, Car)
char VehicleTypeValue[6];
char VehicleType[10];

//for automatic getting vehicle brand(e.g. honda, pulsar)
char VehicleBrandValue[6];
char VehicleBrand[10];

//sturctures
struct Customer		//customer data
{
	char cus_first_name[30], cus_last_name[30], cus_address[100], cus_email[50];
	long unsigned  cus_phone_no;
}cus;

struct RentDetail
{
	char pick_up_location[50], return_location[50];
	struct PickUpDate
		{
			int day, month, year;
		}pdate;
	struct ReturnDate
		{
			int day, month, year;
		}rdate;
	int rental_duration, advance;
}rd;

int day_max, month_max, newYear, newMonth, newMonth2, newDay;
int Rental_Price, Total_Rental_Price;

//words for welcome section
char words_for_welcomeTo[50];	

//graphics part
COORD coord={0,0};

/////int main starts-----------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
int main()
{
//VRS GUI start------>>>>>>>
	system("cls");
	Welcome();	
	
fclose(fptr);		
getch();
return 0;
} //end of int main

//Functions start________________________________________________________________________________________________________________

//coordinates part
int gotoxy(int x , int y)
{
	coord.X=x,coord.Y=y; //x and y coordinates
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);	
return 0;
}

//file function to display file
int DisplayFile(char FileName[])
{
	char c;
	fptr=fopen(FileName,"r+");
	if(fptr==NULL)
	{
		printf("File cannot be opened.");
		exit(1);
	}
	while((c=fgetc(fptr))!=EOF)
	{	
		putchar(c);
	}
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


int Welcome()
{
	char FileName[]="E:\\VRS\\Welcome VRS.txt";
	DisplayFile(FileName);
	
	printf("\n\n\n\n\t\tStarting 'VRS'. Please wait");
	for(i=0;i<3;i++)
	{
		printf(".");
		Sleep(1000);	//function which waits for (n) seconds
	}
	
	printf("\n\n\t\tLoading files");
	for(i=0;i<3;i++)
	{
		printf(".");
		Sleep(1000);
	}
	
	gotoxy(65,14);
	printf("LIST OF OPTIONS:");
	gotoxy(65,15);
	printf("----------------");
	gotoxy(65,16);
	printf("1. LOGIN");
	gotoxy(65,17);
	printf("2. SUPPORT");
	gotoxy(65,18);
	printf("3. HELP");
	gotoxy(65,19);
	printf("4. EXIT");
	
	gotoxy(65,21);
	printf("Type your Choice==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			Login();
			break;	
			
			case '2':
			SleepAndClear();
			Support();
			break;
			
			case '3':
			SleepAndClear();
			Help();
			break;
			
			case '4':
			SleepAndClear();
			Exit();
			break;
			
			default:
					printf("\n\n\t\t\t\t\t\t  Invalid Choice!!! Please again Type given options!!! ");
					SleepAndClear4000();
					Welcome();	
		} //end of switch
	
fclose(fptr);
getch();
return 0;
}

//Title and Welcome to part----------------------------------------------------------------------------
int TitleAndWelcomeTo(char words_for_welcomeTo[])
{
	char FileName[]="E:\\VRS\\Welcome VRS.txt";
	DisplayFile(FileName);
	
	printf("\n\n\t\t\t\t\t\t  ------------------------------------------------\n");
	printf("\t\t\t\t\t\t  %s",words_for_welcomeTo);
	printf("\n\t\t\t\t\t\t  ------------------------------------------------\n");	

return 0;
}

//System Pause and Clear Screen


int SleepAndClear()
{
	Sleep(500);
	system("cls"); 
	return 0;
}


int SleepAndClear4000()
{
	Sleep(4000);
	system("cls"); 
	return 0;
}

//Login---------------------------------------------
int Login()
{
	char words_for_welcomeTo[50]="\t\t\tLOGIN";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
			char c,un[10],pass[10];
			i=0;
			
			gotoxy(50,13);
			printf("Enter your username:");
			scanf("%s",un);
			
			gotoxy(50,14);
			printf("Enter Password: ");
			while(c!=13)  //13 is Enter key
			{
			c=getch();
				if(c!='\r' && c!='\b')
				{
				printf("*");
				pass[i]=c;
				i++;
				}	
			}
			
			pass[i]='\0';
			
			//authentication
			if((strcmp(un,username) && strcmp(pass,password))==0)
			{
			gotoxy(50,16);
			printf("Login Successful!!!");
			Sleep(3000);
			system("cls");
			MainMenus();
			}
			
			else
			{
			gotoxy(50,16);
			printf("\a Username and Password don't match!!! Try again.");
			SleepAndClear4000();
			ReLoginOrExit();
			}
return 0;	
}

int ReLoginOrExit()
{
		printf("\n\nDo you want to Re-Login or Exit? [Type 'R/r' for Re-Login and 'E/e' for Exit]: ");
			
		switch(getche())
		{
			case 'R': 
			printf("\n\nRe-Logging...\n\n");
			Sleep(4000);
			system("cls");
			Login();
			break;
				
			case 'r': 
			printf("\n\nRe-Logging...\n\n");
			Sleep(4000);
			system("cls");
			Login();
			break;
			
			case 'E': 
			SleepAndClear();
			exit(1);
			break;
			
			case 'e': 
			SleepAndClear();
			exit(1);
			break;
			
			default:
					printf("\n\nInvalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					ReLoginOrExit();
		} //end of switch
getch();	
return 0;	
}


int LogOut()
{
	char words_for_welcomeTo[50]="\t\tLog Out Section";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
		printf("\n\nDo you want to Log Out? [Type 'Y' for Yes and 'N' for No]: ");
			
		switch(getche())
		{
			case 'Y': 
			printf("\n\nSuccessfully Logged Out!!!\n\n");
			Sleep(4000);
			system("cls");
			Welcome();
			break;
				
			case 'y': 
			printf("\n\nSuccessfully Logged Out!!!\n\n");
			Sleep(4000);
			system("cls");
			Welcome();
			break;
			
			case 'N': 
			SleepAndClear();
			MainMenus();
			break;
			
			case 'n': 
			SleepAndClear();
			MainMenus();
			break;
			
			default:
					printf("\n\nInvalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					LogOut();
		} //end of switch
return 0;
}

//Main menu start----------------------------------------------------------------------------------------
int MainMenus()
{
//Main menu content
	char words_for_welcomeTo[50]="\tWelcome to Vehicle Rental System(VRS)";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Two Wheeler");
	gotoxy(50,15);
	printf("2. Four Wheeler");
	gotoxy(50,16);
	printf("3. More Options");
	gotoxy(50,17);
	printf("4. Log Out");
	
	//choice using switch case
	gotoxy(50,19);
	printf("Type your choice==>");

	switch(getche())
		{
			case '1': 
			SleepAndClear();
			TwoWheeler();
			break;
			
			case '2': 
			SleepAndClear();
			FourWheeler();
			break;	
		
			case '3': 
			SleepAndClear();
			MoreOptions();
			break;
			
			case '4': 
			SleepAndClear();
			LogOut();
			break;
			
			default:
					gotoxy(50,21);
					printf("Invalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					MainMenus();
		} //end of switch
return 0;	
}

//Two Wheeler++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int TwoWheeler()   //TW stands for Two Wheeler
{
	char words_for_welcomeTo[50]="\t\tWelcome to Two Wheeler Section";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Two Wheeler.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Bike");
	gotoxy(50,15);
	printf("2. Scooty");
	gotoxy(50,16);
	printf("3. Back to Main Menu");
	gotoxy(50,18);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Bike();
			break;
			
			case '2':
			SleepAndClear();
			Scooty();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
			gotoxy(50,21);
			printf("Invalid Choice!!! Please again Type given options!!!");
			SleepAndClear4000();
			TwoWheeler();		
		}

fclose(fptr);
getch();
return 0;			
}

//Bike Details--------------------------------------
int Bike()
{
	char VehicleType[]="Bike";
	char words_for_welcomeTo[50]="\t\t\tBike";
	TitleAndWelcomeTo(words_for_welcomeTo);	
		
	char FileName[]="E:\\VRS\\Bike\\2Bike.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);	
	printf("1. Honda");
	gotoxy(50,15);
	printf("2. Pulsar");
	gotoxy(50,16);
	printf("3. Yamaha");
	gotoxy(50,17);
	printf("4. Back to Two Wheeler  Menu");
	
	gotoxy(50,19);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			HondaEngineList();
			break;
			
			case '2':
			SleepAndClear();
			PulsarEngineList();
			break;
			
			case '3':
			SleepAndClear();
			YamahaEngineList();
			break;
			
			case '4':
			SleepAndClear();
			TwoWheeler();
			break;
			
			default:
			gotoxy(50,21);
			printf("Invalid Choice!!! Please again Type given options!!!");
			SleepAndClear4000();
			Bike();		
		}
		
fclose(fptr);
getch();
return 0;
}

//Honda starts============================================================================
int HondaEngineList()
{
	char words_for_welcomeTo[50]="\t\tList of Honda Enginee(CC)";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Bike\\2Bike.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. 150 CC Engine");
	gotoxy(50,15);
	printf("2. 250 CC Engine");
	gotoxy(50,16);
	printf("3. 300 CC Engine");
	gotoxy(50,17);
	printf("4. Back to Previous Menu");
	gotoxy(50,19);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			Honda150ccList();
			break;	
			
			case '2':
			SleepAndClear();
			Honda250ccList();
			break;
			
			case '3':
			SleepAndClear();
			Honda300ccList();
			break;
			
			case '4':
			SleepAndClear();
			Bike();
			break;
			
			default:
				gotoxy(50,21);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				HondaEngineList();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

//Honda 150 CC starts-------------------------------------------------------------------------
int Honda150ccList()
{
	char words_for_welcomeTo[50]="\t\tList of Honda 150 CC";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 150\\Honda 150 CC List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=1501;
				SleepAndClear();
				Honda150ccNo1501();
			break;	
			
			case '2':
				VehicleNo=1502;
				SleepAndClear();
				Honda150ccNo1502();	
			break;
		
			case '3':
				VehicleNo=1503;
				SleepAndClear();
				Honda150ccNo1503();
			break;	
			
			case '4':
				SleepAndClear();
				HondaEngineList();
			break;
				
			default:	
				gotoxy(24,35);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Honda150ccList();
		}			
		
fclose(fptr);
getch();
return 0;
}

int Honda150ccNo1501()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 150 cc: Bike No 1501";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 150\\Honda 150 CC No 1501.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda150ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda150ccNo1501();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int Honda150ccNo1502()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 150 cc: Bike No 1502";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 150\\Honda 150 CC No 1502.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda150ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda150ccNo1502();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int Honda150ccNo1503()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 150 cc: Bike No 1503";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 150\\Honda 150 CC No 1503.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda150ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda150ccNo1503();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

//Honda 250 CC starts------------------------------------------------------------------
int Honda250ccList()
{
	char  words_for_welcomeTo[50]="\t\tList of Honda 250 CC";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 250\\Honda 250 CC List.txt";
	DisplayFile(FileName);
	
	switch(getche())
		{
			case '1':
				VehicleNo=2501;
				SleepAndClear();
				Honda250ccNo2501();
			break;	
			
			case '2':
				VehicleNo=2502;
				SleepAndClear();
				Honda250ccNo2502();	
			break;
		
			case '3':
				VehicleNo=2503;
				SleepAndClear();
				Honda250ccNo2503();
			break;	
			
			case '4':
				SleepAndClear();
				HondaEngineList();
			break;
				
			default:	
				gotoxy(24,35);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Honda250ccList();
		}
		
fclose(fptr);
getch();	
return 0;
}

int	Honda250ccNo2501()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 250 cc: Bike No 2501";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 250\\Honda 250 CC No 2501.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda250ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda250ccNo2501();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;	
}

int	Honda250ccNo2502()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 250 cc: Bike No 2502";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 250\\Honda 250 CC No 2502.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda250ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda250ccNo2502();
		} //end of switch	
	
fclose(fptr);
getch();
return 0;	
}

int	Honda250ccNo2503()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 250 cc: Bike No 2503";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 250\\Honda 250 CC No 2503.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda250ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda250ccNo2503();
		} //end of switch	
	
fclose(fptr);
getch();
return 0;	
}

//Honda 300 CC starts--------------------------------------------------------------------
int Honda300ccList()
{
	char  words_for_welcomeTo[50]="\t\tList of Honda 300 CC";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 300\\Honda 300 CC List.txt";
	DisplayFile(FileName);
	
	switch(getche())
		{
			case '1':
				VehicleNo=3001;
				SleepAndClear();
				Honda300ccNo3001();
			break;	
			
			case '2':
				VehicleNo=3002;
				SleepAndClear();
				Honda300ccNo3002();	
			break;
		
			case '3':
				VehicleNo=3003;
				SleepAndClear();
				Honda300ccNo3003();
			break;	
			
			case '4':
				SleepAndClear();
				HondaEngineList();
			break;
				
			default:	
				gotoxy(24,35);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Honda300ccList();
		}
		
fclose(fptr);
getch();	
return 0;
}

int	Honda300ccNo3001()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 300 cc: Bike No 3001";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 300\\Honda 300 CC No 3001.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda300ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(24,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda300ccNo3001();
		} //end of switch	
	
fclose(fptr);
getch();
return 0;		
}

int	Honda300ccNo3002()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 300 cc: Bike No 3002";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 300\\Honda 300 CC No 3002.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda300ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(24,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda300ccNo3002();
		} //end of switch	
	
fclose(fptr);
getch();
return 0;		
}

int	Honda300ccNo3003()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda 300 cc: Bike No 3003";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Honda\\Bike 300\\Honda 300 CC No 3003.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Honda300ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(24,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Honda300ccNo3003();
		} //end of switch	
	
fclose(fptr);
getch();
return 0;		
}

//Pulsar starts=========================================================================
int PulsarEngineList()
{
	char words_for_welcomeTo[50]="\t\tList of Pulsar Enginee(CC)";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Bike\\2Bike.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. 180 CC Engine");
	gotoxy(50,15);
	printf("2. 220 CC Engine");
	gotoxy(50,16);
	printf("3. Back to Previous Menu");
	gotoxy(50,18);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			Pulsar180ccList();
			break;	
			
			case '2':
			SleepAndClear();
			Pulsar220ccList();
			break;
			
			case '3':
			SleepAndClear();
			Bike();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				PulsarEngineList();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

// Pulsar 180 cc starts---------------------------------------------------
int Pulsar180ccList()
{
	char words_for_welcomeTo[50]="\t\tList of Pulsar 180 CC";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Bike\\Pulsar\\Bike 180\\Pulsar 180 CC List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=1801;
				SleepAndClear();
				Pulsar180ccNo1801();
			break;	
			
			case '2':
				VehicleNo=1802;
				SleepAndClear();
				Pulsar180ccNo1802();	
			break;
		
			case '3':
				SleepAndClear();
				PulsarEngineList();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Pulsar180ccList();
		}			
		
fclose(fptr);
getch();
return 0;
}

int Pulsar180ccNo1801()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Pulsar";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tPulsar 180 cc: Bike No 1801";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Pulsar\\Bike 180\\Pulsar 180 CC No 1801.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Pulsar180ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Pulsar180ccNo1801();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int Pulsar180ccNo1802()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Pulsar";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tPulsar 180 cc: Bike No 1802";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Pulsar\\Bike 180\\Pulsar 180 CC No 1802.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Pulsar180ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Pulsar180ccNo1802();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

// Pulsar 220 cc starts---------------------------------------------------
int Pulsar220ccList()
{
	char words_for_welcomeTo[50]="\t\tList of Pulsar 220 CC";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Bike\\Pulsar\\Bike 220\\Pulsar 220 CC List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=2201;
				SleepAndClear();
				Pulsar220ccNo2201();
			break;	
			
			case '2':
				VehicleNo=2202;
				SleepAndClear();
				Pulsar220ccNo2202();	
			break;
		
			case '3':
				SleepAndClear();
				PulsarEngineList();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Pulsar220ccList();
		}			
		
fclose(fptr);
getch();
return 0;
}

int Pulsar220ccNo2201()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Pulsar";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tPulsar 220 cc: Bike No 2201";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Pulsar\\Bike 220\\Pulsar 220 CC No 2201.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Pulsar220ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Pulsar220ccNo2201();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int Pulsar220ccNo2202()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Pulsar";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tPulsar 220 cc: Bike No 2202";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Pulsar\\Bike 220\\Pulsar 220 CC No 2202.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Pulsar220ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Pulsar220ccNo2202();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

// Yamaha Starts===========================================================================
int YamahaEngineList()
{

	char words_for_welcomeTo[50]="\t\tList of Yamaha Enginee(CC)";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Bike\\2Bike.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. 150 CC Engine");
	gotoxy(50,15);
	printf("2. 300 CC Engine");
	gotoxy(50,16);
	printf("3. Back to Previous Menu");
	gotoxy(50,18);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			Yamaha150ccList();
			break;	
		
			case '2':
			SleepAndClear();
			Yamaha300ccList();
			break;
			
			case '3':
			SleepAndClear();
			Bike();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				YamahaEngineList();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

// Yamaha 150 cc starts---------------------------------------------------
int Yamaha150ccList()
{
	char words_for_welcomeTo[50]="\t\tList of Yamaha R15: 150 CC";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Bike\\Yamaha\\Bike R15\\Yamaha 150 CC List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=151;
				SleepAndClear();
				Yamaha150ccNo151();
			break;	
			
			case '2':
				VehicleNo=152;
				SleepAndClear();
				Yamaha150ccNo152();	
			break;
		
			case '3':
				SleepAndClear();
				YamahaEngineList();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Yamaha150ccList();
		}			
		
fclose(fptr);
getch();
return 0;
}

int Yamaha150ccNo151()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Yamaha";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tYamaha R15 150 cc: Bike No 151";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Yamaha\\Bike R15\\Yamaha 150 CC No 151.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Yamaha150ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Yamaha150ccNo151();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int Yamaha150ccNo152()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Yamaha";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tYamaha R15 150 cc: Bike No 152";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Yamaha\\Bike R15\\Yamaha 150 CC No 152.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Yamaha150ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Yamaha150ccNo152();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

// Yamaha 300 cc starts---------------------------------------------------
int Yamaha300ccList()
{
	char words_for_welcomeTo[50]="\t\tList of Yamaha R3: 300 CC";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Bike\\Yamaha\\Bike R3\\Yamaha 300 CC List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=301;
				SleepAndClear();
				Yamaha300ccNo301();
			break;	
			
			case '2':
				VehicleNo=302;
				SleepAndClear();
				Yamaha300ccNo302();	
			break;
		
			case '3':
				SleepAndClear();
				YamahaEngineList();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Yamaha300ccList();
		}			
		
fclose(fptr);
getch();
return 0;
}

int Yamaha300ccNo301()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Yamaha";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tYamaha R3 300 cc: Bike No 301";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Yamaha\\Bike R3\\Yamaha 300 CC No 301.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Yamaha300ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Yamaha300ccNo301();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int Yamaha300ccNo302()
{
	char VehicleType[]="Bike";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Yamaha";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tYamaha R3 300 cc: Bike No 302";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bike\\Yamaha\\Bike R3\\Yamaha 300 CC No 302.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,28);
	printf("1. Proceed to Rent Now");
	gotoxy(50,29);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,30);
	printf("3. Go Back to Main Menu");
	gotoxy(50,32);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Yamaha300ccList();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				Yamaha300ccNo302();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

//Scooty Details==========================================================================
int Scooty()
{
	char VehicleType[]="Scooty";
	char words_for_welcomeTo[50]="\t\t\tScooty";
	TitleAndWelcomeTo(words_for_welcomeTo);	
		
	char FileName[]="E:\\VRS\\Scooty\\2Scooty.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);	
	printf("1. Honda");
	gotoxy(50,15);	
	printf("2. Hero");
	gotoxy(50,16);
	printf("3. Suzuki");
	gotoxy(50,17);
	printf("4. Back to Two Wheeler  Menu");
	
	gotoxy(50,19);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			HondaScooty();
			break;
			
			case '2':
			SleepAndClear();
			HeroScooty();
			break;
			
			case '3':
			SleepAndClear();
			SuzukiScooty();
			break;
			
			case '4':
			SleepAndClear();
			TwoWheeler();
			break;
			
			default:
			gotoxy(50,21);
			printf("Invalid Choice!!! Please again Type given options!!!");
			SleepAndClear4000();
			Scooty();		
		}
		
fclose(fptr);
getch();
return 0;
}

//Honda Scooty starts--------------------------------------------------------------
int HondaScooty()
{
	char words_for_welcomeTo[50]="\t\tList of Honda Scooty";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Scooty\\2Scooty.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Dio");
	gotoxy(50,15);
	printf("2. Back to Previous Menu");
	gotoxy(50,17);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			Dio();
			break;	
			
			case '2':
			SleepAndClear();
			Scooty();
			break;
			
			default:
				gotoxy(50,19);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				HondaScooty();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

int Dio()
{
	char words_for_welcomeTo[50]="\t\tList of Honda Dio Scooty";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Scooty\\Honda\\Dio\\Honda Dio List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=1101;
				SleepAndClear();
				DioNo1101();
			break;	
			
			case '2':
				VehicleNo=1102;
				SleepAndClear();
				DioNo1102();	
			break;
		
			case '3':
				SleepAndClear();
				HondaScooty();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Dio();
		}			
		
fclose(fptr);
getch();
return 0;
}

int DioNo1101()
{
	char VehicleType[]="Scooty";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda Dio: Scooty No 1101";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Scooty\\Honda\\Dio\\Honda Dio No 1101.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,33);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Dio();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				DioNo1101();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int DioNo1102()
{
	char VehicleType[]="Scooty";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Honda";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHonda Dio: Scooty No 1102";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Scooty\\Honda\\Dio\\Honda Dio No 1102.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,33);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Dio();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				DioNo1102();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

//Hero Scooty starts--------------------------------------------------------------
int HeroScooty()
{
	char words_for_welcomeTo[50]="\t\tList of Hero Scooty";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Scooty\\2Scooty.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Pleasure");
	gotoxy(50,15);
	printf("2. Back to Previous Menu");
	gotoxy(50,17);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			Pleasure();
			break;	
			
			case '2':
			SleepAndClear();
			Scooty();
			break;
			
			default:
				gotoxy(50,19);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				HeroScooty();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

int Pleasure()
{
	char words_for_welcomeTo[50]="\t\tList of Hero Pleasure Scooty";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Scooty\\Hero\\Pleasure\\Hero Pleasure List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=1103;
				SleepAndClear();
				PleasureNo1103();
			break;	
			
			case '2':
				VehicleNo=1104;
				SleepAndClear();
				PleasureNo1104();	
			break;
		
			case '3':
				SleepAndClear();
				HeroScooty();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				Pleasure();
		}			
		
fclose(fptr);
getch();
return 0;
}

int PleasureNo1103()
{
	char VehicleType[]="Scooty";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Hero";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHero Pleasure: Scooty No 1103";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Scooty\\Hero\\Pleasure\\Hero Pleasure No 1103.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,33);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Pleasure();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				PleasureNo1103();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int PleasureNo1104()
{
	char VehicleType[]="Scooty";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Hero";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tHero Pleasure: Scooty No 1104";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Scooty\\Hero\\Pleasure\\Hero Pleasure No 1104.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,33);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			Pleasure();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				PleasureNo1104();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

//Suzuki Scooty starts--------------------------------------------------------------
int SuzukiScooty()
{
	char words_for_welcomeTo[50]="\t\tList of Suzuki Scooty";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Scooty\\2Scooty.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Access");
	gotoxy(50,15);
	printf("2. Lets");
	gotoxy(50,16);
	printf("3. Back to Previous Menu");
	gotoxy(50,18);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			SuzukiAccess();
			break;	
			
			case '2':
			SleepAndClear();
			SuzukiLets();
			break;
			
			case '3':
			SleepAndClear();
			Scooty();
			break;
			
			default:
				gotoxy(50,20);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				SuzukiScooty();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

int SuzukiAccess()
{
	char words_for_welcomeTo[50]="\t\tList of Suzuki Access Scooty";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Scooty\\Suzuki\\Access\\Suzuki Access List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=1251;
				SleepAndClear();
				AccessNo1251();
			break;	
			
			case '2':
				VehicleNo=1252;
				SleepAndClear();
				AccessNo1252();	
			break;
		
			case '3':
				SleepAndClear();
				SuzukiScooty();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				SuzukiAccess();
		}			
		
fclose(fptr);
getch();
return 0;
}

int AccessNo1251()
{
	char VehicleType[]="Scooty";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Suzuki";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tSuzuki Access: Scooty No 1251";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Scooty\\Suzuki\\Access\\Suzuki Access No 1251.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,33);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			SuzukiAccess();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				AccessNo1251();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int AccessNo1252()
{
	char VehicleType[]="Scooty";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Suzuki";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tSuzuki Access: Scooty No 1252";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Scooty\\Suzuki\\Access\\Suzuki Access No 1252.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,33);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			SuzukiAccess();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				AccessNo1252();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int SuzukiLets()
{
	char words_for_welcomeTo[50]="\t\tList of Suzuki Lets Scooty";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Scooty\\Suzuki\\Lets\\Suzuki Lets List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=1131;
				SleepAndClear();
				LetsNo1131();
			break;	
			
			case '2':
				VehicleNo=1132;
				SleepAndClear();
				LetsNo1132();	
			break;
		
			case '3':
				SleepAndClear();
				SuzukiScooty();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				SuzukiLets();
		}			
		
fclose(fptr);
getch();
return 0;
}

int LetsNo1131()
{
	char VehicleType[]="Scooty";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Suzuki";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tSuzuki Lets: Scooty No 1131";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Scooty\\Suzuki\\Lets\\Suzuki Lets No 1131.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,33);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			SuzukiLets();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				LetsNo1131();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int LetsNo1132()
{
	char VehicleType[]="Scooty";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Suzuki";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tSuzuki Lets: Scooty No 1132";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Scooty\\Suzuki\\Lets\\Suzuki Lets No 1132.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,33);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			SuzukiLets();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				LetsNo1132();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

//Four Wheeler++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int FourWheeler()   //FW stands for Four Wheeler
{
	char words_for_welcomeTo[50]="\t\tWelcome to Four Wheeler Section";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Four Wheeler.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Car");
	gotoxy(50,15);
	printf("2. Bus");
	gotoxy(50,16);
	printf("3. Back to Main Menu");
	gotoxy(50,18);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Car();
			break;
			
			case '2':
			SleepAndClear();
			Bus();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
			gotoxy(50,21);
			printf("Invalid Choice!!! Please again Type given options!!!");
			SleepAndClear4000();
			FourWheeler();		
		}

fclose(fptr);
getch();
return 0;			
}

// Car starts=============================================================================
int Car()
{
	char VehicleType[]="Car";
	char words_for_welcomeTo[50]="\t\t\tCar";
	TitleAndWelcomeTo(words_for_welcomeTo);	
		
	char FileName[]="E:\\VRS\\Car\\2Car.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);	
	printf("1. Tata");
	gotoxy(50,15);
	printf("2. Toyato");
	gotoxy(50,16);
	printf("3. Back to Four Wheeler  Menu");
	
	gotoxy(50,18);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			TataCar();
			break;
			
			case '2':
			SleepAndClear();
			ToyotaCar();
			break;
			
			case '3':
			SleepAndClear();
			FourWheeler();
			break;
			
			default:
			gotoxy(50,21);
			printf("Invalid Choice!!! Please again Type given options!!!");
			SleepAndClear4000();
			Car();		
		}
		
fclose(fptr);
getch();
return 0;
}

//Tata Car starts--------------------------------------------------------------
int TataCar()
{
	char words_for_welcomeTo[50]="\t\tList of Tata Car";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Car\\2Car.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Indica Ev2");
	gotoxy(50,15);
	printf("2. Indica Vista");
	gotoxy(50,16);
	printf("3. Back to Previous Menu");
	gotoxy(50,18);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			TataIndicaEv2();
			break;	
			
			case '2':
			SleepAndClear();
			TataIndicaVista();
			break;
			
			case '3':
			SleepAndClear();
			Car();
			break;
			
			default:
				gotoxy(50,19);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				TataCar();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

int TataIndicaEv2()
{
	char words_for_welcomeTo[50]="\t\tList of Tata Indica Ev2 Car";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Car\\Tata\\Indica Ev2\\Tata Indica Ev2 List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=1401;
				SleepAndClear();
				IndicaEv2No1401();
			break;	
			
			case '2':
				VehicleNo=1102;
				SleepAndClear();
				IndicaEv2No1402();	
			break;
		
			case '3':
				SleepAndClear();
				TataCar();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				TataIndicaEv2();
		}			
		
fclose(fptr);
getch();
return 0;
}

int IndicaEv2No1401()
{
	char VehicleType[]="Car";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Tata";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tTata Indica Ev2: Car No 1401";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Car\\Tata\\Indica Ev2\\Tata Indica Ev2 No 1401.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			TataIndicaEv2();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				IndicaEv2No1401();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int IndicaEv2No1402()
{
	char VehicleType[]="Car";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Tata";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tTata Indica Ev2: Car No 1402";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Car\\Tata\\Indica Ev2\\Tata Indica Ev2 No 1402.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			TataIndicaEv2();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				IndicaEv2No1402();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int TataIndicaVista()
{
	char words_for_welcomeTo[50]="\t\tList of Tata Indica Vista Car";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Car\\Tata\\Indica Vista\\Tata Indica Vista List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=1255;
				SleepAndClear();
				IndicaVistaNo1255();
			break;	
			
			case '2':
				VehicleNo=1256;
				SleepAndClear();
				IndicaVistaNo1256();	
			break;
		
			case '3':
				SleepAndClear();
				TataCar();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				TataIndicaVista();
		}			
		
fclose(fptr);
getch();
return 0;
}

int IndicaVistaNo1255()
{
	char VehicleType[]="Car";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Tata";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tTata Indica Vista: Car No 1255";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Car\\Tata\\Indica Vista\\Tata Indica Vista No 1255.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			TataIndicaVista();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				IndicaVistaNo1255();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int IndicaVistaNo1256()
{
	char VehicleType[]="Car";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Tata";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tTata Indica Vista: Car No 1256";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Car\\Tata\\Indica Vista\\Tata Indica Vista No 1256.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			TataIndicaVista();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				IndicaVistaNo1256();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

//Toyota Car starts--------------------------------------------------------------
int ToyotaCar()
{
	char words_for_welcomeTo[50]="\t\tList of Toyota Car";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Car\\2Car.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Hilux");
	gotoxy(50,15);
	printf("2. Land Cruiser");
	gotoxy(50,16);
	printf("3. Back to Previous Menu");
	gotoxy(50,18);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			ToyotaHilux();
			break;	
			
			case '2':
			SleepAndClear();
			ToyotaLandCruiser();
			break;
			
			case '3':
			SleepAndClear();
			Car();
			break;
			
			default:
				gotoxy(50,19);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				ToyotaCar();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

int ToyotaHilux()
{
	char words_for_welcomeTo[50]="\t\tList of Toyota Hilux Car";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Car\\Toyota\\Hilux\\Toyota Hilux List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=2447;
				SleepAndClear();
				HiluxNo2447();
			break;	
			
			case '2':
				VehicleNo=2448;
				SleepAndClear();
				HiluxNo2448();	
			break;
		
			case '3':
				SleepAndClear();
				ToyotaCar();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				ToyotaHilux();
		}			
		
fclose(fptr);
getch();
return 0;
}

int HiluxNo2447()
{
	char VehicleType[]="Car";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Toyota";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tToyota Hilux: Car No 2447";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Car\\Toyota\\Hilux\\Toyota Hilux No 2447.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			ToyotaHilux();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				HiluxNo2447();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int HiluxNo2448()
{
	char VehicleType[]="Car";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Toyota";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tToyota Hilux: Car No 2448";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Car\\Toyota\\Hilux\\Toyota Hilux No 2448.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			ToyotaHilux();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				HiluxNo2448();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int ToyotaLandCruiser()
{
	char words_for_welcomeTo[50]="\t\tList of Toyota Land Cruiser Car";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Car\\Toyota\\Land Cruiser\\Land Cruiser List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=3432;
				SleepAndClear();
				LandCruiserNo3432();
			break;	
			
			case '2':
				VehicleNo=3433;
				SleepAndClear();
				LandCruiserNo3433();	
			break;
		
			case '3':
				SleepAndClear();
				ToyotaCar();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				ToyotaLandCruiser();
		}			
		
fclose(fptr);
getch();
return 0;
}

int LandCruiserNo3432()
{
	char VehicleType[]="Car";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Toyota";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tToyota Land Cruiser: Car No 3432";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Car\\Toyota\\Land Cruiser\\Land Cruiser No 3432.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			ToyotaLandCruiser();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				LandCruiserNo3432();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int LandCruiserNo3433()
{
	char VehicleType[]="Car";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Toyota";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tToyota Land Cruiser: Car No 3433";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Car\\Toyota\\Land Cruiser\\Land Cruiser No 3433.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			ToyotaLandCruiser();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				LandCruiserNo3433();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

// Bus starts=============================================================================
int Bus()
{
	char VehicleType[]="Bus";
	char words_for_welcomeTo[50]="\t\t\tBus";
	TitleAndWelcomeTo(words_for_welcomeTo);	
		
	char FileName[]="E:\\VRS\\Bus\\2Bus.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);	
	printf("1. Ashok");
	gotoxy(50,15);
	printf("2. Tata");
	gotoxy(50,16);
	printf("3. Back to Four Wheeler  Menu");
	
	gotoxy(50,18);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			AshokBus();
			break;
			
			case '2':
			SleepAndClear();
			TataBus();
			break;
			
			case '3':
			SleepAndClear();
			FourWheeler();
			break;
			
			default:
			gotoxy(50,21);
			printf("Invalid Choice!!! Please again Type given options!!!");
			SleepAndClear4000();
			Bus();		
		}
		
fclose(fptr);
getch();
return 0;
}

//Ashok Bus starts--------------------------------------------------------------
int AshokBus()
{
	char words_for_welcomeTo[50]="\t\tList of Ashok Bus";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Bus\\2Bus.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Leyland");
	gotoxy(50,15);
	printf("2. Back to Previous Menu");
	gotoxy(50,17);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			AshokLeyland();
			break;	
			
			case '2':
			SleepAndClear();
			Bus();
			break;
			
			default:
				gotoxy(50,19);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				AshokBus();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

int AshokLeyland()
{
	char words_for_welcomeTo[50]="\t\tList ofAshokLeyland Bus";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Bus\\Ashok\\Leyland\\Ashok Leyland List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=3840;
				SleepAndClear();
				LeylandNo3840();
			break;	
			
			case '2':
				VehicleNo=3841;
				SleepAndClear();
				LeylandNo3841();	
			break;
		
			case '3':
				SleepAndClear();
				AshokBus();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				AshokLeyland();
		}			
		
fclose(fptr);
getch();
return 0;
}

int LeylandNo3840()
{
	char VehicleType[]="Bus";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Ashok";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tAshok Leyland: Bus No 3840";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bus\\Ashok\\Leyland\\Ashok Leyland No 3840.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			AshokLeyland();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				LeylandNo3840();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int LeylandNo3841()
{
	char VehicleType[]="Bus";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Ashok";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tAshok Leyland: Bus No 3841";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bus\\Ashok\\Leyland\\Ashok Leyland No 3841.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			AshokLeyland();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				LeylandNo3841();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

//Tata Bus starts--------------------------------------------------------------
int TataBus()
{
	char words_for_welcomeTo[50]="\t\tList of Tata Bus";
	TitleAndWelcomeTo(words_for_welcomeTo);	

	char FileName[]="E:\\VRS\\Bus\\2Bus.txt";
	DisplayFile(FileName);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("----------------");
	gotoxy(50,14);
	printf("1. Deluxe Volvo");
	gotoxy(50,15);
	printf("2. Mini Bus");
	gotoxy(50,16);
	printf("3. Back to Previous Menu");
	gotoxy(50,18);
	printf("Type your choice ==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			TataDeluxeVolvo();
			break;	
			
			case '2':
			SleepAndClear();
			TataMiniBus();
			break;
			
			case '3':
			SleepAndClear();
			Bus();
			break;
			
			default:
				gotoxy(50,20);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				TataBus();
		} //end of switch	

fclose(fptr);
getch();
return 0;
}

int TataDeluxeVolvo()
{
	char words_for_welcomeTo[50]="\t\tList of Tata Deluxe Volvo Bus";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Bus\\Tata\\Deluxe Volvo\\Tata Deluxe Volvo List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=3201;
				SleepAndClear();
				DeluxeVolvoNo3201();
			break;	
			
			case '2':
				VehicleNo=3202;
				SleepAndClear();
				DeluxeVolvoNo3202();	
			break;
		
			case '3':
				SleepAndClear();
				TataBus();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				TataDeluxeVolvo();
		}			
		
fclose(fptr);
getch();
return 0;
}

int DeluxeVolvoNo3201()
{
	char VehicleType[]="Bus";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Tata";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tTata Deluxe Volvo: Bus No 3201";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bus\\Tata\\Deluxe Volvo\\Tata Deluxe Volvo No 3201.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			TataDeluxeVolvo();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				DeluxeVolvoNo3201();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int DeluxeVolvoNo3202()
{
	char VehicleType[]="Bus";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Tata";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tTata Deluxe Volvo: Bus No 3202";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bus\\Tata\\Deluxe Volvo\\Tata Deluxe Volvo No 3202.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			TataDeluxeVolvo();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				DeluxeVolvoNo3202();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int TataMiniBus()
{
	char words_for_welcomeTo[50]="\t\tList of Tata Mini Bus";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Bus\\Tata\\Mini Bus\\Tata Mini Bus List.txt";
	DisplayFile(FileName);
		
		switch(getche())
		{
			case '1':
				VehicleNo=2601;
				SleepAndClear();
				MiniBusNo2601();
			break;	
			
			case '2':
				VehicleNo=2602;
				SleepAndClear();
				MiniBusNo2602();	
			break;
		
			case '3':
				SleepAndClear();
				TataBus();
			break;
				
			default:	
				gotoxy(50,30);
				printf("Invalid Choice!!! Please again Type given options!!!");
				SleepAndClear4000();
				TataMiniBus();
		}			
		
fclose(fptr);
getch();
return 0;
}

int MiniBusNo2601()
{
	char VehicleType[]="Bus";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Tata";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tTata Mini Bus: Bus No 2601";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bus\\Tata\\Mini Bus\\Tata Mini Bus No 2601.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			TataMiniBus();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				MiniBusNo2601();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

int MiniBusNo2602()
{
	char VehicleType[]="Bus";
	strcpy(VehicleTypeValue,VehicleType);
	char VehicleBrand[]="Tata";
	strcpy(VehicleBrandValue,VehicleBrand);
	
	char c, words_for_welcomeTo[50]="\t\tTata Mini Bus: Bus No 2602";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Bus\\Tata\\Mini Bus\\Tata Mini Bus No 2602.txt";
	DisplayFile(FileName);
		
	//Menus
	gotoxy(50,30);
	printf("1. Proceed to Rent Now");
	gotoxy(50,31);
	printf("2. Go Back to Previous Menu");
	gotoxy(50,32);
	printf("3. Go Back to Main Menu");
	gotoxy(50,34);
	printf("Type your choice ==>");

	switch(getche())
		{
			case '1':
			SleepAndClear();
			Step1Customer();
			break;	
			
			case '2':
			SleepAndClear();
			TataMiniBus();
			break;
			
			case '3':
			SleepAndClear();
			MainMenus();
			break;
			
			default:
				gotoxy(50,35);
				printf("Invalid Choice!!! Please again type given options!!!");
				SleepAndClear4000();
				MiniBusNo2602();
		} //end of switch	
	
fclose(fptr);
getch();	
return 0;
}

//Main menu's More options starts------------------------------------------------------------------
int MoreOptions()
{
	char words_for_welcomeTo[50]="\t\tMore Options";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	gotoxy(50,12);
	printf("LIST OF OPTIONS:");
	gotoxy(50,13);
	printf("-------------------------------------");
	gotoxy(50,14);
	printf("1. List all Customer Records");
	gotoxy(50,15);
	printf("2. Search Your Customer Record");
	gotoxy(50,16);
	printf("3. List all Booking Records");
	gotoxy(50,17);
	printf("4. Search Your Booking Record");
	gotoxy(50,18);
	printf("5. Back to Previous Menu ");
	
	//choice using switch case
	gotoxy(50,20);
	printf("Type your choice==>");

	switch(getche())
		{
			case '1': 
			SleepAndClear();
			ListCustomerDetails();
			break;
			
			case '2': 
			SleepAndClear();
			SearchCustomerDetails();
			break;
			
			case '3': 
			SleepAndClear();
			ListBookingDetails();
			break;
			
			case '4': 
			SleepAndClear();
			SearchBookingDetails();
			break;	
		
			case '5': 
			SleepAndClear();
			MainMenus();
			break;
		
			default:
					gotoxy(50,22);
					printf("Invalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					MoreOptions();
		} //end of switch
return 0;		
}

// list of more options starts
int ListCustomerDetails()
{
	char words_for_welcomeTo[50]="\t\tList of all Customer Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	printf("\n\n");
	char FileName[]="E:\\VRS\\Customer Details.txt";
	DisplayFile(FileName);
	
	printf("\n\n\t\t\t\t\t\t  [Type 1: To go back]==>");
	
	if(getche()=='1')
	{
		SleepAndClear();
		MoreOptions();
	}
	else
	{
		printf("\n\n\t\t\t\t\t\t  Invalid Choice!!! Please again Type given options!!!\n");
		SleepAndClear4000();
		ListCustomerDetails();	
	}
return 0;	
}

int SearchCustomerDetails()
{
	dataFound=0;
	char words_for_welcomeTo[50]="\t\t Search Customer Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Search Part\\Customer Details for Search.txt";
	FileToReadAndWrite(FileName);
	
	gotoxy(50,12);
	printf("Enter the first name of customer which is to be searched: ");
	gets(name_to_search);
	fseek(fptr,0,SEEK_SET);
	while(fread(&cus,sizeof(cus),1,fptr)==1)
	{	
		if(strcmp(cus.cus_first_name,name_to_search)==0)
		{
			dataFound=1;
			printf("\n-----------------------------------------------------------------------------------\n");
			printf(" First Name : %s \n Last Name  : %s \n Address    : %s \n Email      : %s \n Phone No   : 98%08lu",cus.cus_first_name, cus.cus_last_name, cus.cus_address, cus.cus_email,cus.cus_phone_no);
		}
	}
	if(dataFound==0)
	{
	gotoxy(50,14);
	printf("    No Data Found. Try Again!!!");
	tryAgain:
	printf("\n\n\t\t\t\t\t\t  Do you want to try searching again? [Type 'Y' for Yes and 'N' for No] ==>");
	switch(getche())
		{
			case 'Y': 
			SleepAndClear();
			SearchCustomerDetails();
			break;
			
			case 'y': 
			SleepAndClear();
			SearchCustomerDetails();
			break;
			
			case 'N': 
			SleepAndClear();
			MoreOptions();
			break;
			
			case 'n': 
			SleepAndClear();
			MoreOptions();
			break;
			
			default:
					printf("\n\n\t\t\t\t\t\t  Invalid Choice!!! Please again Type given options!!!\n");
					goto tryAgain;
		} //end of switch
	}
	
	printf("\n\n\t\t\t\t\t\t  [Type 1: To go back]==>");
	if(getche()=='1')
	{
		SleepAndClear();
		MoreOptions();
	}
	else
	{
		printf("\n\n\t\t\t\t\t\t  Invalid Choice!!! Please again Type given options!!!\n");
		SleepAndClear4000();
		SearchCustomerDetails();	
	}
return 0;
}

int ListBookingDetails()
{
	char words_for_welcomeTo[50]="\t\tList of all Booking Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	printf("\n\n");
	char FileName[]="E:\\VRS\\Booking Details.txt";
	DisplayFile(FileName);
	
	printf("\n\n\t\t\t\t\t\t  [Type 1: To go back]==>");
	
	if(getche()=='1')
	{
		SleepAndClear();
		MoreOptions();
	}
	else
	{
		printf("\n\n\t\t\t\t\t\t  Invalid Choice!!! Please again Type given options!!!\n");
		SleepAndClear4000();
		ListBookingDetails();	
	}
	
return 0;	
}

int SearchBookingDetails()
{
	dataFound=0;
	char words_for_welcomeTo[50]="\t\t Search Booking Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Search Part\\Booking Details for Search.txt";
	FileToReadAndWrite(FileName);
	
	gotoxy(50,12);
	printf("Enter the first name of customer whose booking details are to be searched: ");
	gets(name_to_search);
	fseek(fptr,0,SEEK_SET);
	while(fread(&rd,sizeof(rd),1,fptr)==1)
	{
		if(strcmp(cus.cus_first_name,name_to_search)==0)
		{
			dataFound=1;
			printf("\n-----------------------------------------------------------------------------------\n");
  			printf(" Full Name       : %s %s \n Vehicle Type    : %s \n Vehicle Number  : %d \n Pickup Location : %s \n Pick up date    : 20%d/%d/%d \n Rental Duration : %d(days) \n Advance Deposit : Rs.%d/-\n Return Location : %s ",cus.cus_first_name,cus.cus_last_name,VehicleTypeValue,VehicleNo,rd.pick_up_location,rd.pdate.year,rd.pdate.month,rd.pdate.day,rd.rental_duration,rd.advance, rd.pick_up_location);
		}
	}
	
	if(dataFound==0)
	{
		gotoxy(50,14);
		printf("    No Data Found. Try Again!!!");
		tryAgain:
		printf("\n\n\t\t\t\t\t\t  Do you want to try searching again? [Type 'Y' for Yes and 'N' for No] ==>");
		switch(getche())
			{
				case 'Y': 
				SleepAndClear();
				SearchBookingDetails();
				break;
				
				case 'y': 
				SleepAndClear();
				SearchBookingDetails();
				break;
				
				case 'N': 
				SleepAndClear();
				MoreOptions();
				break;
				
				case 'n': 
				SleepAndClear();
				MoreOptions();
				break;
				
				default:
						printf("\n\n\t\t\t\t\t\t  Invalid Choice!!! Please again Type given options!!!\n");
						goto tryAgain;
			} //end of switch
		}
	
	printf("\n\n\t\t\t\t\t\t  [Type 1: To go back]==>");
	if(getche()=='1')
	{
		SleepAndClear();
		MoreOptions();
	}
	else
	{
		printf("\n\n\t\t\t\t\t\t  Invalid Choice!!! Please again Type given options!!!\n");
		SleepAndClear4000();
		SearchBookingDetails();	
	}
return 0;
}

//Price, Rent, customer details starts+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

// step to record customer details
int	Step1Customer()
{
	char words_for_welcomeTo[50]="\t\tStep 1: Customer Details";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Customer Details.txt";
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
 	 
 	gotoxy(50,19);
	printf("Customer Details have been submitted successfully.");
	
	SleepAndClear4000();
	CustomerMenu();			
return 0;	
}

//Customer menus related to above step 1 
int CustomerMenu()
{
	char words_for_welcomeTo[50]="\t\t\tCustomer Menu";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Customer Details.txt";
	FileToReadAndWrite(FileName);
	
	printf(" Your provided Customer details is:\n");
	printf("------------------------------------------------\n");
	printf(" First Name : %s\n Last Name  : %s\n Address    : %s\n Email      : %s\n Phone No   : 98%08lu",cus.cus_first_name, cus.cus_last_name, cus.cus_address, cus.cus_email,cus.cus_phone_no);

	gotoxy(50,23);
	printf("LIST OF OPTIONS:");
	gotoxy(50,24);
	printf("-------------------------------------");
	gotoxy(50,25);
	printf("1. Modify provided Customer details");
	gotoxy(50,26);
	printf("2. Cancel or delete provided Customer details");
	gotoxy(50,27);
	printf("3. Continue to NEXT STEP without modification or deletion");
	
	//choice using switch case
	gotoxy(50,29);
	printf("Type your choice==>");

	switch(getche())
		{
			case '1': 
			SleepAndClear();
			ModifyCustomerDetails();
			break;
			
			case '2': 
			SleepAndClear();
			DeleteCustomerDetails();
			break;			
			
			case '3': 
			fseek(fptr,0,SEEK_END); //to the end of file and then add new data from there
			fprintf(fptr,"\n-----------------------------------------------------------------------------------\n");
			//storing details in certain format using fprintf in file
			fprintf(fptr," First Name : %s\n Last Name  : %s\n Address    : %s\n Email      : %s\n Phone No   : 98%08lu",cus.cus_first_name, cus.cus_last_name, cus.cus_address, cus.cus_email,cus.cus_phone_no);
			
			WritingCustomerDataForSearch(); //writing customer data for search part only using fwrite
			
			SleepAndClear();
			Step2Book();
			break;	
		
			default:
					gotoxy(50,31);
					printf("Invalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					CustomerMenu();
		} //end of switch
return 0;		
}

//Modify part of Customer
int ModifyCustomerDetails()
{	
	char words_for_welcomeTo[50]="\t\t Modify Customer Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Customer Details.txt";
	FileToReadAndWrite(FileName);
	
	printf(" Your provided Customer details is:\n");
	printf("------------------------------------------------\n");
	printf(" First Name : %s\n Last Name  : %s\n Address    : %s\n Email      : %s\n Phone No   : 98%08lu",cus.cus_first_name, cus.cus_last_name, cus.cus_address, cus.cus_email,cus.cus_phone_no);
	
			printf("\n\nEnter New details:");	
			printf("\nFirst Name:");
			scanf("%s",cus.cus_first_name);
			printf("\nLast Name : ");
			scanf("%s",cus.cus_last_name);
			printf("\nAddress   :");
			scanf("%s",cus.cus_address);
			printf("\nEmail     :");
			scanf("%s",cus.cus_email);
			printf("\nPhone No  : 98");
			scanf("%08lu",&cus.cus_phone_no);
			
			fseek(fptr,0,SEEK_END); //to the end of file and then add new data from there
			fprintf(fptr,"\n-----------------------------------------------------------------------------------\n");
		
			//storing details in certain format using fprintf in file
			fprintf(fptr," First Name : %s\n Last Name  : %s\n Address    : %s\n Email      : %s\n Phone No   : 98%08lu",cus.cus_first_name, cus.cus_last_name, cus.cus_address, cus.cus_email,cus.cus_phone_no);
			
			WritingCustomerDataForSearch(); //writing customer data for search part only using fwrite
			
	printf("\n\nYour provided details have been successfully modified. \n\n Now you are proceeding to NEXT STEP.");
	
	SleepAndClear4000();
	Step2Book();

return 0;
}		

//search part of customer
int WritingCustomerDataForSearch()
{
		//using fwrite for search part
			char FileName[]="E:\\VRS\\Search Part\\Customer Details for Search.txt";
			FileToReadAndWrite(FileName);
			fseek(fptr,0,SEEK_END); //to the end of file and then add new data from there
			fwrite(&cus,sizeof(cus),1,fptr);	
return 0;	
}

//Delete part of Customer	
int DeleteCustomerDetails()
{	
	char words_for_welcomeTo[50]="\tDelete/Cancel current Customer Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Customer Details.txt";
	FileToReadAndWrite(FileName);
	
	printf(" Your provided Customer details is:\n");
	printf("------------------------------------------------");
	printf(" First Name : %s\n Last Name  : %s\n Address    : %s\n Email      : %s\n Phone No   : 98%08lu",cus.cus_first_name, cus.cus_last_name, cus.cus_address, cus.cus_email,cus.cus_phone_no);
	
	gotoxy(30,23);
	printf(" Do you want to Cancel Customer details you just provided? [Type 'Y' for Yes and 'N' for No]: ");
			
	switch(getche())
		{
			case 'Y':
			gotoxy(50,25);
			printf(" Successfully Cancelled!!!");
			goto cancelOptions;
			break;
			
			case 'y': 
			gotoxy(50,25);
			printf(" Successfully Cancelled!!!");
			goto cancelOptions;
			break;
			
			case 'N': 
			SleepAndClear();
			CustomerMenu();
			break;
			
			case 'n': 
			SleepAndClear();
			CustomerMenu();
			break;
			
			default:
					gotoxy(50,27);
					printf("Invalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					DeleteCustomerDetails();
		} //end of switch
		
		cancelOptions:
		gotoxy(50,29);
		printf(" After Cancellation, you want to:");
		gotoxy(50,30);
		printf(" 1. Enter NEW Customer Details");
		gotoxy(50,31);
		printf(" 2. Go back to Main Menus");
		gotoxy(50,33);
		printf(" TYPE your choice ==>");
		
		againTry:	
		switch(getche())
		{
			case '1': 
			SleepAndClear();
			Step1Customer();
			break;
			
			case '2': 
			SleepAndClear();
			MainMenus();
			break;
			
			default:
					printf("\n\t\t\t\t\t\t   Invalid Choice!!! Please again Type given options:");
					goto againTry;
		} //end of switch
return 0;
}

// step to record booking details
int	Step2Book()
{
	rd.advance=0;
	char words_for_welcomeTo[50]="\t\tStep 2: Booking Details";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	gotoxy(50,12);	
	printf("Choosen Bike Number: %d",VehicleNo);
	
	gotoxy(50,14);
	printf("Please provide the required details");
	gotoxy(50,15);
	printf("Pick Up Location:");
	gotoxy(70,15);
	scanf(" %s",rd.pick_up_location);
	gotoxy(50,16);
	printf("Pick Up Date:");
		gotoxy(70,16);
		printf("Year:  20");
		gotoxy(79,16);
		scanf("%02d",&rd.pdate.year);
		gotoxy(70,17);
		printf("Month:"); 
		gotoxy(77,17);
		scanf("%02d",&rd.pdate.month);
		gotoxy(70,18);
		printf("Day:");
		gotoxy(77,18);
		scanf("%02d",&rd.pdate.day);
	gotoxy(50,19);
	printf("Rental Duration(days):");
	gotoxy(77,19);
	scanf("%d",&rd.rental_duration);
	gotoxy(50,20);
	printf("Advance Deposit(In Rs.) :");
	gotoxy(77,20);
	scanf("%d",&rd.advance);
	
	rd.advance=rd.advance+0;
	newDay=rd.pdate.day+rd.rental_duration;	
							
	gotoxy(50,28);
	printf("Booking Details have been submitted successfully.");

 	SleepAndClear4000();
 	BookingMenu();			
return 0;	
}

//displaying provided data of Booking (related to step 2)
int DPBD()	//DPBD means Display Provided Booking Details, Only Printf Part 
{
	int day_max=30, month_max=12;
	printf("------------------------------------------------\n");
  	printf(" Full Name       : %s %s\n Vehicle Type    : %s\n Vehicle Number  : %d\n Pickup Location : %s\n Pick up date    : 20%02d/%02d/%02d\n Rental Duration : %d(days)\n Advance Deposit : Rs.%d/-\n Return Location : %s",cus.cus_first_name,cus.cus_last_name,VehicleTypeValue,VehicleNo,rd.pick_up_location,rd.pdate.year,rd.pdate.month,rd.pdate.day,rd.rental_duration,rd.advance, rd.pick_up_location);
				
				//only calculating return date :printf only
				if(newDay > day_max)
					{	
						newDay=newDay-day_max;
						newMonth=rd.pdate.month+1;
					
						if(newMonth > month_max)
						{
							newMonth2=newMonth-month_max;
							newYear=rd.pdate.year+1;
							gotoxy(1,22);
							printf("Your Return Date is: Year:20%02d    Month:%02d    Day:%02d ",newYear,newMonth2,newDay );
						}
						else
						{
							gotoxy(1,22);
							printf("Your Return Date is: Year:20%02d    Month:%02d    Day:%02d ",rd.pdate.year,newMonth,newDay );
						}
					}	
						
				else if(rd.pdate.month > month_max)
					{
						newMonth=rd.pdate.month-month_max;
						newYear=rd.pdate.year+1;
						gotoxy(1,22);
						printf("Your Return Date is: Year:20%02d    Month:%02d    Day:%02d ",newYear,newMonth,newDay );

					}
	
				else if(rd.pdate.month <= month_max && newDay <= day_max)
				{
					gotoxy(1,22);
					printf("Your Return Date is: Year:20%02d   Month:%02d   Day:%02d",rd.pdate.year,rd.pdate.month, newDay);
				}
				else
				{	
				gotoxy(1,24);
				printf("Please! Again provide valid data.");
				SleepAndClear4000();
				Step2Book();
				}

return 0;	
}

//writing provide booking details to file (related to step 2)
int WPBD() 		//WPBD means Writing Provided Booking Details using frpintf part
{
	int day_max=30, month_max=12;
			fseek(fptr,0,SEEK_END); //to the end of file and then add new data from there
			fprintf(fptr,"\n-----------------------------------------------------------------------------------\n");
  			fprintf(fptr," Full Name       : %s %s\n Vehicle Type    : %s\n Vehicle Number  : %d\n Pickup Location : %s\n Pick up date    : 20%02d/%02d/%02d\n Rental Duration : %d(days)\n Advance Deposit : Rs.%d/-\n Return Location : %s",cus.cus_first_name,cus.cus_last_name,VehicleTypeValue,VehicleNo,rd.pick_up_location,rd.pdate.year,rd.pdate.month,rd.pdate.day,rd.rental_duration,rd.advance, rd.pick_up_location);
				
				//only calculating return date: fprintf only
				if(newDay > day_max)
					{	
						newDay=newDay-day_max;
						newMonth=rd.pdate.month+1;
					
						if(newMonth > month_max)
						{
							newMonth2=newMonth-month_max;
							newYear=rd.pdate.year+1;
							fprintf(fptr,"\n Your Return Date is: Year:20%02d    Month:%02d    Day:%02d ",newYear,newMonth2,newDay );
						}
						else
						{
						fprintf(fptr,"\n Your Return Date is: Year:20%02d    Month:%02d    Day:%02d ",rd.pdate.year,newMonth,newDay );
						}
					}	
						
				else if(rd.pdate.month > month_max)
					{
						newMonth=rd.pdate.month-month_max;
						newYear=rd.pdate.year+1;
						fprintf(fptr,"\n Your Return Date is: Year:20%02d    Month:%02d    Day:%02d ",newYear,newMonth,newDay );

					}
	
				else if(rd.pdate.month <= month_max && newDay <= day_max)
				{
					fprintf(fptr, "\n Your Return Date is: Year:20%02d   Month:%02d   Day:%02d",rd.pdate.year,rd.pdate.month, newDay);
				}
				else
				{	
				gotoxy(1,24);
				printf("Please! Again provide valid data.");
				SleepAndClear4000();
				Step2Book();
				}
				
			WritingBookingDataForSearch(); //writing booking data for search part only using fwrite
	
return 0;	
}

//Booking menus part related to step 2
int BookingMenu()
{
	char words_for_welcomeTo[50]="\t\t\tBooking Menu";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	char FileName[]="E:\\VRS\\Booking Details.txt";
	FileToReadAndWrite(FileName);
	
	printf(" Your provided Booking details is:\n");
	DPBD();
	
	gotoxy(50,24);
	printf("LIST OF OPTIONS:");
	gotoxy(50,25);
	printf("-------------------------------------");
	gotoxy(50,26);
	printf("1. Modify provided Booking details");
	gotoxy(50,27);
	printf("2. Cancel or delete provided Booking details");
	gotoxy(50,28);
	printf("3. Continue to NEXT STEP without modification or deletion");

	//choice using switch case
	gotoxy(50,30);
	printf("Type your choice==>");

	switch(getche())
		{
			case '1': 
			SleepAndClear();
			ModifyBookingDetails();
			break;
			
			case '2': 
			SleepAndClear();
			DeleteBookingDetails();
			break;			
			
			case '3': 
			WPBD();
			SleepAndClear();
			Step3Calculate();
			break;	
		
			default:
					gotoxy(50,32);
					printf("Invalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					BookingMenu();
		} //end of switch
return 0;		
}

//Modify part of Booking
int ModifyBookingDetails()
{	
	char words_for_welcomeTo[50]="\t\t Modify Booking Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	char FileName[]="E:\\VRS\\Booking Details.txt";
	FileToReadAndWrite(FileName);
	
	printf(" Your provided Booking details is:\n");
	DPBD();
		
		printf("\n\nEnter New details:");
	printf("\n-----------------------------");	
	gotoxy(1,26);
	printf("Pick Up Location:");
	gotoxy(20,26);
	scanf(" %s",rd.pick_up_location);
	gotoxy(1,27);
	printf("Pick Up Date:");
		gotoxy(21,27);
		printf("Year:  20");
		gotoxy(30,27);
		scanf("%02d",&rd.pdate.year);
		gotoxy(21,28);
		printf("Month:"); 
		gotoxy(30,28);
		scanf("%02d",&rd.pdate.month);
		gotoxy(21,29);
		printf("Day:");
		gotoxy(30,29);
		scanf("%02d",&rd.pdate.day);
	gotoxy(1,30);
	printf("Rental Duration:(days)");
	gotoxy(30,30);
	scanf("%.3d",&rd.rental_duration);
	gotoxy(1,31);
	printf("Advance Deposit::(In Rs.)");
	gotoxy(30,31);
	scanf("%d",&rd.advance);

	rd.advance=rd.advance+0;
	newDay=rd.pdate.day+rd.rental_duration;	
	WPBD();	 //writing provided booking details to file function
		
	printf("\n\nYour provided details have been successfully modified. \n\n Now you are proceeding to NEXT STEP.");
	
	SleepAndClear4000();
	Step3Calculate();

return 0;
}		

//search part of customer
int WritingBookingDataForSearch()
{
		//using fwrite for search part
			char FileName[]="E:\\VRS\\Search Part\\Booking Details for Search.txt";
			FileToReadAndWrite(FileName);
			fseek(fptr,0,SEEK_END); //to the end of file and then add new data from there
			fwrite(&rd,sizeof(rd),1,fptr);	
return 0;	
}

//Delete part of Customer	
int DeleteBookingDetails()
{	
	char words_for_welcomeTo[50]="\t\t Delete/Cancel current Customer Records";
	TitleAndWelcomeTo(words_for_welcomeTo);	
	
	printf(" Your provided Booking details is:\n");
	DPBD();
	
	printf("\n\n Do you want to Cancel Booking details you just provided? [Type 'Y' for Yes and 'N' for No]: ");
			
	switch(getche())
		{
			case 'Y': 
			printf("\n\n Successfully Cancelled!!!\n\n Enter NEW Booking Details");
			SleepAndClear4000();
			Step2Book();
			break;
			
			case 'y': 
			printf("\n\n Successfully Cancelled!!!\n\n Enter NEW Booking Details");
			SleepAndClear4000();
			Step2Book();
			break;
			
			case 'N': 
			SleepAndClear();
			BookingMenu();
			break;
			
			case 'n': 
			SleepAndClear();
			BookingMenu();
			break;
			
			default:
					printf("\n\nInvalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					DeleteBookingDetails();
		} //end of switch
return 0;
}


int	Step3Calculate()
{		
	char FileName[]="E:\\VRS\\Welcome VRS.txt";
	DisplayFile(FileName);
	
	printf("\n\n\t\t\t\t\t\t  -------------------------------------------------------------\n");
	printf("\t\t\t\t\t\t\tStep 3 & 4: Price Calculation and Invoice Generation");
	printf("\n\t\t\t\t\t\t  -------------------------------------------------------------\n");

	gotoxy(50,12);
	printf("Price is being Calculated.Please Wait");
	for(i=0;i<3;i++)
	{
		printf(".");
		Sleep(1000);
	}

	//Honda Bike===================================
	//Bike Honda 150 cc calculation
	if(VehicleNo==1501)
	{
		Rental_Price=1500*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1502)
	{
		Rental_Price=1550*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1503)
	{
		Rental_Price=1400*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Bike Honda 250 cc calculation
	else if(VehicleNo==2501)
	{
		Rental_Price=1700*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==2502)
	{
		Rental_Price=1750*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==2503)
	{
		Rental_Price=1600*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Bike Honda 300 cc calculation
	else if(VehicleNo==3001)
	{
		Rental_Price=1900*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==3002)
	{
		Rental_Price=1950*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==3003)
	{
		Rental_Price=1800*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Puolsar Bike==============================
	//Bike Pulsar 180 cc calculation
	else if(VehicleNo==1801)
	{
		Rental_Price=1800*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1802)
	{
		Rental_Price=1850*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Bike Pulsar 220 cc calculation
	else if(VehicleNo==2201)
	{
		Rental_Price=1900*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==2202)
	{
		Rental_Price=1950*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Yamaha Bike==============================
	//Bike Yamaha 150 cc calculation
	else if(VehicleNo==151)
	{
		Rental_Price=1950*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==152)
	{
		Rental_Price=1900*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Bike Yamaha 300 cc calculation
	else if(VehicleNo==301)
	{
		Rental_Price=2450*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==302)
	{
		Rental_Price=2400*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Scooty starts=========================
	//Scooty Honda Dio calculation
	else if(VehicleNo==1101)
	{
		Rental_Price=1150*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1102)
	{
		Rental_Price=1100*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Scooty Suzuki Access calculation
	else if(VehicleNo==1251)
	{
		Rental_Price=1200*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1252)
	{
		Rental_Price=1250*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Scooty Suzuki Lets calculation
	else if(VehicleNo==1131)
	{
		Rental_Price=1130*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1132)
	{
		Rental_Price=1230*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Scooty Hero Pleasure calculation
	else if(VehicleNo==1103)
	{
		Rental_Price=1150*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1104)
	{
		Rental_Price=1100*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Car Starts==================================
	//Car Tata Indica Ev2 calculation
	else if(VehicleNo==1401)
	{
		Rental_Price=4500*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1402)
	{
		Rental_Price=4400*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Car Tata Indica Vista calculation
	else if(VehicleNo==1255)
	{
		Rental_Price=3800*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==1256)
	{
		Rental_Price=3850*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Car Toyota Hilux calculation
	else if(VehicleNo==2447)
	{
		Rental_Price=5050*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==2448)
	{
		Rental_Price=5100*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Car Toyota Land Cruiser calculation
	else if(VehicleNo==3432)
	{
		Rental_Price=6200*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==3433)
	{
		Rental_Price=6100*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Bus starts===========================
	//Bus Ashok Leyland calculation
	else if(VehicleNo==3840)
	{
		Rental_Price=10900*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==3841)
	{
		Rental_Price=10500*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Bus Tata Mini Bus calculation
	else if(VehicleNo==2601)
	{
		Rental_Price=8500*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==2602)
	{
		Rental_Price=8200*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	//Bus Tata Deluxe Volvo calculation
	else if(VehicleNo==3201)
	{
		Rental_Price=9700*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	
	else if(VehicleNo==3202)
	{
		Rental_Price=9400*rd.rental_duration;
		Total_Rental_Price=Rental_Price-rd.advance;
	}
	

	gotoxy(50,14);
	printf("Calculation Process Completed.");
	Sleep(2000);
	
	Step4Invoice();

return 0;	
}

int	Step4Invoice()
{
	static int Invoice_No=0;
	int day_max=30, month_max=12;
	
	gotoxy(50,16);
	printf("Here is bill receipt for you.");
	
	gotoxy(70,18);
	printf("Vehicle Rental - Customer Invoice");
	gotoxy(50,19);
	printf("///////////////////////////////////////////////////////////////////");
	gotoxy(50,20);
	
	printf("| Invoice No: -----------------------");
	gotoxy(87,20);
	printf("|");
	gotoxy(88,20);
	printf(" VRS0%02d ",Invoice_No+1);
	gotoxy(115,20);
	printf("|");
	
	gotoxy(50,21);
	printf("| Customer Name: --------------------");
	gotoxy(87,21);
	printf("|");
	gotoxy(88,21);
	printf(" %s  %s ", cus.cus_first_name,cus.cus_last_name);
	gotoxy(115,21);
	printf("|");
	
	gotoxy(50,22);	
	printf("| %s",VehicleTypeValue);
	gotoxy(60,22);
	printf("Brand:-------------------");
	gotoxy(87,22);
	printf("|");
	gotoxy(88,22);
	printf(" %s ", VehicleBrandValue);
	gotoxy(115,22);
	printf("|");
	
	gotoxy(50,23);
	printf("| %s", VehicleTypeValue);
	gotoxy(60,23);
	printf("Number:-------------------");
	gotoxy(87,23);
	printf("|");
	gotoxy(88,23);
	printf(" %d ", VehicleNo);
	gotoxy(115,23);
	printf("|");
	
	gotoxy(50,24);
	printf("| Pick Up Date: ---------------------");
	gotoxy(87,24);
	printf("|");
	gotoxy(88,24);
	printf(" 20%02d-%02d-%02d ",rd.pdate.year,rd.pdate.month,rd.pdate.day);
	gotoxy(115,24);
	printf("|");
	
	gotoxy(50,25);
	printf("| Pick Up Location: -----------------");
	gotoxy(87,25);
	printf("|");
	gotoxy(88,25);
	printf(" %s ",rd.pick_up_location);
	gotoxy(115,25);
	printf("|");

	gotoxy(50,26);
	printf("| Rental Duration: ------------------");
	gotoxy(87,26);
	printf("|");
	gotoxy(88,26);
	printf(" %d ",rd.rental_duration);
	gotoxy(115,26);
	printf("|");
	

  	gotoxy(50,27);
	printf("| Return Date: ----------------------");
	gotoxy(87,27);
	printf("|");
	newDay=rd.pdate.day+rd.rental_duration;	
				
				//only calculating return date :printf only
				if(newDay > day_max)
					{	
						newDay=newDay-day_max;
						newMonth=rd.pdate.month+1;
					
						if(newMonth > month_max)
						{
							newMonth2=newMonth-month_max;
							newYear=rd.pdate.year+1;
							gotoxy(88,27);
							printf(" 20%02d-%02d-%02d ",newYear,newMonth2,newDay );
						}
						else
						{
							printf(" 20%02d-%02d-%02d ",rd.pdate.year,newMonth,newDay );
						}
					}	
						
				else if(rd.pdate.month > month_max)
					{
						newMonth=rd.pdate.month-month_max;
						newYear=rd.pdate.year+1;
						gotoxy(88,27);
						printf(" 20%02d-%02d-%02d ",newYear,newMonth,newDay );

					}
	
				else if(rd.pdate.month <= month_max && newDay <= day_max)
				{
					gotoxy(88,27);
					printf(" 20%02d-%02d-%02d",rd.pdate.year,rd.pdate.month, newDay);
				}
				else
				{	
				gotoxy(88,27);
				printf(" Error");
				}
	gotoxy(115,27);
	printf("|");


	gotoxy(50,28);
	printf("| Return Location: ------------------");
	gotoxy(87,28);
	printf("|");
	gotoxy(88,28);
	printf(" %s ", rd.pick_up_location);
	gotoxy(115,28);
	printf("|");

	gotoxy(50,29);
	printf("| Your Rental Amount is: ------------");
	gotoxy(87,29);
	printf("|");
	gotoxy(88,29);
	printf(" %d ", Rental_Price);
	gotoxy(115,29);
	printf("|");
	
	gotoxy(50,30);
	printf("| Advance Deposit: ------------------");
	gotoxy(87,30);
	printf("|");
	gotoxy(88,30);
	printf(" %d ",rd.advance);
	gotoxy(115,30);
	printf("|");

	gotoxy(50,31);
	printf(" _________________________________________________________________");
	
	gotoxy(50,33);
	printf("| Total Rental Amount is: -----------");
	gotoxy(87,33);
	printf("|");
	gotoxy(88,33);
	printf(" %d ",Total_Rental_Price);
	gotoxy(115,33);
	printf("|");

	gotoxy(50,34);
	printf(" _________________________________________________________________");
	gotoxy(50,35);
	printf("# This is computer generated invoice and it does not require  ");
	gotoxy(50,36);
	printf("  an authorised signature. #");
	gotoxy(50,37);
	printf("///////////////////////////////////////////////////////////////////");
	gotoxy(50,38);
	printf("You are advised to pay up the amount before due date.");
	gotoxy(50,39);
	printf("Otherwise penalty fee will be applied. ");
	gotoxy(50,40);
	printf("///////////////////////////////////////////////////////////////////");

	ThankYou();
	system("cls");
	MainMenus();
getch();	
return 0;	
}

//////////////////////////////////Others
//Support------------------------------------------------------------------------------------------
int Support()
{
	char words_for_welcomeTo[50]="\t\tWelcome to Support Section";
	TitleAndWelcomeTo(words_for_welcomeTo);
	gotoxy(50,12);
	printf("CONTACT US:");
	gotoxy(50,13);
	printf("____________________________________________________________________");
	gotoxy(50,15);
	printf("Mobile No : 9808374003(Ameer), 9810130495(Badri), 9806101417(Sandip)");
	gotoxy(50,16);
	printf("Address   : New Baneshwor, Kathmandu");
	gotoxy(50,17);
	printf("Email     : developers.vrs@gmail.com");
	gotoxy(50,18);
	printf("_____________________________________________________________________");
	
	gotoxy(50,20);
	printf("[Type 1: To go back]==>");
	
	if(getche()=='1')
	{
		SleepAndClear();
		Welcome();
	}
	else
	{
		printf("\n\n\t\t\t )Invalid Choice!!! Please again Type given options!!!\n");
		SleepAndClear4000();
		Support();	
	}
getch();	
return 0;
}

//Help------------------------------------------------------------------------------------------
int Help()
{
	char words_for_welcomeTo[50]="\t\tWelcome to Help Section";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	gotoxy(50,12);
	printf("1. How to use VRS?");
	gotoxy(50,13);
	printf("2. About VRS");
	gotoxy(50,14);
	printf("3. Go Back");
	gotoxy(50,16);
	printf("Type your Choice==>");
	
	switch(getche())
		{
			case '1':
			SleepAndClear();
			HowToUse();
			break;	
			
			case '2':
			SleepAndClear();
			About();
			break;
			
			case '3':
			SleepAndClear();
			Welcome();
			break;
			
			default:
				printf("\n\n\t\t\t )Invalid Choice!!! Please again Type given options!!!\n");
				SleepAndClear4000();
				Help();
		} //end of switch

getch();		
return 0;
}

//How to use VRS
int HowToUse()
{
	char words_for_welcomeTo[50]="\t\tHow To Use VRS Section";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	gotoxy(50,12);
	printf("Steps to follow:");
	gotoxy(50,13);
	printf("--------------------------------------------------------------------------------------------------");
	gotoxy(50,15);
	printf("1. List of options is provided as per your choice, you read and choose");
	gotoxy(50,17);
	printf("2. Then, you must TYPE one of the provided letter or number to choose");
	gotoxy(50,19);
	printf("3. Then, you must TYPE related letter or word to go back");
	gotoxy(50,21);
	printf("4. If you TYPE wrong choice, then you are again to TYPE correct given options to proceed further");
	gotoxy(50,23);
	printf("--------------------------------------------------------------------------------------------------");
	gotoxy(80,25);
	printf("***Thank YOU***");				

	gotoxy(50,27);
	printf("[Type 1: To go back]==>");
	
	if(getche()=='1')
	{
		SleepAndClear();
		Help();
	}
	else
	{
		printf("\n\n\t\t\t )Invalid Choice!!! Please again Type given options!!!\n");
		SleepAndClear4000();
		HowToUse();	
	}
	

getch();
return 0;	
}

//About------------------------------------------------------------------------------------------
int About()
{
	char words_for_welcomeTo[50]="\t\tAbout Section";
	TitleAndWelcomeTo(words_for_welcomeTo);
	
	gotoxy(50,12);
	printf("| VRS(Vehicle Renting System) is a project based |");
	gotoxy(50,13);
	printf("| on C programming language. Its purpose is to   |");
	gotoxy(50,14);
	printf("| help people rent vehicle anytime, anywhere     |");
	gotoxy(50,15);
	printf("| easily and fast at affordable price.           |");
	gotoxy(50,16);
	printf(" ------------------------------------------------");

	gotoxy(50,18);
	printf("[Type 1: To go back]==>");
	
	if(getche()=='1')
	{
		SleepAndClear();
		Help();
	}
	else
	{
		printf("\n\n\t\t\t )Invalid Choice!!! Please again Type given options!!!\n");
		SleepAndClear4000();
		About();	
	}
	
getch();
return 0;
}

//Thank you------------------------------------------------------------------------------------------
int ThankYou()
{
	gotoxy(50,42);
	printf("Thank you for using VRS. Please Visit us again!!!");
	printf("\n");
	system("PAUSE");	
return 0;	
}

int Exit()
{
	char FileName[]="E:\\VRS\\Welcome VRS.txt";
	DisplayFile(FileName);
	
	gotoxy(50,13);
	printf("Are you sure to Exit? [Type 'Y' for Yes and 'N' to No]: ");
	
	switch(getche())
		{
			case 'Y': 
			printf("\n\n Successfully Exited!!!\n\n");
			ThankYou();
			exit(1);
			break;
			
			case 'y': 
			printf("\n\n Successfully Exited!!!\n\n");
			ThankYou();
			exit(1);
			break;
			
			case 'N': 
			SleepAndClear();
			Welcome();
			break;
			
			case 'n': 
			SleepAndClear();
			Welcome();
			break;
			
			default:
					gotoxy(50,15);
					printf("Invalid Choice!!! Please again Type given options!!!");
					SleepAndClear4000();
					Exit();				
		} //end of switch

fclose(fptr);
getch();
return 0;	
}

////////////Copyright @ 2019 during Corona and Lockdown project//////////////////////////////
