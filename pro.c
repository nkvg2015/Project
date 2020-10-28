#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<stdlib.h>
#include<windows.h>

int main_function();               // control directly to main function
int page_1();                     // color changes at page 1
int all_password();              //   password related information
int enter_new_password();       // changing new password
int enter_admin();             // entering to admin after entering correct password
int add_new_medicine();       // adding new medicine in stock
int see_all_codes();         // see all the medicines codes at same time
int add_qty();              // adding new stock to medicine
int search_by_code();      // you can search with code
int delete_medicine();    // stock over delete medicine name
int purchase();         // user purchasing stock reducing
int modify_modify();
int going_to_get_code();
int settings();
int checking_stock();

char choice;
int i=0,f,c,e_code;

struct record
{
	int code,price,qty,total;
	char name[20];
}r;
struct pur_record
{
  	int code,price,qty,total;
	char name[20];
}k;
struct password
{
char password[20];
}p;
struct supply_info
{
	int code,price,qty,total,md,mm,my,ed,em,ey,year,month,date,hour,min,sec;
	char name[20],comp_name[20],mo[10],s_name[21];
}si;
// **********************************      main body          *************************/
int main()
{	system("color fc");
	page_1();
    main_function();
}
int main_function()
{
	do
	{	system("cls");
	printf("\n   1. See all the codes\n");
	printf("   2. To Buy the medicines  \n");
	printf("   3. Administrater\n");
	printf("   4. Exit \n");
	printf("   Please enter your choice here: \n");
	c=getche();	
    switch(c)
	    {
	    	case '1':see_all_codes();
			       break;
	    	case '2':purchase();
	    	       break;
	    	case '3':all_password();
				   break;       
	    	case '4':exit(0);
	    	default:system("cls");
			       printf("!!!!!!   PLEASE ENTER VALID CHOICE   !!!!!!\n         Press Any key to Continue");
			       getche();
		}
	}while(c!='4');
}
int purchase()
{	int sub,total,f=0;
    static int al_total=0;
    	                  
   FILE *fp,*fs,*fr;
          system("cls");
	fp=fopen("medicine_record.txt","r");
    printf("Enter code to purchase for:\n");
               e_again:
	scanf("%d",&e_code);
           if(e_code<=-1)
			   { 
			     system("cls");
				 printf("\n\nInvalid Code\nEnter the Code Again");
			     goto e_again;
				}    	
   fs=fopen("temp.txt","w");                        // for writing in temporary file
   fr=fopen("current_purchase.txt","a");
   while(fread(&r,sizeof(r),1,fp))
	{
		if(e_code==r.code)
	    {
	    print();
		printf("Enter Quantity to Purchase\n");
		 again:
	    scanf("%d",&sub);
	    if(sub<=0)
			   { 
			     system("cls");
				 printf("\n\nYou Cannot enter Negative Value\nEnter the Quantity Again");
			     goto again;
				}
		total=r.price*sub; 
	    al_total=al_total+total;
		r.qty=r.qty-sub;
	    f=1;
	    k.code=r.code;
	    strcpy(k.name,r.name);
	    k.price=r.price;
	    k.qty=sub;
	    k.total=total;
	    fwrite(&k,sizeof(k),1,fr);
	    fwrite(&r,sizeof(r),1,fs);
	    }
	    else 
	    {
	    	fwrite(&r,sizeof(r),1,fs);
		}
	}
	fclose(fs);
    fclose(fp);
    fclose(fr);
fout.remove("medicine_record.txt");
rename("temp.txt","medicine_record.txt");
remove("temp.txt");
	if(f==1)
	{      
     printf("\n\n**************************\n");
     printf("\nYour Total Amount is:%d",total);
     printf("\n**************************");
	}
	else
	  {
	  printf("\nCode Not found\n");	
	  }
  printf("\nDo you want anything else(y/Y): ");                       // asking for choice for more purchase
    choice=getche();
    system("cls");
         if(choice=='y' || choice=='Y')
            purchase();
         else
           {
           	FILE *fp;                                              //     file for billing payment
           	fp=fopen("current_purchase.txt","r");
           	printf("Code: \t\t Price:        Quantity:    \t Amount");
	        printf("\n*********************************************************************\n");
           	 while(fread(&k,sizeof(k),1,fp))
           	  {
               printf("Name:%s \n",k.name);
	             if(k.code<10 && k.code>0)
		            printf("00%d \t\t %d \t\t %d\t\t   %d Rs.",k.code,k.price,k.qty,k.total);
		         if(k.code<100 && k.code>=10)
		            printf("0%d \t\t %d \t\t %d\t\t   %d Rs.",k.code,k.price,k.qty,k.total);
		         if(k.code<1000 && k.code>=100)
		            printf("%d \t\t %d \t\t %d\t\t   %d Rs.",k.code,k.price,k.qty,k.total);
		         else{	}
		            printf("\n================================================================\n");
			 }
			printf("Your total amount is:                              %d Rs.",al_total);
			fclose(fp);
			getche();
			system("cls");
           	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t    Thank You\n");
           	printf("\n\n\t\t\t\t\t\t\t Please Visit Again");
		   }	
remove("current_purchase.txt");
al_total=0; 		      
}
int print()
{
	    system("cls");
	    printf("Your Searched Record conatins:\n");
		printf("Code: %d\n",r.code);
		printf("Name: %s\n",r.name);
		printf("Price: %d\n",r.price);
		printf("Quantity: %d\n\n",r.qty);
}
page_1()
{   
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("                                                ************************************\n\n");
	printf("                                                             Welcome To \n\n");
	printf("\n                                                 Medicine Record Management System");
	printf("\n\n\n                                                 By: Navneet Kumar");
	printf("\n                                                 Submitted To: Mr. Gurpreet");
	printf("\n                                                ************************************\n");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	sleep(4);
	printf("\nPress any key to continue\n");
	getch();
}
int all_password()
{
	enter_admin();                                   // enter_admin is here
	system("cls");
	do
	{   system("cls");
	printf("\n Welcome To Administrative Deparment");
	printf("\n 0. Settings");
	printf("\n 1. To Add New Medicine");
	printf("\n 2. To Add the Medicine Quantity");
	printf("\n 3. To Modify the medicine");
	printf("\n 4. To search by code");
	printf("\n 5. To modify your password");
	printf("\n 6. To see all codes");
	printf("\n 7. To Delete the Medicine");
	printf("\n 8. Log Out ");
	printf("\n 9. To EXIT \n");
	printf("Please Enter your choice: ");
	c=getche();	
	   switch(c)
	    {
	    	case '0':settings();
	    	       break;
	    	case '1':add_new_medicine();                             //  done 1
			       break;
	    	case '2':add_qty();                              //   done  2
			       break;
	    	case '3':modify_modify();
			       break;
	    	case '4':search_by_code();                         //done  4
			       break;
	    	case '5':enter_new_password();                           //done 5
	    	       break;
	    	case '6':see_all_codes();                                 // done 6
                   break;
			case '7':delete_medicine();                             // done  7
			       break;
			case '8':main_function();     // done 8
			       break;	   	      	    	
	    	case '9':exit(0);
		}
    }while(c!=9);
}
          //****************************     FUNCTIONS DEFINATIONS      ****************************************
int settings()
{
	do
	{   system("cls");
	printf("\n Welcome To Settings");
	printf("\n1. View Supplier\'s information");
	printf("\n2. For checking stock");
	printf("\n8. Log Out ");
	printf("\n9. To EXIT \n");
	printf("Please Enter the Valid Choice: ");
	c=getche();	
	   switch(c)
	    {
	    	case '1':supply_info();
			         break;
			case '2':checking_stock();
			         break;         
			case '8':main_function();		   	      	    	
	    	case '9':exit(0);
		}
    }while(c!=9);
}
int supply_info()
{
	system("cls");
	FILE *fs;
	fs=fopen("supplier_info.txt","r");
	while(fread(&si,sizeof(si),1,fs))
	 {
	 	printf("\nSupplier company name: %s",si.comp_name);
	 //	printf("\nSupplier name: %s",si.s_name);
	 	printf("\nMedicine Name: %s",si.name);
	 	printf("\nSupplier mobile number: %s",si.mo);
	 	printf("\nDate of manufacture: %d-%d-%d",si.md,si.mm,si.my);
	 	printf("\nDate of expiry: %d-%d-%d",si.ed,si.em,si.ey);
	 	printf("\nQuantity added: %d",si.qty);
	 	printf("\nUnit Price: %d",si.price);
	 	printf("\n Total amount: %d",si.total);
	 	printf("\nRecorded at: %d-%d-%d",si.date,si.month,si.year);
	 	printf("\nTime: %d:%d:%d",si.hour,si.min,si.sec);
	 	printf("\n==================================");
	 }
	fclose(fs); 
	printf("\nPress any key continue\n"); 
	getche(); 
}
int checking_stock()
{ 
    int en_no,k=0;
	printf("\n\nEnter the least quantity to see the name of medicine having least quantity: ");
	  scanf("%d",&en_no);
	  FILE *fp;
	  fp=fopen("medicine_record.txt","r");
	  printf("\n\nCode: \t\t Price:        Quantity:");
	  printf("\n*****************************************\n");
	  while(fread(&r,sizeof(r),1,fp))
	   {
	      if(r.qty<en_no)
	         {
	         //	printf("Code:%d      Name:%s      Quantity:%d     Price:%d\n",r.code,r.name,r.qty,r.price);
	         printf("Name:%s \n",r.name);
	         if(r.code<10 && r.code>0)
	      	 printf("00%d \t\t %d \t\t %d\t\t ",r.code,r.price,r.qty);
		     if(r.code<100 && r.code>=10)
	       	 printf("0%d \t\t %d \t\t %d\t\t ",r.code,r.price,r.qty);
		     if(r.code<1000 && r.code>=100)
		     printf("%d \t\t %d \t\t %d\t\t ",r.code,r.price,r.qty);
	     	 else{	}
		     printf("\n=========================================\n");
			    k++;
			 }	 
	   }
	 fclose(fp);     
	 if(k==0)
	   printf("\nNo Record to show\n");  
   printf("\nEnter any key to continue:\n");
	getche();   
}
int add_new_medicine()                                
{
	FILE *fp,*fs;
	fp=fopen("medicine_record.txt","a");
	fs=fopen("supplier_info.txt","a");
	
	going_to_get_code();             
//	printf("Enter Supplier name:\n");
	 gets(si.s_name);                                     
	printf("Enter company name\n");
	 gets(si.comp_name); 
	printf("Enter the Name of Medicine: ");
	scanf("%s",&r.name);
	printf("Enter the Price of Medicine: ");
	         a_price:
	scanf("%d",&r.price);
	  if(r.price<0)
	    {
	    	printf("\nCan not enter negative price\n Enter new price again\n");
	    	 goto a_price;
		}
	printf("Enter the Quantity of Medicine: ");
	       a_qty:
	scanf("%d",&r.qty);
	   if(r.qty<0)
	    {
	    	printf("\nCan not enter negative Quantity\n Enter new Quantity again\n");
	    	 goto a_qty;
		}
	si.code=r.code;
	strcpy(si.name,r.name);
	si.price=r.price;
	si.qty=r.qty;
	printf("Enter the date of manufacture: ");
	     	scanf("%d",&si.md);
	printf("Enter the month of manufacture: ");     	
			scanf("%d",&si.mm);
	printf("Enter the year of manufacture: ");		
			scanf("%d",&si.my);    
	   printf("Enter the date of Expiry: ");
    	scanf("%d",&si.ed);
	   printf("Enter the month of Expiry: ");
    	scanf("%d",&si.em);
	   printf("Enter the year of Expiry: ");
	    scanf("%d",&si.ey);
	printf("Enter Supplier mobile number:\n");
	  scanf("%s",si.mo); 
	si.total=si.price*si.qty;
	 system("cls");
	printf("Verify Your Information:\n");
 	    printf("\nSupplier company name %s",si.comp_name);
	 	//printf("\nSupplier name: %s",si.s_name);
	 	printf("\nMedicine Name: %s",si.name);
	 	printf("\nSupplier mobile number: %s",si.mo);
	 	printf("\nDate of manufacture:- %d:%d:%d",si.md,si.mm,si.my);
	 	printf("\nDate of expiry:- %d:%d:%d",si.ed,si.em,si.ey);
	 	printf("\nQuantity added: %d",si.qty);
	 	printf("\nUnit Price: %d ",si.price);
	 	printf("\n Total amount: %d",si.total);
	 	printf("\n==================================\n");
	printf("Would You like to save the Record(y|Y): \n");
	choice=getche(); 
	 if(choice=='Y' || choice=='y')
	   {
	   	SYSTEMTIME str_t;
	GetSystemTime(&str_t);
	   si.year=str_t.wYear;
	si.month=str_t.wMonth;
	si.date=str_t.wDay;
	si.hour=str_t.wHour+5;
	si.min=str_t.wMinute+30;
	si.sec=str_t.wSecond; 
	   	fwrite(&si,sizeof(si),1,fs);
	   	fwrite(&r,sizeof(r),1,fp);
	   	printf("\nRecord Saved Succesfully\n ");
	   }
	 else
	  printf("\nRecord not saved\n");  
	fclose(fp);	
	fclose(fs);
	printf("Press any key to continue\n");
	getche();
}
int going_to_get_code()
{   f=0;
    nav:
	printf("\n\n\nEnter the medicine code : ");
	   e_again:
	scanf("%d",&e_code);
	  if(e_code<0)
	    {   system("cls"); 
		    printf("\n   Invalid code \nEnter another code");
	    	goto e_again;
		}
    	FILE *fp;
   	    fp=fopen("medicine_record.txt","r");
	while(fread(&r,sizeof(r),1,fp))
	{
		if(e_code==r.code)
	    { f=1;	  break;	}
	    else { }
	}
	fclose(fp);
	if(f==1)
	{		system("cls");
		printf("********     ERROR     ********\n");
	printf("Duplicate code......\nPress enter key to continue");
	  getche();
    going_to_get_code();
	}
	else
	r.code=e_code;
}
int add_qty()                                               
{   
    int add;
    printf("\nEnter code to search for:\n");
	scanf("%d",&e_code);
	FILE *fp,*fs;
	fp=fopen("medicine_record.txt","r");
	fs=fopen("temp.txt","w");
   while(fread(&r,sizeof(r),1,fp))
	{
		if(e_code==r.code)
	    {
		printf("\nEnter Quantity of medicine to add\n");
	    scanf("%d",&add); 
	    r.qty=r.qty+add;
	    fwrite(&r,sizeof(r),1,fs);
		}
	    else 
		fwrite(&r,sizeof(r),1,fs);
	}
    fclose(fs);
    fclose(fp);
   printf("Your Medicine added Successfully:");
   printf("\nEnter any key to continue:\n");
   getche(); 
remove("medicine_record.txt");
rename("temp.txt","medicine_record.txt");
remove("temp.txt");
}
int modify_modify()
{
	int add;
    printf("\n Enter code to modify:\n");
	scanf("%d",&e_code);
	FILE *fp,*fs;
	fp=fopen("medicine_record.txt","r");
	fs=fopen("temp.txt","w");
   while(fread(&r,sizeof(r),1,fp))
	{
		if(e_code==r.code)
	    { 
	    printf("\nAre you Sure, to modify the medicine record:(y/Y)\n");
	    scanf("%s",&choice);
	      if(choice=='y' || choice=='Y')    // nested if here
	        {
			do
			  {  system("cls");
	    	      printf("1. Name:  %s\n",r.name);
	    	      printf("2. Price: %d \n",r.price);
	    	      printf("3. Stock: %d\n",r.qty);
	    	      printf("4. Exit \n");
	    	      printf("\nEnter choice to modify:\n");
	    	       c=getch();	
	             switch(c)
	              {
	    	        case '1':printf("Enter new Name\n");
	    	               scanf("%s",&r.name);
			               break;
	    	        case '2':printf("Enter new Price\n");
	    	               scanf("%d",&r.price);//all_password();
	    	               break;
	    	        case '3':printf("Enter new Quantity\n");
	    	               scanf("%d",&r.qty);
				           break;       
	    	        case '4':break;
	            	default:printf("\nPlaeas Enter Valid Choice\n");       
		           }
	         }while(c!='4');
			}
	      else            // nested else
	        { }
		fwrite(&r,sizeof(r),1,fs);
		}
	else 
		fwrite(&r,sizeof(r),1,fs);
	}
    fclose(fs);
    fclose(fp);
    printf("Your Record Modified Successfully:");
   printf("\nEnter any key to continue:\n");
   getche();
remove("medicine_record.txt");
rename("temp.txt","medicine_record.txt");
remove("temp.txt");
}
int enter_new_password()
{
    printf("\nEnter Your Password:\n");
    FILE *fp;
	fp=fopen("pass.txt","w");
	while((c = getch()) != 13)
   {
       if(i < 0)
           i = 0;
       if(c == 8)                      /* 8 is ASCII value of BACKSPACE character */
	   {  putch('\b');
           putch(NULL);
           putch('\b');
           i--;
       continue;
       }
       p.password[i++] = c;
       putch('*');
   }
   p.password[i] = '\0';
     printf("\nDo you like to see your password(y/Y):");
       choice=getche();
     if(choice=='y' || choice=='Y')  
	    printf("\nYour password is: %s\n",p.password);
	    printf("\n Press any key to continue\n");
          getche();  
	   fwrite(&p,sizeof(p),1,fp);
	fclose(fp);	
}  
int search_by_code()
{
	printf("\nEnter code to search:\n");
	scanf("%d",&e_code);
	FILE *fp;
	fp=fopen("medicine_record.txt","r");
	while(fread(&r,sizeof(r),1,fp))
	{
		if(e_code==r.code)
	    {  f=1;   break;  }
	    else
	      f=0;  
	}
	if(f==1)
		printf("Code:%d\nPrice:%d \nName:%s \nQuantity:%d",r.code,r.price,r.name,r.qty);
	else
	    printf("\nNo Record Found\n");	
	fclose(fp);
}
int enter_admin()
{	int i=0,f=0,c;
	char e_pass[20];
    FILE *fp;
	fp=fopen("pass.txt","r");
	fread(&p,sizeof(p),1,fp);
	fclose(fp);
	system("cls");
    printf("\nEnter Login Password:\n");
   while((c = getch()) != 13)
   {
       if(i < 0)
           i = 0;
      if(c == 8)       /* 8 is ASCII value of BACKSPACE character */
	   {
           putch('\b');
           putch(NULL);
           putch('\b');
           i--;
       continue;
       }
       e_pass[i++] = c;
       putch('*');
   }
   e_pass[i] = '\0';    
if(strcmp(e_pass,p.password)==0)
    {	}
else {
	 	  printf("\n !!!!!!!!!      SORRY     !!!!!!!!!\n         WRONG PASSWORD\n\n Press any key to continue");
	 	  getche();
	      main_function();
          }    
}
int see_all_codes()
{   
    system("cls");
	FILE *fp;
	fp=fopen("medicine_record.txt","r");
	printf("  Unique Code List \n\n");
	printf("Code: \t\t Price: \t Quantity:");
	printf("\n************************************************\n");
	while(fread(&r,sizeof(r),1,fp))
	{
	    printf("Name:%s \n",r.name);
	    if(r.code<10 && r.code>0)
		printf("00%d \t\t %d \t\t %d\t\t ",r.code,r.price,r.qty);
		if(r.code<100 && r.code>=10)
		printf("0%d \t\t %d \t\t %d\t\t ",r.code,r.price,r.qty);
		if(r.code<1000 && r.code>=100)
		printf("%d \t\t %d \t\t %d\t\t ",r.code,r.price,r.qty);
		else{	}
		printf("\n=================================================\n");
	}
	fclose(fp);
	printf("Enter any key to continue");
	getche();
}
int delete_medicine()
{  
    system("cls");
	printf("\nEnter code to delete:\n");
	scanf("%d",&e_code);
	FILE *fp,*fs;
	fp=fopen("medicine_record.txt","r");
	fs=fopen("temp.txt","w");
   while(fread(&r,sizeof(r),1,fp))
	{
		if(e_code==r.code)
		 { 
		    printf("\n Code=00%d \n Name=%s \n Price=%d \n Quantity=%d\n",r.code,r.name,r.price,r.qty);
		    printf("\nDo you want to delete this record(y/Y): ");
		    choice=getch();
		    if(choice=='y' || choice=='Y')
		      {	  }
		    else
			  fwrite(&r,sizeof(r),1,fs);  
		 }
	    else
		  {
		  	fwrite(&r,sizeof(r),1,fs); 
		  }
	}
    fclose(fs);
    fclose(fp);
   printf("Your Record Successfully deleted:");
   printf("\nEnter any key to continue:\n");
   getche(); 
remove("medicine_record.txt");
rename("temp.txt","medicine_record.txt");
remove("temp.txt");
}

