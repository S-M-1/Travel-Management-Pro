#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
namespace train1{
typedef struct{
	char name[50];
	int train_num;
	int num_of_seats;
}pd;
void reservation(void);							
void viewdetails(void);							
void cancel(void);								
int printticket(char name[],int,int,float);	 
void specifictrain(int);						
float charge(int,int);							

int train()
{
		
	printf("\t\t=================================================\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|           TRAIN TICKET RERS. SYSTEM           |\n");
	printf("\t\t|        -----------------------------          |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t|        ------------------------------------   |\n");
	printf("\t\t|                 TRAVEL AGENCY                 |\n");
	printf("\t\t|        ------------------------------------   |\n");
	printf("\t\t|                                               |\n");
	printf("\t\t=================================================\n\n\n");
		
	    
	printf(" \n Press any key to continue:");
		
    
	int menu_choice,choice_return;
	int y=0;
	while(y!=1)
	{
	printf("\n=================================\n");
	printf("    TRAIN RESERVATION SYSTEM");
	printf("\n=================================");
	printf("\n1>> Reserve A Ticket");
	printf("\n------------------------");
	printf("\n2>> View All Available Trains");
	printf("\n------------------------");
	printf("\n3>> Cancel Reservation");
	printf("\n------------------------");
	printf("\n4>> Go to home");
	printf("\n------------------------");
	printf("\n\n-->");
	scanf("%d",&menu_choice);
	
	switch(menu_choice)
	{
		case 1:
			reservation();		
			break;
		case 2:
			viewdetails();
			printf("\n\nPress any key to go to Main Menu..");
			
			break;
		case 3:
			cancel();
			break;
		case 4:
		y=1;
			break;
		
		default:
			printf("\nInvalid choice");
	}
}
	return 0;
}

void viewdetails(void)
{
	
	printf("--------------------------------------------------------------------------------------------------------");	
	printf("\nTr.No\tName\t\t\t\tDestinations\t\t\tCharges\t\tTime\n");
	printf("--------------------------------------------------------------------------------------------------------");
	printf("\n1001\tPatli Putra Express\t\tMumbai to Pondicherry\t\tRs.5000\t\t9am");
	printf("\n1002\tGhaziabad Express\t\tPondicherry To Mumbai\t\tRs.5000\t\t12pm");
	printf("\n1003\tRajdhani Express\t\tMumbai To Kolkata\t\tRs.4500\t\t8am");
	printf("\n1004\tGareeb Rath Express\t\tKolkata To Mumbai\t\tRs.4500\t\t11am");
	printf("\n1005\tMumbai-Goa Special\t\tMumbai To Goa\t\t\tRs.4000\t\t7am");
	printf("\n1006\tShatabdi Express\t\tGoa To Mumbai\t\t\tRs.4000\t\t9.30am");
    printf("\n1007\tChennai Express\t\t\tMumbai To Chennai\t\tRs.3500\t\t1pm");	
    printf("\n1008\tItercity Express\t\tChennai To Mumbai\t\tRs.3500\t\t4pm");
    printf("\n1009\tDouble Decar Express\t\tPondicherry to Kolkata\t\tRs.6000\t\t9am");
	printf("\n1010\tKolkata Express\t\t\tKolkata To Pondicherry\t\tRs.6000\t\t12pm");
	printf("\n1011\tMazza Express\t\t\tPondicherry To Goa\t\tRs.4500\t\t8am");
	printf("\n1012\tSitara Express\t\t\tGoa To Pondicherry\t\tRs.4500\t\t11am");
	printf("\n1013\tDornto Express\t\t\tPondicherry To Chennai\t\tRs.4000\t\t7am");
	printf("\n1014\tLaal Bhaag Express\t\tChennai To Pondicherry\t\tRs.4000\t\t9.30am");
    printf("\n1015\tKaveri Express\t\t\tKolkata To Goa\t\t\tRs.3500\t\t1pm");	
    printf("\n1016\tSampark Kranti Express\t\tGoa To Kolkata\t\t\tRs.3500\t\t4pm");
    printf("\n1017\tGodavari Express\t\tKolkata To Chennai\t\tRs.6000\t\t3.35pm");
    printf("\n1018\tAwadh Express\t\t\tChennai To Kolkata\t\tRs.6000\t\t4.15pm");
    printf("\n1019\tGoda Express\t\t\tGoa To Chennai\t\t\tRs.6500\t\t5.35pm");
    printf("\n1020\tAwa Express\t\t\tChennai To Goa\t\t\tRs.6500\t\t2.15pm");

}
void reservation(void)
{
	char confirm;
	int i=0,ii;
	float charges;
	pd passdetails;
	FILE *fp;
	fp=fopen("seats_reserved.txt","a");
	
	printf("\nEnter Your Name:> ");
	fflush(stdin);
	gets(passdetails.name);
	printf("\nEnter Number of seats:> ");
	scanf("%d",&passdetails.num_of_seats);
	printf("\n\n>>Press Enter To View Available Trains<< ");
	
	
	viewdetails();
	printf("\n\nEnter train number:> ");
	start1:
	scanf("%d",&passdetails.train_num);
	if(passdetails.train_num>=1001 && passdetails.train_num<=1020)
	{
		charges=charge(passdetails.train_num,passdetails.num_of_seats);
		printticket(passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);		
	}
	else
	{
		printf("\nInvalid train Number! Enter again--> ");
		goto start1;
	}
	printf("\n\nConfirm Ticket (y/n):>");
	start:
	scanf(" %c",&confirm);
	if(confirm == 'y')
	{
		fprintf(fp,"%s\t\t%d\t\t%d\t\t%.2f\n",&passdetails.name,passdetails.num_of_seats,passdetails.train_num,charges);
		printf("==================");
		printf("\n Reservation Done\n");
		printf("==================");
		printf("\nPress any key to go back to Main menu");
	}
	else
	{
		if(confirm=='n'){
			printf("\nReservation Not Done!\nPress any key to go back to  Main menu!");
		}
		else
		{
			printf("\nInvalid choice entered! Enter again-----> ");
			goto start;
		}
	}
	fclose(fp);
	
}
float charge(int train_num,int num_of_seats)
{
		if (train_num==1001)
	{
		return(5000.0*num_of_seats);
	}
	else if (train_num==1002)
	{
		return(5000.0*num_of_seats);
	}
	else if (train_num==1003)
	{
		return(4500.0*num_of_seats);
	}
	else if (train_num==1004)
	{
		return(4500.0*num_of_seats);
	}
	else if (train_num==1005)
	{
		return(4000.0*num_of_seats);
	}
	else if (train_num==1006)
	{
		return(4000.0*num_of_seats);
	}
	else if (train_num==1007)
	{
		return(3500.0*num_of_seats);
	}
	else if (train_num==1008)
	{
		return(3500.0*num_of_seats);
	}
	else if (train_num==1009)
	{
		return(6000.0*num_of_seats);
	}
	else if (train_num==1010)
	{
		return(6000.0*num_of_seats);
	}
	else if (train_num==1011)
	{
		return(4500.0*num_of_seats);
	}
	else if (train_num==1012)
	{
		return(4500.0*num_of_seats);
	}
		if (train_num==1013)
	{
		return(4000.0*num_of_seats);
	}
	else if (train_num==1014)
	{
		return(4000.0*num_of_seats);
	}
	else if (train_num==1015)
	{
		return(3500.0*num_of_seats);
	}
	else if (train_num==1016)
	{
		return(3500.0*num_of_seats);
	}
	else if (train_num==1017)
	{
		return(6000.0*num_of_seats);
	}
	else if (train_num==1018)
	{
		return(6000.0*num_of_seats);
	}
	else if (train_num==1019)
	{
		return(6500.0*num_of_seats);
	}
	else if (train_num==1020)
	{
		return(6500.0*num_of_seats);
	}
}
int printticket(char name[],int num_of_seats,int train_num,float charges)
{
	
	printf("-------------------\n");
	printf("\tTICKET\n");
	printf("-------------------\n\n");
	//display();
/*	printf("Name:\t\t\t%s",name);
	printf("\nNumber Of Seats:\t%d",num_of_seats);
	printf("\nTrain Number:\t\t%d",train_num);
	specifictrain(train_num);*/
	
	printf("\nCharges:\t\t%.2f",charges);
	return 0;
}
void specifictrain(int train_num)
{
	
	if (train_num==1001)
	{
		printf("\nTrain:\t\t\tPatli Putra Express");
		printf("\nDestination:\t\tMumbai To Pondicherry");
		printf("\nDeparture:\t\t9am ");
	}
	else if (train_num==1002)
	{
		printf("\nTrain:\t\t\tGhaziabad Express");
		printf("\nDestination:\t\tPondicherry To Mumbai");
		printf("\nDeparture:\t\t12pm");
	}
	else if (train_num==1003)
	{
		printf("\nTrain:\t\t\tRajdhani Express");
		printf("\nDestination:\t\tMumbai To Kolkata ");
		printf("\nDeparture:\t\t8am");
	}
	else if (train_num==1004)
	{
		printf("\nTrain:\t\t\tGareeb Rath Express");
		printf("\nDestination:\t\tKolkata to Mumbai");
		printf("\nDeparture:\t\t11am ");
	}
	else if (train_num==1005)
	{
		printf("\nTrain:\t\t\tMumbai-Goa Special");
		printf("\nDestination:\t\tMumbai to Goa");
		printf("\nDeparture:\t\t7am");
	}
	else if (train_num==1006)
	{
		printf("\ntrain:\t\t\tShatabdi Express");
		printf("\nDestination:\t\tGoa to Mumbai");
		printf("\nDeparture:\t\t9.30am ");
	}
	else if (train_num==1007)
	{
		printf("\ntrain:\t\t\tChennai Express");
		printf("\nDestination:\t\tMumbai to Chennai");
		printf("\nDeparture:\t\t1pm ");
	}
	else if (train_num==1008)
	{
		printf("\ntrain:\t\t\tItercity Express");
		printf("\nDestination:\t\tChennai to Mumbai");
		printf("\nDeparture:\t\t4pm ");
	}
	else if (train_num==1009)
	{
		printf("\ntrain:\t\t\tDouble Decar Express");
		printf("\nDestination:\t\tPondicherry to Kolkata");
		printf("\nDeparture:\t\t9am ");
	}
	else if (train_num==1010)
	{
		printf("\ntrain:\t\t\tKolkata Express");
		printf("\nDestination:\t\tKolkata to Pondicherry");
		printf("\nDeparture:\t\t12pm ");
	}
	else if (train_num==1011)
	{
		printf("\nTrain:\t\t\tMazza Express");
		printf("\nDestination:\t\tPondicherry to Goa");
		printf("\nDeparture:\t\t8am ");
	}
	else if (train_num==1012)
	{
		printf("\nTrain:\t\t\tSitara Express");
		printf("\nDestination:\t\tGoa to Pondicherry");
		printf("\nDeparture:\t\t11am ");
	}
	else if (train_num==1013)
	{
		printf("\nTrain:\t\t\tDornto Express");
		printf("\nDestination:\t\tPondicherry to Chennai");
		printf("\nDeparture:\t\t7am ");
	}
	else if (train_num==1014)
	{
		printf("\nTrain:\t\t\tLaal Bhaag Express");
		printf("\nDestination:\t\tChennai to Pondicherry");
		printf("\nDeparture:\t\t9.30am ");
	}
	else if (train_num==1015)
	{
		printf("\nTrain:\t\t\tKaveri Express");
		printf("\nDestination:\t\tKolkata to Goa");
		printf("\nDeparture:\t\t9am ");
	}
	else if (train_num==1016)
	{
		printf("\nTrain:\t\t\tSampark Kranti Express");
		printf("\nDestination:\t\tGoa to Kolkata");
		printf("\nDeparture:\t\t1am ");
	}
	else if (train_num==1017)
	{
		printf("\nTrain:\t\t\tGodavari Express");
		printf("\nDestination:\t\tKolkata to Chennai");
		printf("\nDeparture:\t\t4am ");
	}
	else if (train_num==1018)
	{
		printf("\nTrain:\t\t\tAwadh Express");
		printf("\nDestination:\t\tChennai to Kolkata");
		printf("\nDeparture:\t\t3.35am ");
	}
	else if (train_num==1019)
	{
		printf("\nTrain:\t\t\tGoda Express");
		printf("\nDestination:\t\tGoa to Chennai");
		printf("\nDeparture:\t\t5.35am ");
	}
	else if (train_num==1020)
	{
		printf("\nTrain:\t\t\tAwa Express");
		printf("\nDestination:\t\tChennai to Goa");
		printf("\nDeparture:\t\t2.15am ");
	}
}

void cancel(void)   
{
	
	int trainnum;
	printf("-----------------------\n");
		printf("Enter the train number: \n");
			printf("-----------------------\n");
		
		scanf("%d",&trainnum);
		printf("\n\nCancelled");  
		
}
}