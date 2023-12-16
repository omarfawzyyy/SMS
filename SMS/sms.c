#include<conio.h>  //getch
#include<stdio.h>
#include<process.h>
#include<stdlib.h> //system exit


struct student
{
 int rollno;
 char name[30];
 int O_marks,T_marks,M_marks,SC_marks,A_marks;
 float per;
 char grade;
 int std;
}st;

 FILE *fptr;
 
void write_student()
   {
	system("cls");
    fptr=fopen("student.txt","ab");
    printf("\nPlease Enter The New Details of student \n");
    printf("\nEnter The roll number of student ");
    scanf("%d",&st.rollno);
	//fprintf(fptr,"\n\n The roll number of student: %d ",st.rollno);
    fflush(stdin);
    printf("\n\nEnter The Name of student ");
    scanf("%s",&st.name);
	//fprintf(fptr,"\n\n The Name of student: %s ",st.name);
    printf("\nEnter The marks in orbital out of 100 : ");
    scanf("%d",&st.O_marks);
	//fprintf(fptr,"\n\n the marks in orbital out of 100: %d ",st.O_marks);
    printf("\nEnter The marks in thermo out of 100 : ");
    scanf("%d",&st.T_marks);
	//fprintf(fptr,"\n\n the marks in thermo out of 100: %d ",st.T_marks);
    printf("\nEnter The marks in maths out of 100 : ");
    scanf("%d",&st.M_marks);
	//fprintf(fptr,"\n\n the marks in math out of 100: %d ",st.M_marks);
    printf("\nEnter The marks in space science out of 100 : ");
    scanf("%d",&st.SC_marks);
	//fprintf(fptr,"\n\n the marks in space science out of 100: %d ",st.SC_marks);
    printf("\nEnter The marks in aero out of 100 : ");
    scanf("%d",&st.A_marks);
	//fprintf(fptr,"\n\n the marks in aero out of 100: %d ",st.A_marks);
    st.per=(st.O_marks+st.T_marks+st.M_marks+st.SC_marks+st.A_marks)/5.0;
    if(st.per>=85)
       st.grade='A';
    else if(st.per>=75 &&st.per<85)
      st.grade='B';
    else if(st.per>=60 &&st.per<75)
      st.grade='C';
    else
     st.grade='F';
    
	fwrite(&st,sizeof(st),1,fptr);
    fclose(fptr);
    printf("\n\nStudent Record Has Been Created ");
    getch();
}








void display_all()
{
	
    system("cls");
    printf("\n\n\n\t\tDISPLAY ALL RECORD !!!\n\n");
    fptr=fopen("student.txt","rb");
	
    while((fread(&st,sizeof(st),1,fptr))>0){
      printf("\nRoll Number of Student : %d",st.rollno);
      printf("\nName of student : %s",st.name);
      printf("\nMarks in orbital : %d",st.O_marks);
      printf("\nMarks in thermo : %d",st.T_marks);
      printf("\nMarks in math : %d",st.M_marks);
      printf("\nMarks in space science : %d",st.SC_marks);
      printf("\nMarks in aero : %d",st.A_marks);
      printf("\nPercentage of student is  : %.2f",st.per);
      printf("\nGrade of student is : %c",st.grade);
      printf("\n\n====================================\n");
      getch();
    }
    fclose(fptr);
    getch();
}








void search_student()
{
	     int num, flag=0;
		
	 
           system("cls");
           printf("\n\n\tPlease Enter The roll number: ");
           scanf("%d",&num);
    fptr=fopen("student.txt","r");
    while((fread(&st,sizeof(st),1,fptr))>0)
	{
     if(st.rollno==num)
        {
         system("cls");
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in Physics : %d",st.O_marks);
            printf("\nMarks in Chemistry : %d",st.T_marks);
            printf("\nMarks in Maths : %d",st.M_marks);
            printf("\nMarks in English : %d",st.SC_marks);
            printf("\nMarks in Computer Science : %d",st.A_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
			flag=1;
        }
    }
    fclose(fptr);
	if(flag==0)
 printf("\n\n\tRecord not exist");
    getch();
}









void modify_student()
{
    	int num, found=0;
	
    system("cls");
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The roll number of student: ");
    scanf("%d",&num);
    fptr=fopen("student.txt","rb+");
    
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
	{
    if(st.rollno==num)
           {
            printf("\nRoll number of student : %d",st.rollno);
            printf("\nName of student : %s",st.name);
            printf("\nMarks in orbital : %d",st.O_marks);
            printf("\nMarks in thermo : %d",st.T_marks);
            printf("\nMarks in math : %d",st.M_marks);
            printf("\nMarks in space science : %d",st.SC_marks);
            printf("\nMarks in aero : %d",st.A_marks);
            printf("\nPercentage of student is  : %.2f",st.per);
            printf("\nGrade of student is : %c",st.grade);
            printf("\n\nPlease Enter The New Details of student \n");
            printf("\nEnter The roll number of student: ");
            scanf("%d",&st.rollno);
            fflush(stdin);
            printf("\n\nEnter The Name of student ");
            scanf("%s",&st.name);
            printf("\nEnter The marks in orbital out of 100 : ");
            scanf("%d",&st.O_marks);
            printf("\nEnter The marks in thermo out of 100 : ");
            scanf("%d",&st.T_marks);
            printf("\nEnter The marks in math out of 100 : ");
            scanf("%d",&st.M_marks);
            printf("\nEnter The marks in space science out of 100 : ");
            scanf("%d",&st.SC_marks);
            printf("\nEnter The marks in aero out of 100 : ");
            scanf("%d",&st.A_marks);
            st.per=(st.O_marks+st.T_marks+st.M_marks+st.SC_marks+st.A_marks)/5.0;
            if(st.per>=85)
               st.grade='A';
            else if(st.per>=75 && st.per<85)
               st.grade='B';
            else if(st.per>=60 && st.per<75)
               st.grade='C';
            else
               st.grade='F';
            fseek(fptr,(double)sizeof(st),1);
            fwrite(&st,sizeof(st),1,fptr);
            printf("\n\n\t Record Updated");
        	 found=1;
    
           }
	}    
    fclose(fptr);
	if (found==0)
    printf("\n\n Record Not Found ");
    getch();
}





void delete_student()
   {
    int num;
    FILE *fptr2;
    system("cls");
    printf("\n\n\n\tDelete Record");
    printf("\n\nPlease Enter The roll number of student You Want To Delete");
    scanf("%d",&num);
    fptr=fopen("student.txt","rb");

    fptr2=fopen("Temp.txt","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(st.rollno!=num)
       {
      fwrite(&st,sizeof(st),1,fptr2);
	  printf("\n\n\tRecord Not Found ..");
	  exit(0);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.txt");
    rename("Temp.txt","student.txt");
    printf("\n\n\tRecord Deleted ..");
    getch();
   }
   


    void sheet_result()
    {
    system("cls");
     fptr=fopen("student.txt","rb");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

     printf("\n\n\t\tALL STUDENTS RESULT \n\n");
      printf("====================================================\n");
      printf("R.No.  Name       O   T   M   SC   A  per   Grade  \n");
      printf("====================================================\n");
     while((fread(&st,sizeof(st),1,fptr))>0){
       printf("%-6d %-10s %-3d %-3d %-3d %-3d %-3d %-3.2f  %-1c\n",st.rollno,st.name,st.O_marks,st.T_marks,st.M_marks,st.SC_marks,st.A_marks,st.per,st.grade);
     }
     fclose(fptr);
     getch();
}






void entry_menu()
{
    char ch;
  
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY ALL STUDENTS RECORDS");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch=getche();
  switch(ch)
  {
    case '1': write_student()	;break;
    case '2': display_all()		;break;
    case '3': search_student()		;break;
    case '4': modify_student()	;break;
    case '5': delete_student()	;break;
    case '6': 					 break;
    default:printf("\a");entry_menu();
   }
}




void main()
{
  char ch;
  
  do
    {
      system("cls");
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. Sheet of result");
      printf("\n\n\t02. ENTRY/EDIT MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
		{
         case '1' :  system("cls");
               sheet_result();
                break;
			   
         case '2' :  system("cls");
		       entry_menu();
				break;
         case '3' :  system("cls");
				exit(0);
					
          default :printf("\n\n\tPlease Enter num from (1-3) ");
		}
    }while(ch!= '3');
}
