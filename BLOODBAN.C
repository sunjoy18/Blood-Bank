/**BLOOD DONOR DATABASE**/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
#include<dos.h>
#define amt 300

FILE *fp;
long int size;
struct donor
{
char name[25];
int age;
char address1[30];
char address2[30];
char city[20];
char phn[11];
char bloodgrp[4];
char email[40];
int id;
};
struct donor b; //declaration of structure

void putdonor(); //store the data in file
void getdonor();  //display data
void donorbyid();
void donorbycity();
void calamt();    //calculate sum to be paid to donor
void menu();      //display menu
void creden();    //display credentials

void main()
{
int i;
i=1;
size=sizeof(b); //finding size of structure

clrscr();
while(i<=7)
{
printf("\n\n\n\n\n\n\n\n\t\t\t\t Initializing");
if(i<7)
{
delay(500);
clrscr();
delay(450);
}
i++;
}
delay(1000);
printf(".");
delay(1000);
printf(".");
delay(1000);
printf(".");
delay(1000);

clrscr();
menu();
getch();
}

void putdonor()
{
char a;
clrscr();
fp=fopen("BDONOR.DAT","wb+"); //opening a binary file
if(fp==NULL)
{
puts("Cannot Open File");
exit(0);
}
fseek(fp,0,SEEK_END); //putting the pointer at the end of the file
do
{
clrscr();
fflush(stdin);
printf("\n\tEnter Name : ");
gets(b.name);
printf("\n\tEnter Your Age : ");
scanf("%d",&b.age);
fflush(stdin);
printf("\n\tEnter Your Donor ID : ");
scanf("%d",&b.id);
printf("\n\tEnter Address Line 1 : ");
fflush(stdin);
gets(b.address1);
printf("\n\tEnter Address Line 2 : ");
gets(b.address2);
printf("\n\tEnter City : ");
gets(b.city);
printf("\n\tEnter Blood Group : ");
gets(b.bloodgrp);
printf("\n\tEnter Your 10 Digit Moblie Number : ");
scanf("%s",b.phn);
fflush(stdin);
printf("\n\tEnter Your Email : ");
scanf("%s",b.email);
fwrite(&b,size,1,fp);
printf("\n\tDo You Want To Add Another Data\n Enter(Y / N)");
fflush(stdin);
scanf("%c",&a);
}while(a=='Y'||a=='y');
fclose(fp);
clrscr();
menu();
}

void getdonor()
{
char bld[4];
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter The Blood Group : ");
scanf("%s",bld);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if(strcmp(b.bloodgrp,bld)==0) //matching the blood group required with the one's present in Database
{
clrscr();
printf("\n\tName : %s \n\tDonor Id : %d \n\tAge : %d \n\tAddress Line : %s \n\tAddress Line 2 : %s \n\tCity : %s \n\tPhone No : %s \n\tEmail : %s \n\tBlood Grouo : %s \n\n",b.name,b.id,b.age,b.address1,b.address2,b.city,b.phn,b.email,b.bloodgrp);
printf("\n\n\tSee More(Y/N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t No More Records Found......!!!");
printf("\n\nBack to Main Menu in 7 Seconds");
delay(7000);
fclose(fp);
menu();
}
}

void menu()
{
int choice;
clrscr();
printf("\n\n\t\t\tBLOOD DONOR DATABSE \n\n\n");
printf("\t1 Add a new entry\n\n");
printf("\t2 Search by Blood Group \n\n");
printf("\t3 Search by Donor Id\n\n");
printf("\t4 Search by City\n\n");
printf("\t5 Calculate the amount to be paid to Donor\n\n");
printf("\t6 Credentials\n\n");
printf("\t7 Exit the program\n\n");
printf("\t Your choice : ");


scanf("%d",&choice);
switch(choice)
{
case 1 : putdonor();
	 break;
case 2 : getdonor();
	 break;
case 3 : donorbyid();
	 break;
case 4 : donorbycity();
	 break;
case 5 : calamt();
	 break;
case 6 : creden();
	 break;
case 7 : exit();

default : clrscr();
	  printf("\n\n\t\tYou have entered wrong choce....!!!");
	  delay(4000);
	  menu();
}
}

void calamt()
{
float unit,sum;
clrscr();
printf("\n\n\tEnter the unit donated : ");
scanf("%f",&unit);
sum=unit*amt; //Calculating the amount to be paid
printf("\n\tAmount paid per unit = Rs.%d\n\n",amt);
printf("\n\tTotal Amount to be paid = Rs.%f\n",sum);
printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\nBack to Main Menu in 7 seconds");
delay(7000);
clrscr();
menu();
}

void creden()
{
clrscr();
printf("\n\n\t\t\t\tBLOOD DONOR DATABASE\n\n\n");
printf("\t\t\tTeacher Incharge : NIKITA MAANDWAL\n");
printf("\n\n\t\tTeam Lead : SANJAY GUPTA\n");
printf("\n\n\t\tTeam Members : \n");
printf("\n\t\t\tNISHA\n\t\t\tROSHNI\n");
printf("\t\t\tSANDEEP\n\t\t\tSHWETA\n");
printf("\n\n\nBack to Main Menu in 10 seconds");
delay(10000);
clrscr();
menu();
}

void donorbyid()
{
int id;
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter the Donor Id : ");
scanf("%d",&id);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if(b.id==id)
{
printf("\n\tName : %s \n\tdonor Id : %d \n\tAge : %d \n\tAddress Line 1 : %s \n\tCity : %s \n\tPhone No : %s \n\tEmail :%s \n\tBlood Group : %s \n\n",b.name,b.id,b.age,b.address1,b.address2,b.city,b.phn,b.email,b.bloodgrp);
printf("\n\n\tSee More(Y / N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t NO MORE RECORDS FOUND....!!!");
printf("\n\n Back to Main Menu in 7 seconds");
delay(7000);
fclose(fp);
menu();
}
}

void donorbycity()
{
char city[20];
char a='y';
clrscr();
fp=fopen("BDONOR.DAT","rb");
if(fp==NULL)
{
puts("Cannot Open File");
exit();
}
fflush(stdin);
printf("\n\tEnter the City : ");
scanf("%s",&city);
rewind(fp);

while(fread(&b,size,1,fp)==1)
{
if(a=='Y'||a=='y')
{
if((strcmp(b.city,city))==0) //Matching the Bloodgroup required with the one's present in Databse
{
printf("\n\tName : %s \n\tdonor Id : %d \n\tAge : %d \n\tAddress Line 1 : %s \n\tCity : %s \n\tPhone No : %s \n\tEmail :%s \n\tBlood Group : %s \n\n",b.name,b.id,b.age,b.address1,b.address2,b.city,b.phn,b.email,b.bloodgrp);
printf("\n\n\tSee More(Y /N)");
fflush(stdin);
scanf("%c",&a);
}
}
}
if(a=='n'||a=='N')
{
fclose(fp);
menu();
}
else
{
printf("\n\n\n\t\t NO MORE RECORDS FOUND....!!!");
printf("\n\n Back to Main Menu in 7 seconds");
delay(7000);
fclose(fp);
menu();
}
}

//floating point Emulator
void linkfloat()
{
float a=0,*b;
b=&a;
a=*b;
}
