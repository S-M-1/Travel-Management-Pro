#include<iostream>
#include<stdlib.h>
#include"dijikstra.h"
#include "train.h"
#include<conio.h>
#include<string>


namespace as{

int bc=50;
int wlc=10;
int a[101]={0},b[16]={0},t=0,w=0;

typedef struct node{
	int id;
	int data;
	char name[10][100];
	char gender[10][100];
	int age[10];
	double stplace;
	int desplace;
	struct node *next;
} node;

typedef node *list;
list head=0,head1=0;
list beg_ins(list head,int idee,int os);
list end_ins(list head);
list pos_ins(list head);
list beg_del(list head);
list end_del(list head);
list pos_del(list head);
list search(list head);
list display(list head);

void avail(int u);

void start(int idee)
{		
	int n;
	printf("\n\n\nENTER 1 YOU WANT TO BOOK THE TICKET\n\n\n");
	printf("ENTER 2 GO FOR HOLIDAY TRIP\n\n\n");
	printf("\n\n\nENTER YOUR CHOICE:->\n ");
	scanf("%d",&n);
	printf("\n\n\n");
	switch(n)
	{	
		int os;
		case 1:
			int f1;
			if(t<bc)
			{
				printf("PRESS 1 IF YOU WANNA BOOK FLIGHT TICKET\n\n\n");
				printf("PRESS 2 IF YOU WANNA BOOK TRAIN TICKET\n\n\n");
				
				scanf("%d",&f1);

				switch(f1)
				{
				case 1:
					os=2;   //NORMAL TICKET BOOKING
					head=beg_ins(head,idee,os);  //END INSERTION
					head=display(head);
					break;
				case 2:
					train1::train();
					break;
					default:
						printf("PLEASE ENTER A VALID CHOICE\n\n\n");
						break;
				}
			}
			else if(t>=bc && w<wlc)
			{ 
			head1=beg_ins(head1,idee,os);
			}
			else
			{
				printf("!!!!!!!!!!!!!!!!!!!NO ROOM IN THE WAITING LIST!!!!!!!!!!!!!!!!!! \n\n\n");
			}
			break;
	
		
		case 2:
			int c1,bc1;
			os=1;    //HOLIDAY PLANNING
			head=beg_ins(head,idee,os);
			head=display(head);
			break;

			
		default:
			printf("======================== ENTER THE VALID CHOICE ======================================\n");
	}

}

void avail(int u)  //TO CHECK WAITING LIST NUMBER, U IS ID 
{
int i=1,v;list temp;
temp =head1;
while(temp!=0)
{
	if(temp->id==u)
	{
	printf("YOUR WAITING LIST NUMBER IS %d\n",i);
	v=3;
}
	i=i+1;
	temp=temp->next;
}
if(v!=3)
{
	printf("NO DETAILS FOUND\n");
}
}

	
list beg_ins(list head,int idee,int os)
{	

	
	FILE *fp;
	fp=fopen("seats_reserved_plane.txt","a");
	

	list newnode,ptr,preptr;
	int n,i;	
	printf("ENTER THE NUMBER OF TICKETS TO BE BOOKED:-> \n");
	scanf("%d",&n);
	
		newnode=(list)malloc(sizeof(node));
		newnode->id=idee;
	newnode->data=n;

	for(i=0;i<n;i++)
	{char ad[100],bd[100];int cc,ii;
	tt:
	printf("ENTER THE DETAILS OF THE PASSSENGER %d\n",i+1);
	printf("\n\n\n=====================================================ENTER THE NAME======================================================== \n");
	scanf("%s",&ad);

	
	
	for(ii=0;ii<strlen(ad);ii++)
	{
		if(!isalpha(ad[ii]) && ad[ii]!=' ')
		{
		printf("ENTER VALID NAME\n");
		goto tt;
		}
	}

	

	printf("\n\n\n=====================================================ENTER THE GENDER(ENTER -MALE OR FEMALE)=================================================== \n\n\n");
	scanf("%s",&bd);
	
	
	if(strcmp(bd,"MALE")!=0 && strcmp(bd,"FEMALE")!=0 )
	{
		printf("ENTER VALID INPUT\n");
		goto tt;
	}



	printf("\n\n\n======================================================ENTER THE AGE======================================================\n\n\n");
	scanf("%d",&cc);
	
	if(cc<5 || cc>90)
	{
		printf("ENTER VALID INPUT\n");
		goto tt;
	}

	

	strcpy(newnode->name[i],ad);
	strcpy(newnode->gender[i],bd);
	newnode->age[i]=cc;

	fprintf(fp,"Ticket: %d\nName: %s\nGender: %s\nAge: %d\n\n ",i+1,&ad,bd,cc);
	}


	int iop;
	sjt:
		printf("\n\n\nCHOOSE YOUR CITY\n");
		printf("\n\n\nPRESS 1.MUMBAI\n");
		printf("\n\n\nPRESS 2.PONDICHERRY\n");
		printf("\n\n\nPRESS 3.KOLKATA\n");
		printf("\n\n\nPRESS 4.GOA\n");	
		printf("\n\n\nPRESS 5.CHENNAI\n");
		printf("ENTER YOUR CHOICE\n\n");
		scanf("%d",&iop);
	
		if(iop<1 || iop>5)
		{
		printf("ENTER VALID CHOICE\n");
		goto sjt;
	}

	newnode->stplace=iop;
	int iop1;
	printf("\n\nCHOOSE YOUR DESTINATION\n");
		scanf("%d",&iop1);
		
		if(iop1<1 || iop1>5 || (iop1==newnode->stplace))
		{
		printf("ENTETR VALID CHOICE\n");
		goto sjt;
		}

		
	switch(iop1){
		case 1:
			fprintf(fp,"\nDestination: Mumbai\n\n");
		 break;
		case 2:
		fprintf(fp,"\nDestination:Pondicherry\n\n");
		 break;
		case 3:
		fprintf(fp,"\nDestination:Kolkata\n\n");
		 break;
		case 4:
		fprintf(fp,"\nDestination:Goa\n\n");
		 break;
		case 5:
		fprintf(fp,"\nDestination:Chennai\n\n");
		break;
	}

fclose(fp);

	newnode->desplace=iop1;
	newnode->id=idee;
 newnode->next=0;
 t=t+n; 

 dj::path1(newnode->stplace-1,newnode->desplace-1,os);  
		if(head==0)
	{
		head=newnode;
		printf("\n\n============================SUCCESSFULLY DONE!!!===================================\n");
		return head;
	}
	else
	{
		ptr=head;
		while(ptr->next!=0)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
		printf("============================SUCCESSFULLY DONE!!!===================================\n");
		return head;
	}
	
}




list beg_del(list head)
{
	if(head==0)
	{
		printf("nothing to delete\n");
	}
	else
	{
	list newnode,ptr,preptr;
	ptr=head;
	head=head->next;
	printf("============================SUCCESSFULLY DONE!!!===================================\n");
	free(ptr);
}
	return head;
}

list display(list head)
{
	list ptr=head;int i,x=0;
	if(ptr==0)
	{
		printf("nothing to show\n");
		
	}
	else{
	printf("\n\nGREETINGS!!! TICKETS SUCCESFULLY BOOKED\n\nTICKET DETAILS\n\n");
		while(x!=t-head->data)
	{
		ptr=ptr->next;
		x=x+1;
	}
	i=0;
	while(i<ptr->data)
	{
		printf("PASSENGER NO: %d\n\n",i+1);
		puts(ptr->name[i]);printf("NAME-->  %s\n",ptr->name[i]);
		
		puts(ptr->gender[i]);printf("\t");
	
		printf("AGE OF PASSENGER-->%d\n",ptr->age[i]);printf("\n");
		printf("\n\nSEAT NUMBER-->%d\n\n",x+1);
		x=x+1;
		
		i=i+1;
	}
		printf("\nPRESS ANY KEY TO GO MAIN MENU\n");
		
		
return head;
}
}
}
