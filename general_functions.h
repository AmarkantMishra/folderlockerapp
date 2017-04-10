#include "variables.h"

void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


void get_password(char* pass)
{
    char temp_passP[25];
    int i=0;
     while(1)
    {
            temp_passP[i]=getch();
            if(temp_passP[i]==13){break;}
            else if(temp_passP[i]==8)
            {
                if(i!=0) {
                printf("\b \b");
                i--;
                } else {printf("\a");}
            }
            else
            {
                printf("*");
                *(pass+i) = temp_passP[i];
                i++;
            }
             *(pass+i)='\0';
     }
}



void creditNclose(){
    system("cls");
    gotoxy(16,3);
    printf("Programmer....");
    gotoxy(16,6);
    printf("Amarkant Mishra");
    gotoxy(16,8);
    printf("Hi guys! This is Folder Locker Application in c++,");
    gotoxy(16,9);
    printf("I hope you like it & you can also set password");
    gotoxy(16,10);
    printf("& you can change also.");
    gotoxy(16,12);
    printf("Github: https://github.com/AmarkantMishra");
    gotoxy(16,14);
    printf("Exiting in 3 second...........>");
    gotoxy(16,18);
    Sleep(3000);
    exit(0);
}



void adminsignup(){

    char temp[10];
    login = fopen("password.dat","wb");
    gotoxy(10,10);
    printf("Enter password: ");
    get_password(password);
    gotoxy(10,11);
    printf("Re Enter Password: ");
    get_password(temp);
    while(strcmp(password,temp)!=0){
        gotoxy(10,10);
        printf("Password did not matched! Enter again");
        gotoxy(10,11);
        printf("Enter password: ");
        get_password(password);
        gotoxy(10,12);
        printf("Re Enter Password: ");
        get_password(temp);
        system("cls");
    }
    fwrite(&password,sizeof(password),1,login);
    fclose(login);
}

void adminsignin(){

    char temp[10];
    login = fopen("password.dat","rb");
    gotoxy(10,10);
    printf("Enter password: ");
    get_password(temp);
    while(fread(&password, sizeof(password),1,login)==1){
        while(strcmp(temp,password)!=0){
            system("cls");
            gotoxy(10,10);
            printf("Password did not match! ");
            printf("Enter Again: ");
            get_password(temp);
        }
        gotoxy(10,11);
        printf("Password Match");
        break;
    }
    fclose(login);
    gotoxy(10,12);
    printf("Press any key...");
    getch();
}


int change_password(){     //this for change the password
    system("cls");
    FILE *login;
    char old_pass[10], new_pass[10];
    gotoxy(10,10);
    printf("Enter Old password: ");
    get_password(old_pass);
    gotoxy(10,11);
    printf("Enter New password: ");
    get_password(new_pass);
    login = fopen("password.dat","rb+");
    while(fread(&password,sizeof(password),1,login)==1){
        if(strcmp(old_pass,password)==0){
            strcpy(password,new_pass);
            fseek(login,-sizeof(password),SEEK_CUR);
            fwrite(&password,sizeof(password),1,login);
            fclose(login);
            gotoxy(10,12);
            printf("Password successfully changed! ");
            return 1;
        }else{
            gotoxy(10,12);
            printf("Password changing process failed!");
            return 0;
        }

    }

}

void load(){
    int row,col,r,c,q;
    gotoxy(33,14);
    printf("  loading...");
    gotoxy(30,15);
    for(r=1;r<=20;r++){
    for(q=0;q<=100000000;q++);
    printf("%c",177);}
    //getch();   //for press enter after loading
}

