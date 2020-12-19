#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include <stdlib.h> 

//function declaration
void start();
void Service();
void Cjob();
void Edit();
void ViewSearch();
void Remove();

//structure declaration
struct customer
{
	char VID[10];
	char name[100];
	char date[2];
	char month[2];
	char year[4];
	char service[2];
	char days[2];
	char type[10];
	char fee[3];
}c;

//fee string to integer for total work done logic based on the acsi value of the string - 48 
int stringToInteger(char string[])
{
	int digit, j = 1, m = 0;
	for (int i = strlen(string) - 1; i >= 0; i--)
	{
		digit = string[i];
		digit = digit - 48;
		m = m + (digit * j);
		j = j * 10;
	}
	return m;
}
//First screen
void main()
{
	int i, b = 1;
	system("cls");
	printf("\n-------------------------\n");
	//got from reddit
	printf(" -------------------------------------------------------------------------\n");
	printf("|                                                                         |\n");
	printf("|                                                                         |\n");
	printf("|  OOOOOO   OOOOOO OOOOOO OOOOOO OOOOOO OOOOOO O      O OOOOOOO  OOOOOO   |\n");
	printf("|  O        O    O O      O        O      O    O O    O O        O        |\n");
	printf("|  O  OOOOO OOOOOO OOOOO  OOOOO    O      O    O  O   O O  OOOOO OOOOOO   |\n");
	printf("|  O    O   O  O   O      O        O      O    O   O  O O    O        O   |\n");
	printf("|  OOOOOO   O   O  OOOOOO OOOOOO   O    OOOOOO O    O O OOOOOO   OOOOOO   |\n");
	printf("|                                                                         |\n");
	printf(" -------------------------------------------------------------------------\n");
	printf("Welcome To Computer Repair System");
	printf("\n--------------------\n");
	printf("1.Continue\n");
	printf("2.Exit Program\n");
	fflush(stderr);
	scanf("%d", &i);
	switch (i)
	{
	case 1: while (b)
	{
		start();
	}
		  break;
	case 2: exit(0);
		break;
	default: printf("Error....\n");
	}
}
//starting screen
void start()
{
	int i;
	system("cls");
	printf("Choose an option\n");
	printf("1. Book Service\n");
	printf("2. Complete Job\n");
	printf("3. Edit Data\n");
	printf("4. View/Search\n");
	printf("5. Remove\n");
	printf("6. Exit\n\n");
	printf("   :");
	fflush(stderr);
	scanf("%d", &i);
	switch (i)
	{
	case 1: Service();
		break;
	case 2: Cjob();
		break;
	case 3: Edit();
		break;
	case 4: ViewSearch();
		break;
	case 5: Remove();
		break;
	case 6: exit(0);
	default: printf("Error...\n");
	}
}

//book service
void Service() 
{
	int i;
	system("cls");
	printf("NO               SERVICE TYPE                NEEDED DAYS            SERVICE FEE\n");
	printf("                                                                 NORMAL  |  URGENT\n");
	printf("1. Remove virus, malware or spyware            2 days             30RM       50RM\n");
	printf("2. Troubleshoot and fix computer running       2 days             40RM       70RM\n");
	printf("   slow\n");
	printf("3. Laptop screen replacement                   3 days             380RM      430RM\n");
	printf("4. Laptopn keyboard replacement                2 days             160RM      200RM\n");
	printf("5. Laptop battery replacement                  1 day              180RM      210RM\n");
	printf("6. Operating system format and installation    2 days             50RM       80RM\n");
	printf("7. Data backup and recovery                    2 days             100RM      150RM\n");
	printf("8. Internet connectivity issues                1 day              50RM       75RM\n\n");
	printf("Enter 9 to go back, enter 10 to view current jobs based on VID\n");
	printf("Enter service type NO\n");
	printf(": ");
	fflush(stderr);
	scanf("%d", &i);
	switch (i)
	{
	case 1:
	{
		int fee, change, outstanding, pay;
		int checkType;
		char str[2];
		int ch;
		char checkVID[10];
		char checkName[100];
		FILE* fp;
		system("cls");
		fflush(stdin);
		printf("Enter Visitor ID \n");
		printf(": ");
		scanf("%s", &checkVID);
		printf("\n");
		printf("Enter customer name\n");
		printf(": ");
		scanf("%s", &checkName);
		printf("\n");
		if ((fp = fopen("pending_job.txt", "r+")) != NULL)
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				if (strcmp(c.VID, checkVID) == 0 || strcmp(c.name, checkName) == 0)
				{
					printf("The visitor id/customer name has been used\n\n");
					fflush(stdin);
					printf("Enter 1 to re-enter details or 2 to return to main menu\n");
					printf(": ");
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: Service();
						break;
					case 2: start();
						break;
					default: printf("Error....!\n");
					}
				}
				else
				{
					strcpy(c.VID, checkVID);
					strcpy(c.name, checkName);
				}
			}
		}
		else
		{
			fp = fopen("pending_job.txt", "a+");
			if (fp == 0)
				fp = fopen("pending_job.txt", "w+");
			strcpy(c.VID, checkVID);
			strcpy(c.name, checkName);
		}
		printf("Enter the date\n");
		printf(": ");
		scanf("%s", &c.date);
		printf("\n");
		printf("Enter the month\n");
		printf(": ");
		scanf("%s", &c.month);
		printf("\n");
		printf("Enter the year\n");
		printf(": ");
		scanf("%s", &c.year);
		printf("\n");
		strcpy(c.service, "1");
		strcpy(c.days, "2");
		printf("Enter service type: 1 for normal or 2 for urgent\n");
		printf(": ");
		fflush(stdin);
		scanf("%d", &checkType);
		printf("\n");
		switch (checkType)
		{
		case 1:
		{
			strcpy(c.type, "normal");
			printf("The fee is 30RM\n");
			printf(": ");
			fflush(stdin);
			scanf("%d", &fee);
			if (fee > 30)
			{
				change = fee - 30;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "30");
			}
			else
			{
				outstanding = 30 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "30");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		case 2:
		{
			strcpy(c.type, "urgent");
			printf("The fee is 50RM\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &fee);
			if (fee > 50)
			{
				change = fee - 50;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "50");
			}
			else
			{
				outstanding = 50 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "50");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		default: printf("Error...\n");
		}
	}
	break;
	case 2:
	{
		int fee, change, outstanding, pay;
		int checkType;
		char str[2];
		int ch;
		char checkVID[10];
		char checkName[100];
		FILE* fp;
		system("cls");
		fflush(stdin);
		printf("Enter Visitor ID \n");
		printf(": ");
		scanf("%s", &checkVID);
		printf("\n");
		printf("Enter customer name\n");
		printf(": ");
		scanf("%s", &checkName);
		printf("\n");
		if ((fp = fopen("pending_job.txt", "r+")) != NULL)
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				if (strcmp(c.VID, checkVID) == 0 || strcmp(c.name, checkName) == 0)
				{
					printf("The visitor id/customer name has been used\n\n");
					fflush(stdin);
					printf("Enter 1 to re-enter details or 2 to return to main menu\n");
					printf(": ");
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: Service();
						break;
					case 2: start();
						break;
					default: printf("Error....!\n");
					}
				}
				else
				{
					strcpy(c.VID, checkVID);
					strcpy(c.name, checkName);
				}
			}
		}
		else
		{
			fp = fopen("pending_job.txt", "a+");
			if (fp == 0)
				fp = fopen("pending_job.txt", "w+");
			strcpy(c.VID, checkVID);
			strcpy(c.name, checkName);
		}
		printf("Enter the date\n");
		printf(": ");
		scanf("%s", &c.date);
		printf("\n");
		printf("Enter the month\n");
		printf(": ");
		scanf("%s", &c.month);
		printf("\n");
		printf("Enter the year\n");
		printf(": ");
		scanf("%s", &c.year);
		printf("\n");
		strcpy(c.service, "2");
		strcpy(c.days, "2");
		printf("Enter service type: 1 for normal or 2 for urgent\n");
		printf(": ");
		fflush(stdin);
		scanf("%d", &checkType);
		printf("\n");
		switch (checkType)
		{
		case 1:
		{
			strcpy(c.type, "normal");
			printf("The fee is 40RM\n");
			printf(": ");
			fflush(stdin);
			scanf("%d", &fee);
			if (fee > 40)
			{
				change = fee - 40;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "40");
			}
			else
			{
				outstanding = 40 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "40");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		case 2:
		{
			strcpy(c.type, "urgent");
			printf("The fee is 70RM\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &fee);
			if (fee > 70)
			{
				change = fee - 70;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "70");
			}
			else
			{
				outstanding = 70 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "70");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		default: printf("Error....!\n");
		}
	}
	break;
	case 3:
	{
		int fee, change, outstanding, pay;
		int checkType;
		char str[2];
		int ch;
		char checkVID[10];
		char checkName[100];
		FILE* fp;
		system("cls");
		fflush(stdin);
		printf("Enter Visitor ID \n");
		printf(": ");
		scanf("%s", &checkVID);
		printf("\n");
		printf("Enter customer name\n");
		printf(": ");
		scanf("%s", &checkName);
		printf("\n");
		if ((fp = fopen("pending_job.txt", "r+")) != NULL)
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				if (strcmp(c.VID, checkVID) == 0 || strcmp(c.name, checkName) == 0)
				{
					printf("The visitor id/customer name has been used\n\n");
					fflush(stdin);
					printf("Enter 1 to re-enter details or 2 to return to main menu\n");
					printf(": ");
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: Service();
						break;
					case 2: start();
						break;
					default: printf("Error....!\n");
					}
				}
				else
				{
					strcpy(c.VID, checkVID);
					strcpy(c.name, checkName);
				}
			}
		}
		else
		{
			fp = fopen("pending_job.txt", "a+");
			if (fp == 0)
				fp = fopen("pending_job.txt", "w+");
			strcpy(c.VID, checkVID);
			strcpy(c.name, checkName);
		}
		printf("Enter the date\n");
		printf(": ");
		scanf("%s", &c.date);
		printf("\n");
		printf("Enter the month\n");
		printf(": ");
		scanf("%s", &c.month);
		printf("\n");
		printf("Enter the year\n");
		printf(": ");
		scanf("%s", &c.year);
		printf("\n");
		strcpy(c.service, "3");
		strcpy(c.days, "3");
		printf("Enter service type: 1 for normal or 2 for urgent\n");
		printf(": ");
		fflush(stdin);
		scanf("%d", &checkType);
		printf("\n");
		switch (checkType)
		{
		case 1:
		{
			strcpy(c.type, "normal");
			printf("The fee is 380RM\n");
			printf(": ");
			fflush(stdin);
			scanf("%d", &fee);
			if (fee > 380)
			{
				change = fee - 380;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "380");
			}
			else
			{
				outstanding = 380 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "380");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		case 2:
		{
			strcpy(c.type, "urgent");
			printf("The fee is 430RM\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &fee);
			if (fee > 430)
			{
				change = fee - 430;
				printf("Your change is RM%d, press any key to continue,press any key to continue", change);
				_getch();
				strcpy(c.fee, "430");
			}
			else
			{
				outstanding = 430 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "430");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		default: printf("Error....\n");
		}
	}
	break;
	case 4:
	{
		int fee, change, outstanding, pay;
		int checkType;
		char str[2];
		int ch;
		char checkVID[10];
		char checkName[100];
		FILE* fp;
		system("cls");
		fflush(stdin);
		printf("Enter Visitor ID \n");
		printf(": ");
		scanf("%s", &checkVID);
		printf("\n");
		printf("Enter customer name\n");
		printf(": ");
		scanf("%s", &checkName);
		printf("\n");
		if ((fp = fopen("pending_job.txt", "r+")) != NULL)
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				if (strcmp(c.VID, checkVID) == 0 || strcmp(c.name, checkName) == 0)
				{
					printf("The visitor id/customer name has been used\n\n");
					fflush(stdin);
					printf("Enter 1 to re-enter details or 2 to return to main menu\n");
					printf(": ");
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: Service();
						break;
					case 2: start();
						break;
					default: printf("Error....!\n");
					}
				}
				else
				{
					strcpy(c.VID, checkVID);
					strcpy(c.name, checkName);
				}
			}
		}
		else
		{
			fp = fopen("pending_job.txt", "a+");
			if (fp == 0)
				fp = fopen("pending_job.txt", "w+");
			strcpy(c.VID, checkVID);
			strcpy(c.name, checkName);
		}
		printf("Enter the date\n");
		printf(": ");
		scanf("%s", &c.date);
		printf("\n");
		printf("Enter the month\n");
		printf(": ");
		scanf("%s", &c.month);
		printf("\n");
		printf("Enter the year\n");
		printf(": ");
		scanf("%s", &c.year);
		printf("\n");
		strcpy(c.service, "4");
		strcpy(c.days, "2");
		printf("Enter service type: 1 for normal or 2 for urgent\n");
		printf(": ");
		fflush(stdin);
		scanf("%d", &checkType);
		printf("\n");
		switch (checkType)
		{
		case 1:
		{
			strcpy(c.type, "normal");
			printf("The fee is 160RM\n");
			printf(": ");
			fflush(stdin);
			scanf("%d", &fee);
			if (fee > 160)
			{
				change = fee - 160;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "160");
			}
			else
			{
				outstanding = 160 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "160");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		case 2:
		{
			strcpy(c.type, "urgent");
			printf("The fee is 200RM\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &fee);
			if (fee > 200)
			{
				change = fee - 200;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "200");
			}
			else
			{
				outstanding = 200 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "200");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		default: printf("Error....!\n");
		}
	}
	break;
	case 5:
	{
		int fee, change, outstanding, pay;
		int checkType;
		char str[2];
		int ch;
		char checkVID[10];
		char checkName[100];
		FILE* fp;
		system("cls");
		fflush(stdin);
		printf("Enter Visitor ID \n");
		printf(": ");
		scanf("%s", &checkVID);
		printf("\n");
		printf("Enter customer name\n");
		printf(": ");
		scanf("%s", &checkName);
		printf("\n");
		if ((fp = fopen("pending_job.txt", "r+")) != NULL)
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				if (strcmp(c.VID, checkVID) == 0 || strcmp(c.name, checkName) == 0)
				{
					printf("The visitor id/customer name has been used\n\n");
					fflush(stdin);
					printf("Enter 1 to re-enter details or 2 to return to main menu\n");
					printf(": ");
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: Service();
						break;
					case 2: start();
						break;
					default: printf("Error....!\n");
					}
				}
				else
				{
					strcpy(c.VID, checkVID);
					strcpy(c.name, checkName);
				}
			}
		}
		else
		{
			fp = fopen("pending_job.txt", "a+");
			if (fp == 0)
				fp = fopen("pending_job.txt", "w+");
			strcpy(c.VID, checkVID);
			strcpy(c.name, checkName);
		}
		printf("Enter the date\n");
		printf(": ");
		scanf("%s", &c.date);
		printf("\n");
		printf("Enter the month\n");
		printf(": ");
		scanf("%s", &c.month);
		printf("\n");
		printf("Enter the year\n");
		printf(": ");
		scanf("%s", &c.year);
		printf("\n");
		strcpy(c.service, "5");
		strcpy(c.days, "1");
		printf("Enter service type: 1 for normal or 2 for urgent\n");
		printf(": ");
		fflush(stdin);
		scanf("%d", &checkType);
		printf("\n");
		switch (checkType)
		{
		case 1:
		{
			strcpy(c.type, "normal");
			printf("The fee is 180RM\n");
			printf(": ");
			fflush(stdin);
			scanf("%d", &fee);
			if (fee > 180)
			{
				change = fee - 180;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "180");
			}
			else
			{
				outstanding = 180 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "180");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		case 2:
		{
			strcpy(c.type, "urgent");
			printf("The fee is 210RM\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &fee);
			if (fee > 210)
			{
				change = fee - 210;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "210");
			}
			else
			{
				outstanding = 210 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "210");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		default: printf("Error....!\n");
		}
	}
	break;
	case 6:
	{
		int fee, change, outstanding, pay;
		int checkType;
		char str[2];
		int ch;
		char checkVID[10];
		char checkName[100];
		FILE* fp;
		system("cls");
		fflush(stdin);
		printf("Enter Visitor ID \n");
		printf(": ");
		scanf("%s", &checkVID);
		printf("\n");
		printf("Enter customer name\n");
		printf(": ");
		scanf("%s", &checkName);
		printf("\n");
		if ((fp = fopen("pending_job.txt", "r+")) != NULL)
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				if (strcmp(c.VID, checkVID) == 0 || strcmp(c.name, checkName) == 0)
				{
					printf("The visitor id/customer name has been used\n\n");
					fflush(stdin);
					printf("Enter 1 to re-enter details or 2 to return to main menu\n");
					printf(": ");
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: Service();
						break;
					case 2: start();
						break;
					default: printf("Error....!\n");
					}
				}
				else
				{
					strcpy(c.VID, checkVID);
					strcpy(c.name, checkName);
				}
			}
		}
		else
		{
			fp = fopen("pending_job.txt", "a+");
			if (fp == 0)
				fp = fopen("pending_job.txt", "w+");
			strcpy(c.VID, checkVID);
			strcpy(c.name, checkName);
		}
		printf("Enter the date\n");
		printf(": ");
		scanf("%s", &c.date);
		printf("\n");
		printf("Enter the month\n");
		printf(": ");
		scanf("%s", &c.month);
		printf("\n");
		printf("Enter the year\n");
		printf(": ");
		scanf("%s", &c.year);
		printf("\n");
		strcpy(c.service, "6");
		strcpy(c.days, "2");
		printf("Enter service type: 1 for normal or 2 for urgent\n");
		printf(": ");
		fflush(stdin);
		scanf("%d", &checkType);
		printf("\n");
		switch (checkType)
		{
		case 1:
		{
			strcpy(c.type, "normal");
			printf("The fee is 50RM\n");
			printf(": ");
			fflush(stdin);
			scanf("%d", &fee);
			if (fee > 50)
			{
				change = fee - 50;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "50");
			}
			else
			{
				outstanding = 50 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "50");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		case 2:
		{
			strcpy(c.type, "urgent");
			printf("The fee is 80RM\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &fee);
			if (fee > 80)
			{
				change = fee - 80;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "80");
			}
			else
			{
				outstanding = 80 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "80");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		default: printf("Error....!\n");
		}
	}
	break;
	case 7:
	{
		int fee, change, outstanding, pay;
		int checkType;
		char str[2];
		int ch;
		char checkVID[10];
		char checkName[100];
		FILE* fp;
		system("cls");
		fflush(stdin);
		printf("Enter Visitor ID \n");
		printf(": ");
		scanf("%s", &checkVID);
		printf("\n");
		printf("Enter customer name\n");
		printf(": ");
		scanf("%s", &checkName);
		printf("\n");
		if ((fp = fopen("pending_job.txt", "r+")) != NULL)
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				if (strcmp(c.VID, checkVID) == 0 || strcmp(c.name, checkName) == 0)
				{
					printf("The visitor id/customer name has been used\n\n");
					fflush(stdin);
					printf("Enter 1 to re-enter details or 2 to return to main menu\n");
					printf(": ");
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: Service();
						break;
					case 2: start();
						break;
					default: printf("Error....!\n");
					}
				}
				else
				{
					strcpy(c.VID, checkVID);
					strcpy(c.name, checkName);
				}
			}
		}
		else
		{
			fp = fopen("pending_job.txt", "a+");
			if (fp == 0)
				fp = fopen("pending_job.txt", "w+");
			strcpy(c.VID, checkVID);
			strcpy(c.name, checkName);
		}
		printf("Enter the date\n");
		printf(": ");
		scanf("%s", &c.date);
		printf("\n");
		printf("Enter the month\n");
		printf(": ");
		scanf("%s", &c.month);
		printf("\n");
		printf("Enter the year\n");
		printf(": ");
		scanf("%s", &c.year);
		printf("\n");
		strcpy(c.service, "7");
		strcpy(c.days, "2");
		printf("Enter service type: 1 for normal or 2 for urgent\n");
		printf(": ");
		fflush(stdin);
		scanf("%d", &checkType);
		printf("\n");
		switch (checkType)
		{
		case 1:
		{
			strcpy(c.type, "normal");
			printf("The fee is 100RM\n");
			printf(": ");
			fflush(stdin);
			scanf("%d", &fee);
			if (fee > 100)
			{
				change = fee - 100;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "100");
			}
			else
			{
				outstanding = 100 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "100");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		case 2:
		{
			strcpy(c.type, "urgent");
			printf("The fee is 150RM\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &fee);
			if (fee > 150)
			{
				change = fee - 150;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "150");
			}
			else
			{
				outstanding = 150 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "150");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		default: printf("Error....!\n");
		}
	}
	break;
	case 8:
	{
		int fee, change, outstanding, pay;
		int checkType;
		char str[2];
		int ch;
		char checkVID[10];
		char checkName[100];
		FILE* fp;
		system("cls");
		fflush(stdin);
		printf("Enter Visitor ID \n");
		printf(": ");
		scanf("%s", &checkVID);
		printf("\n");
		printf("Enter customer name\n");
		printf(": ");
		scanf("%s", &checkName);
		printf("\n");
		if ((fp = fopen("pending_job.txt", "r+")) != NULL)
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				if (strcmp(c.VID, checkVID) == 0 || strcmp(c.name, checkName) == 0)
				{
					printf("The visitor id/customer name has been used\n\n");
					fflush(stdin);
					printf("Enter 1 to re-enter details or 2 to return to main menu\n");
					printf(": ");
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: Service();
						break;
					case 2: start();
						break;
					default: printf("Error....!\n");
					}
				}
				else
				{
					strcpy(c.VID, checkVID);
					strcpy(c.name, checkName);
				}
			}
		}
		else
		{
			fp = fopen("pending_job.txt", "a+");
			if (fp == 0)
				fp = fopen("pending_job.txt", "w+");
			strcpy(c.VID, checkVID);
			strcpy(c.name, checkName);
		}
		printf("Enter the date\n");
		printf(": ");
		scanf("%s", &c.date);
		printf("\n");
		printf("Enter the month\n");
		printf(": ");
		scanf("%s", &c.month);
		printf("\n");
		printf("Enter the year\n");
		printf(": ");
		scanf("%s", &c.year);
		printf("\n");
		strcpy(c.service, "8");
		strcpy(c.days, "1");
		printf("Enter service type: 1 for normal or 2 for urgent\n");
		printf(": ");
		fflush(stdin);
		scanf("%d", &checkType);
		printf("\n");
		switch (checkType)
		{
		case 1:
		{
			strcpy(c.type, "normal");
			printf("The fee is 50RM\n");
			printf(": ");
			fflush(stdin);
			scanf("%d", &fee);
			if (fee > 50)
			{
				change = fee - 50;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "50");
			}
			else
			{
				outstanding = 50 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "50");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		case 2:
		{
			strcpy(c.type, "urgent");
			printf("The fee is 75RM\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &fee);
			if (fee > 75)
			{
				change = fee - 75;
				printf("Your change is RM%d, press any key to continue", change);
				_getch();
				strcpy(c.fee, "75");
			}
			else
			{
				outstanding = 75 - fee;
				while (outstanding > 0)
				{
					printf("You have %dRM outstanding, please complete payment to proceed\n", outstanding);
					printf(": ");
					scanf("%d", &pay);
					if (pay > outstanding)
					{
						change = pay - outstanding;
						printf("Your change is RM%d, press any key to continue", change);
						_getch();
						outstanding = 0;
					}
					else
						outstanding = outstanding - pay;
				}
				if (outstanding <= 0)
					strcpy(c.fee, "75");
			}
			fwrite(&c, sizeof(c), 1, fp);
			fclose(fp);
			system("cls");
			printf("Data sucessfully stored in the system \n\n");
			printf("Enter 1 to go back to main menu or 2 to exit\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1: start();
				break;
			case 2: exit(0);
				break;
			default: printf("Error...\n");
			}
		}
		break;
		default: printf("Error....!\n");
		}
	}
	break;
	case 9:
	{
		start();
	}
	break;
	case 10:
	{
		system("cls");
		int i;
		FILE* fp;
		fp = fopen("pending_job.txt", "r");
		if (fp == NULL)
		{
			printf("There are no visitor IDs registered\n\n");
			printf("Enter 1 to go back or 2 to go to main menu\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &i);
			switch (i)
			{
			case 1: Service();
				break;
			case 2: start();
				break;
			default: printf("Error....!\n");
			}
		}
		else
		{
			while (fread(&c, sizeof(c), 1, fp) == 1)
			{
				printf("Visitor ID: %s\n", c.VID);
			}
			fclose(fp);
			printf("\nEnter 1 to go back or 2 to go to main menu\n");
			printf(": ");
			fflush(stderr);
			scanf("%d", &i);
			switch (i)
			{
			case 1: Service();
				break;
			case 2: start();
				break;
			default: printf("Error....\n");
			}
		}
	}
	break;
	default: printf("Error....");
	}
}
//complete job
void Cjob()
{
	system("cls");
	int ch;
	char VID[5];
	char namec[100];
	FILE* fp;
	FILE* cp;
	FILE* tp;
	int flag = 0;
	printf("Enter Visitor ID\n");
	printf(": ");
	fflush(stderr);
	scanf("%s", &VID);
	fp = fopen("pending_job.txt", "r");
	tp = fopen("temp.txt", "w");
	while (fread(&c, sizeof(c), 1, fp) == 1)
	{
		if (strcmp(c.VID, VID) == 0)
		{
			cp = fopen("completed_work.txt", "a+");
			if (cp == 0)
				cp = fopen("completed_work.txt", "w+");
			flag = 1;
			fwrite(&c, sizeof(c), 1, cp);
			fclose(cp);
			continue;
		}
		else
		{
			fwrite(&c, sizeof(c), 1, tp);
		}
	}
	fclose(fp);
	fclose(tp);
	if (flag == 0)
	{
		printf("Data not found\n\n");
		printf("Enter 1 to return\n");
		printf(": ");
		fflush(stderr);
		scanf("%d", &ch);
		switch (ch)
		{
		case 1: start();
			break;
		default: printf("Error....\n");
		}
	}
	else
	{
		remove("pending_job.txt");
		rename("temp.txt", "pending_job.txt");
		printf("JOB COMPLETED\n\n");
	}
	printf("Enter 1 to return\n");
	printf(":");
	fflush(stderr);
	scanf("%d", &ch);
	switch (ch)
	{
	case 1: start();
		break;
	default: printf("Error....\n");
	}
}

void Edit()
{
	system("cls");
	FILE* fp;
	FILE* tp;
	int ch, flag = 0;
	char VID[5];
	char name[100];
	char date[2];
	char month[2];
	char year[4];
	long int size = sizeof(c);
	tp = fopen("temp.txt", "w+");
	fp = fopen("pending_job.txt", "r+");
	printf("Enter visitor id\n");
	printf(": ");
	scanf("%s", &VID);
	fflush(stderr);
	while (fread(&c, sizeof(c), 1, fp) == 1)
	{
		if (strcmp(c.VID, VID) == 0)
		{
			flag = 1;
			strcpy(name, c.name);
			strcpy(date, c.date);
			strcpy(month, c.month);
			strcpy(year, c.year);
			continue;
		}
		else
		{
			fwrite(&c, sizeof(c), 1, tp);
		}
	}
	if (flag == 0)
	{
		fclose(fp);
		fclose(tp);
		printf("NOT FOUND\n\n");
	}
	else
	{
		system("cls");
		printf("Enter the new details\n\n");
		fflush(stderr);
		strcpy(c.VID, VID);
		strcpy(c.name, name);
		strcpy(c.date, date);
		strcpy(c.month, month);
		strcpy(c.year, year);
		printf("NO               SERVICE TYPE                NEEDED DAYS            SERVICE FEE\n");
		printf("                                                                 NORMAL  |  URGENT\n");
		printf("1. Remove virus, malware or spyware            2 days             30RM       50RM\n");
		printf("2. Troubleshoot and fix computer running       2 days             40RM       70RM\n");
		printf("   slow\n");
		printf("3. Laptop screen replacement                   3 days             380RM      430RM\n");
		printf("4. Laptopn keyboard replacement                2 days             160RM      200RM\n");
		printf("5. Laptop battery replacement                  1 day              180RM      210RM\n");
		printf("6. Operating system format and installation    2 days             50RM       80RM\n");
		printf("7. Data backup and recovery                    2 days             100RM      150RM\n");
		printf("8. Internet connectivity issues                1 day              50RM       75RM\n\n");
		printf("Enter new service number\n");
		printf(": ");
		scanf("%s", &c.service);
		printf("\n");
		printf("Enter Service type\n");
		printf(": ");
		scanf("%s", &c.type);
		printf("\n");
		printf("Enter days needed\n");
		scanf("%s", &c.days);
		printf("\n");
		printf("Enter fees\n");
		scanf("%s", &c.fee);
		printf("\n");
		printf("\n");
		fseek(fp, size, SEEK_CUR);
		fwrite(&c, sizeof(c), 1, tp);
		fclose(fp);
		fclose(tp);
		remove("pending_job.txt");
		rename("temp.txt", "pending_job.txt");
		printf("Data Edited\n\n");
	}
	printf("Enter 1 to go back or 2 to go to main menu\n");
	printf(": ");
	fflush(stderr);
	scanf("%d", &ch);
	switch (ch)
	{
	case 1: Edit();
		break;
	case 2: start();
		break;
	default: printf("Error...\n");
	}
}
//view and search data
void ViewSearch()
{
	system("cls");
	int ch;
	int intPay, total = 0, flag = 0;
	char VID[5], visitName[100];
	printf("1. Current repair data\n");
	printf("2. Completed work data\n");
	printf("3. Main menu\n\n");
	printf("Enter the option: ");
	fflush(stderr);
	scanf("%d", &ch);
	switch (ch)
	{
	case 1:
	{
		printf("1. View all data\n");
		printf("2. View individual data\n\n");
		printf("Enter the option: ");
		fflush(stderr);
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
		{
			printf("1. Complete data\n");
			printf("2. Only payment data\n\n");
			printf("Enter the option: ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
			{
				FILE* fp;
				if ((fp = fopen("pending_job.txt", "r")) == NULL)
				{
					printf("NO DATA\n\n");
					printf("Enter 1 to go back\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
				else
				{
					system("cls");
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						printf("VISITOR ID:   %s\n", c.VID);
						printf("NAME:         %s\n", c.name);
						printf("DATE:         %s /%s /%s\n", c.date, c.month, c.year);
						printf("SERVICE NO.:  %s\n", c.service);
						printf("DAYS NEEDED:  %s\n", c.days);
						printf("SERVICE TYPE: %s\n", c.type);
						printf("FEE:          %sRM\n\n", c.fee);
					}
					fclose(fp);
					printf("Enter 1 to return\n");
					printf(": ");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
			}
			break;
			case 2:
			{
				FILE* fp;
				if ((fp = fopen("pending_job.txt", "r")) == NULL)
				{
					printf("NO DATA\n\n");
					printf("Enter 1 to go back\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
				else
				{
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						intPay = stringToInteger(c.fee);
						total = total + intPay;
					}
					printf("Total amount paid is %dRM\n\n", total);
					fclose(fp);
					printf("Enter 1 to return\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...!\n");
					}
				}
			}
			break;
			default: printf("Error...");
			}
		}
		break;
		case 2:
		{
			printf("1. Complete data\n");
			printf("2. Only payment data\n\n");
			printf("Enter the option: ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
			{
				FILE* fp;
				if ((fp = fopen("pending_job.txt", "r")) == NULL)
				{
					printf("NO DATA\n\n");
					printf("Enter 1 to go back\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
				else
				{
					printf("Enter visitor id\n");
					printf(": ");
					fflush(stderr);
					scanf("%s", &VID);
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						if (strcmp(c.VID, VID) == 0)
						{
							flag = 1;
							printf("\n\nVISITOR ID:   %s\n", c.VID);
							printf("NAME:         %s\n", c.name);
							printf("DATE:         %s /%s /%s\n", c.date, c.month, c.year);
							printf("SERVICE NO.:  %s\n", c.service);
							printf("DAYS NEEDED:  %s\n", c.days);
							printf("SERVICE TYPE: %s\n", c.type);
							printf("FEE:          %sRM\n\n", c.fee);
							break;
						}
					}
					if (flag == 0)
						printf("NO RECORD\n\n");
				}
				fclose(fp);
				printf("Enter 1 to return\n");
				printf(": ");
				fflush(stderr);
				scanf("%s", &ch);
				switch (ch)
				{
				case 1: start();
					break;
				default: printf("Error...!\n");
				}
			}
			break;
			case 2:
			{
				FILE* fp;
				if ((fp = fopen("pending_job.txt", "r")) == NULL)
				{
					//fclose(fp);
					printf("NO DATA\n\n");
					printf("Enter 1 to go back\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
				else
				{
					printf("Enter visitor id\n");
					printf(": ");
					fflush(stderr);
					scanf("%s", &VID);
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						if (strcmp(c.VID, VID) == 0)
						{
							flag = 1;
							printf("FEE:          %sRM\n\n", c.fee);
							break;
						}
					}
					if (flag == 0)
						printf("NO RECORD\n\n");
				}
				fclose(fp);
				printf("Enter 1 to return\n");
				printf(": ");
				fflush(stderr);
				scanf("%s", &ch);
				switch (ch)
				{
				case 1: start();
					break;
				default: printf("Error...!\n");
				}
			}
			break;
			default: printf("Error...");
			}
		}
		break;
		default: printf("Error...");
		}
	}
	break;
	case 2:
	{
		printf("1. View all data\n");
		printf("2. View individual data\n\n");
		printf("Enter the option: ");
		fflush(stderr);
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
		{
			printf("1. Complete data\n");
			printf("2. Only payment data\n\n");
			printf("Enter the option: ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
			{
				FILE* fp;
				if ((fp = fopen("completed_work.txt", "r")) == NULL)
				{
					printf("NO DATA\n\n");
					printf("Enter 1 to go back\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
				else
				{
					system("cls");
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						printf("VISITOR ID:   %s\n", c.VID);
						printf("NAME:         %s\n", c.name);
						printf("DATE:         %s /%s /%s\n", c.date, c.month, c.year);
						printf("SERVICE NO.:  %s\n", c.service);
						printf("DAYS NEEDED:  %s\n", c.days);
						printf("SERVICE TYPE: %s\n", c.type);
						printf("FEE:          %sRM\n\n", c.fee);
					}
					fclose(fp);
					printf("Enter 1 to return\n");
					printf(": ");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
			}
			break;
			case 2:
			{
				FILE* fp;
				if ((fp = fopen("completed_work.txt", "r")) == NULL)
				{
					//fclose(fp);
					printf("NO DATA\n\n");
					printf("Enter 1 to go back\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
				else
				{
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						intPay = stringToInteger(c.fee);
						total = total + intPay;
					}
					printf("Total amount paid is %dRM\n\n", total);
					fclose(fp);
					printf("Enter 1 to return\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...!\n");
					}
				}
			}
			break;
			default: printf("Error...");
			}
		}
		break;
		case 2:
		{
			printf("1. Complete data\n");
			printf("2. Only payment data\n\n");
			printf("Enter the option: ");
			fflush(stderr);
			scanf("%d", &ch);
			switch (ch)
			{
			case 1:
			{
				FILE* fp;
				if ((fp = fopen("completed_work.txt", "r")) == NULL)
				{
					printf("NO DATA\n\n");
					printf("Enter 1 to go back\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
				else
				{
					printf("Enter visitor name\n");
					printf(": ");
					fflush(stderr);
					scanf("%s", &visitName);
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						if (strcmp(c.name, visitName) == 0)
						{
							flag = 1;
							printf("\n\nVISITOR ID:   %s\n", c.VID);
							printf("NAME:         %s\n", c.name);
							printf("DATE:         %s /%s /%s\n", c.date, c.month, c.year);
							printf("SERVICE NO.:  %s\n", c.service);
							printf("DAYS NEEDED:  %s\n", c.days);
							printf("SERVICE TYPE: %s\n", c.type);
							printf("FEE:          %sRM\n\n", c.fee);
						}
					}
					if (flag == 0)
						printf("NO RECORD\n\n");
				}
				fclose(fp);
				printf("Enter 1 to return\n");
				printf(": ");
				fflush(stderr);
				scanf("%s", &ch);
				switch (ch)
				{
				case 1: start();
					break;
				default: printf("Error...!\n");
				}
			}
			break;
			case 2:
			{
				FILE* fp;
				if ((fp = fopen("completed_work.txt", "r")) == NULL)
				{
					printf("NO DATA\n\n");
					printf("Enter 1 to go back\n");
					fflush(stderr);
					scanf("%d", &ch);
					switch (ch)
					{
					case 1: start();
						break;
					default: printf("Error...\n");
					}
				}
				else
				{
					printf("Enter visitor name\n");
					printf(": ");
					fflush(stderr);
					scanf("%s", &visitName);
					while (fread(&c, sizeof(c), 1, fp) == 1)
					{
						if (strcmp(c.name, visitName) == 0)
						{
							flag = 1;
							intPay = stringToInteger(c.fee);
							total = total + intPay;
						}
					}
					if (flag == 1)
					{
						printf("Total amount paid is %dRM\n\n", total);
					}
					else
						printf("NO RECORD\n\n");
				}
				fclose(fp);
				printf("Enter 1 to return\n");
				printf(": ");
				fflush(stderr);
				scanf("%s", &ch);
				switch (ch)
				{
				case 1: start();
					break;
				default: printf("Error...!\n");
				}
			}
			break;
			default: printf("Error...");
			}
		}
		break;
		default: printf("Error...");
		}
	}
	break;
	case 3:start();
		break;
	default: printf("Error...");
	}
	
}
//delete data
void Remove()
{
	system("cls");
	int ch;
	char VID[5];
	char namec[100];
	FILE* fp;
	FILE* tp;
	int flag = 0;
	
	printf("Enter Visitor ID\n");
	printf(": ");
	fflush(stderr);
	scanf("%s", &VID);
	fp = fopen("pending_job.txt", "r");
	tp = fopen("temp.txt", "w");
	while (fread(&c, sizeof(c), 1, fp) == 1)
	{
		if (strcmp(c.VID, VID) == 0)
		{
			flag = 1;
			continue;
		}
		else
			fwrite(&c, sizeof(c), 1, tp);
	}
	fclose(fp);
	fclose(tp);
	if (flag == 0)
	{
		printf("NOT FOUND\n\n");
		printf("Enter 1 to return\n");
		printf(": ");
		fflush(stderr);
		scanf("%d", &ch);
		switch (ch)
		{
		case 1: start();
			break;
		default: printf("Error...\n");
		}
	}
	else
	{
		remove("pending_job.txt");
		rename("temp.txt", "pending_job.txt");
		printf("Data deleted\n\n");
	}
	printf("Enter 1 to return\n");
	printf(":");
	fflush(stderr);
	scanf("%d", &ch);
	switch (ch)
	{
	case 1: start();
		break;
	default: printf("Error...\n");
	}
}