#include<stdio.h>
#include<string.h>
#include"conio2.h"
#include "car.h"
#include<time.h>
#include<stdlib.h>
#define BKSP 8

void addAdmin()
{
    FILE *fp=fopen("admin.bin","rb");
    if(fp==NULL)
    {
        fp=fopen("admin.bin","wb");
        User u[2]={{"admin","abc","Ashish"},{"Ayush","abc","Ayush singh"}};
        fwrite(u,sizeof(u),1,fp);
        fclose(fp);
        printf("File saved!");
        _getch();
    }
    else
    {
        fclose(fp);
    }
}
User*getInput()
{
    int i=0;
    clrscr();
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTAL SYSTAM\n");
    for(i=1;i<80;i++)
    printf("%c",247);
    gotoxy(32,5);
    printf("*LOGIN PANEL*");
    gotoxy(1,7);
    textcolor(LIGHTCYAN);
    for(i=1;i<80;i++)
        printf("%c",247);
    gotoxy(60,8);
    textcolor(WHITE);
    printf("Press 0 to exit");
    gotoxy(25,10);
    textcolor(LIGHTCYAN);
    printf("Enter user id:");
    fflush(stdin);
    textcolor(WHITE);
    static User usr;
    fgets(usr.userid,20,stdin);
    char *pos;
    pos=strchr(usr.userid,'\n');
    *pos='\0';
    if(strcmp(usr.userid,"0")==0)
    {

        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login Cancelled!");
        _getch();
        textcolor(YELLOW);
        return NULL;
    }
    gotoxy(25,11);
    textcolor(LIGHTCYAN);
    printf("Enter Password:");
    fflush(stdin);
    i=0;
    textcolor(WHITE);
    for(;;)
    {
        usr.pwd[i]=_getch();
        if(usr.pwd[i]==13)
        {
            break;
        }
        printf("*");
        i++;
    }
    usr.pwd[i]='\0';
    if(strcmp(usr.pwd,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(30,17);
        printf("Login cancelled!");
        _getch();
        textcolor(YELLOW);
        return NULL;
    }
    return &usr;
}

int checkUserExist(User u,char*usertype)
{
    if(strcmp(u.userid,"")==0 || strcmp(u.pwd,"")==0)
    {
        gotoxy(28,20);
        textcolor(LIGHTRED);
        printf("BOTH FILDS ARE MANADATORY");
        _getch();
        gotoxy(28,20);
        printf("\t\t\t\t\t\t\t\t\t");
        return 0;

    }
    int found=0;
    if(!(strcmp(usertype,"admin")))
    {
        FILE *fp=fopen("admin.bin","rb");
        User user;
        while(fread(&user,sizeof(User),1,fp)==1)
        {
            if(strcmp(u.userid,user.userid)==0 && strcmp(u.pwd,user.pwd)==0)
            {
                found=1;
                break;
            }
        }
        if(!found)
        {
            gotoxy(27,20);
            textcolor(LIGHTRED);
            printf("INVALID USERID OR PASSWORD");
            _getch();
            fclose(fp);
            return 0;
        }
        fclose(fp);
        return 1;

}
int adminMenu()
{
    int choice,i;
    textcolor(LIGHTRED);
    gotoxy(32,2);
    printf("CAR RENTEL SYSTEM");
    textcolor(LIGHTGREEN);


    gotoxy(35,6);
    printf("ADMIN MENU\n");
    for(i=0;i<80;i++);
    {
        printf("*");

    }
    textcolor(YELLOW);
    gotoxy(32,8);
    printf("1. Add Employee");
    gotoxy(32,9);
    printf("2. Car Details");
    gotoxy(32,10);
    printf("3. Show Employee");
    gotoxy(32,11);
    printf("4. Show Car details");
    gotoxy(32,12);
    printf("5. Delete Employee");
    gotoxy(32,13);
    printf("6. Delete Car Details");
    gotoxy(32,14);
    printf(" EXit");
    gotoxy(32,16);
    printf("Enter Choice");
    textcolor(WHITE);
    scanf("%d",&choice);
    return choice;

    }
void addEmployee()
{
    FILE *fp=fopen("emp.bin","rb");
    int id;
    char uchoice;
    char emp[10]="EMP-";
    char empid[10];
    User u,ur;
    if(fp==NULL)
    {
        fp=fopen("emp.bin","ab");
        id=1;
        sprintf(empid,"%d",id);
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcpy(emp,"EMP-");
    }
    else
    {
        fp=fopen("emp.bin","ab+");
        fseek(fp,-60,SEEK_END);
        fread(&ur,sizeof(ur),1,fp);
        char sub[3];
        char str[20];
        strcpy(str,ur.userid);
        sub_str(str,sub,'_');
        id=atoi(sub);
        id++;
        sprintf(empid,"%d",id);
        strcat(emp,empid);
        strcpy(u.userid,emp);
        strcmp(emp,"EMP-");

    }
    do
    {
      clrscr();
      gotoxy(32,2);
      textcolor(LIGHTRED);
      printf("CAR RENTEL APP");
      textcolor(LIGHTGREEN);
      int i;
      gotoxy(1,3);
      for(i=0;i<80;i++)
      {
          printf("~");
      }
      textcolor(WHITE);
      gotoxy(25,5);
      printf("***** ADD EMPLOYEE DETAILS*****");
      gotoxy(1,8);
      textcolor(YELLOW);
      printf("Enter Employee Name:");
      fflush(stdin);
      textcolor(WHITE);
      //fgets(u.name,'\n');
      char *pos;
      pos=str_chr(u.name,'\n');
      *pos='\0';

      textcolor(YELLOW);
      printf("Enter Employee Pwd");
      fflush(stdin);
      textcolor(WHITE);
      fgets(u.pwd,20,stdin);
      pos=strchr(u.pwd,'\n');
      *pos='\0';
      textcolor(YELLOW);
      fseek(fp,0,SEEK_END);
      fwrite(&u,sizeof(User),1,fp);
      gotoxy(30,15);
      textcolor(LIGHTGREEN);
      printf("EMPLOYEE ADD SUCCESSFULLY");
      printf("\n EMPLOYEE ID IS:%S",u.userid);
      _getch();
      gotoxy(1,20);
      textcolor(LIGHTRED);
      printf("Do YOU WANT TO ADD MORE EMPLOYEE(Y/N):");
      textcolor(WHITE);
      fflush(stdin);
      scanf("%c",&uchoice);
      id++;
      sprintf(empid,"%d",id);
      strcat(emp,empid);
      strcpy(u.userid,emp);
      strcpy(emp,"EMP-");
    }
    while(uchoice=='y' || uchoice=='y');
    fclose(fp);
 }
 void stb_str(char *str,char *sub,char c)
 {
     int i,f=0,j=0;
     for(i=0; str[i]!='\0'; i++)
     {
         sub[j]=str[i];
         j++;
     }
     sub[j]='0';
 }
 void viewEmpliyee()
{
    FILE *fp=fopen("emp.bin","rb");
    User ur;
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTEL SYSTEM\n");
    for(i=1;i<=80;i++)
        printf("%c",247);
    gotoxy(31,5);
    textcolor(YELLOW);
    printf("* EMPLOYEE DETAILS *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++);
    printf("%c",247);
    gotoxy(1,8);
    printf(" Employee ID\t\t\tName\t\t\tPassword");
    gotoxy(1,9);
    textcolor(LIGHTGREEN);
    for(i=1;i<80;i++)
    printf("%c",247);
    int x=10;
    textcolor(YELLOW);
    while(fread(&ur,sizeof(ur),1,fp)==1)
    {
        gotoxy(2,x);
        printf("%s",ur.userid);
        gotoxy(33,x);
        printf("%s",ur.name);
        gotoxy(57,x);
        printf("%s",ur.pwd);
        x++;
    }
    fclose(fp);
    _getch();
}
int deleteEmp()
{
    FILE *fp1=fopen("emp.bin","rb");
    char empid[10];
    int i;
    textcolor(YELLOW);
    gotoxy(32,1);
    printf("CAR RENTEL SYSTEM\n");
    for(i=1; i<=80;i++)
    printf("%c",247);
    gotoxy(29,5);
    textcolor(YELLOW);
    printf("* DELETE EMPLOYEE RECODE *");
    gotoxy(1,7);
    textcolor(LIGHTGREEN);
    for(i=1; i<=80;i++)
    printf("%c",247);
    gotoxy(1,12);
     for(i=1; i<=80;i++)
        printf("%c",247);
     if(fp==NULL)
     {
         textcolor(LIGHTRED);
         printf("\nNO Employee Added Yet!");
         return -1;
     }
     FILE *fp2=fopen("temp.bin","wb+");
     gotoxy(10,9);
     textcolor(YELLOW);
     printf("Enter Employee ID to delete the recode:");
     textcolor(WHITE);
     scanf("%s",empid);
     User U;
     int found=0;
     while(fread(&U,sizeof(U),1,fp1)==1)
     {
         if(strcmp(U.userid,empid)!=0)
         {
             fwrite(&U,sizeof(U),1,fp2);

         }
         else
         {
             found=1;
         }
     }
     fclose(fp1);
     if(found==1)
     {
         rewind(fp2);
         fp1=fopen("emp.bin","wb");
         while(fread(&U,sizeof(U),1,fp2)==1)
         {
             fwrite(&U,sizeof(U),1,fp1);

         }
         fclose(fp1);
     }
     fclose(fp2);
     remove("temp,bin");
     return found;

}


