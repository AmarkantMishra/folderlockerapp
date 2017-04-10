#include<stdio.h>
#include<conio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>




FILE *login;
//list of global variable
char password[10];  //those are variable that public for all programs, functions etc..... and this known as global variable

COORD coord = {0, 0};

void mainmenu(void);  //for main menu   //FOR MAIN MENU THAT SECURE BY PASSWORD
void load();
void Password();  //for password
void get_password(char *);  //for get password
void creditNclose();  //for credit goes to (for make this application)
void adminsignup();  //for admin sign up (1st user only 1st use)
