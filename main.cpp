#include <iostream>
#include <fstream>
#include <windows.h>
#include "general_functions.h"
using namespace std;



void mainmenu();
void CompanyInfo();
void lockfolder();
void unlockfolder();
void setcolour(unsigned int colour);  //DECLARE OF TEXT BACKGROUND COLORS FUNCTION AND TEXT COLOERS

int main()

{

    printf("\n\n\n\n\n\n\n\n\n\n\t\t\tWELLCOME!");
    Sleep(1000);
    system("CLS");
    printf("\n\n\n\n\n\n\n\n\n\n\t\t<<---------------FOLDER LOCKER APP--------------->>");
    load();                   //for calling the function
    SetConsoleTitle("Folder Locker App");
	system("CLS");

    login = fopen("password.dat","rb");
    if(login == NULL){
            gotoxy(10,9);
        printf("Database Do not exits. Be an admin & Sign Up");
        adminsignup();
    }else{
        adminsignin();
    }
    mainmenu();  ///call your special program or main menu of your program
    return 0;

}



void mainmenu()
{

    char nm[30];
    system("CLS");
	unsigned int choice=0;
	SetConsoleTitle("Folder Lock");
	system("CLS");
	setcolour(12);  //FOR CALL THE TEXT BACKGROUND COLORS FOUNCTION (CALLING FUNCTION)  //IN BREACKET NO. ARE THEIR IT IS COLOERS
	cout << "\n\n\t\t\t" << "    > FOLDER LOCKER APP\n";
	setcolour(15);


	cout << "\n\n\t\t\t" << "MAIN MENU>\t\t\t\n\n";
	cout << "\t\t\t---------------------\n\n";
	cout << "\t\t\t1. - Lock Folder.\n\n";
	cout << "\t\t\t2. - Unlock Folder.\n\n";
	cout << "\t\t\t3. - Change Password.\n\n";
	cout << "\t\t\t4. - About & Exit.\n\n";
	cout << "\t\t\t---------------------  \n\n";

	cout << "\n\t\t\tEnter your choice: ";
	cin >> choice;

	switch (choice)
	{
	case 1: lockfolder(); break;
	case 2: unlockfolder(); break;
	case 3: change_password();
                printf("\n\tpress any key to continue....");
                getch(); break;

	case 4: CompanyInfo(); break;
	default: cout << "\n\t\tError. Unknown Option Entered. Quitting ....\n"; break;
	}

}








void setcolour(unsigned int colour)     //TEXT BACKGROUND COLORS FUNCTION AND TEXT COLOR
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(handle, colour);
}

void lockfolder()
{
	char pass[15]="";
	ofstream lfolder;
	char folder[200]={0};
	char tempfolder[200]={'0'};
	char attributes[50]={'0'};

	setcolour(13);

	cout << "\n\t\tEnter the complete path to the Folder: ";
	cin >> folder;

	strcpy(tempfolder, folder);

	strcat(folder, "\\Desktop.ini");

	lfolder.open(folder, ios::out);

	lfolder << "[.shellClassInfo]" << endl;
	lfolder << "CLSID = {63E23168-BFF7-4E87-A246-EF024425E4EC}" << endl;

	lfolder.close();

	strcpy(attributes, "attrib +h +s ");
	strcat(attributes, tempfolder);

	WinExec(attributes, NULL);

	lfolder.open("C:\\windows\\db.dat", ios::app);
	lfolder << "Folder Locked: " << tempfolder << endl;
	lfolder.close();

	cout << "\n\n\t\t" << tempfolder << " has been locked successfully!\n";
}

void unlockfolder()
{
	char folder[255];
	char tempfolder[255];
	char attributes[50];
	char del[50];
	ofstream lfolder;

	setcolour(14);

	cout << "\n\t\tEnter the complete path to the Folder: ";
	cin >> folder;

	strcpy(tempfolder, folder);

	strcat(folder, "\\Desktop.ini");

	strcpy(del, "del ");
	strcat(del, folder);
	system(del);

	strcpy(attributes, "attrib -h -s ");
	strcat(attributes, tempfolder);

	WinExec(attributes, NULL);

	lfolder.open("C:\\windows\\db.dat", ios::app);
	lfolder << "! Folder Unlocked: " << tempfolder << endl;
	lfolder.close();

	cout << "\n\n\t\t" << tempfolder << " has been unlocked successfully!\n";
}


void CompanyInfo()
{
    creditNclose();
    }

