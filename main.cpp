#include<math.h>
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<cstdlib>
#include<ctype.h>
#include "ticket.h"
#include "floyd.h"
#include "regression.h"

static int idt=100;
struct tree {
	int id;
	int data;
	char pass[100];
	char name[100];
	struct tree *left;
	struct tree *right;
} *root = NULL, *node = NULL, *temp = NULL;

struct tree* insert(int key,char n[],char p[],struct tree *leaf)
{
	if(leaf == 0) {
		struct tree *temp;
		temp = (struct tree *)malloc(sizeof(struct tree));
		strcpy(temp->name,n);
		strcpy(temp->pass,p);
		temp->data=key;
		temp->id=idt;
		idt++;
		temp->left = 0;
		temp->right = 0;
		printf("\n===================================YOU ARE SUCCESSFULLY REGISTERED============================================\n\n\n");
		printf("PRESS ANY KEY TO GO MAIN MENU\n");
		
		
		return temp;
	}
	else {
		if(key < leaf->data)
			leaf->left =insert(key,n,p,leaf->left);
		else
			leaf->right=insert(key,n,p,leaf->right);
	}
	return leaf;					
}
int search(int key,char p[],struct tree *leaf) 
{
	if(leaf != NULL) {
		if(key==leaf->data&& strcmp(p,leaf->pass)==0) {
			return leaf->id;
		}
		else {
			if(key < leaf->data)
				return search(key,p,leaf->right);
			else
				return search(key,p,leaf->right);
		}
	}
	return -1;
}










int main()
{	
	FILE *fp, *fa, *ft;
	
	char s[100];

	while(1)	{
		int n,g,x;
		char c[100], d[100];
		jk:
	printf("\n\n\n\n\t==============================================================================  WELCOME TO MAIN MENU  ==============================================================================\n\n\n\n\n>>>>>>\tPRESS 1 TO REGISTER WITH US\n\n");
	printf(">>>>>\tPRESS 2 FOR LOGIN IF ALREADY A REGISTERED USER \n\n");
	printf(">>>>>\tENTER 3 TO CHECK YOUR TICKETS\n\n");
	printf(">>>>>\tPRESS 4 IF YOU WOULD LIKE TO GET OUR ADVICE\n\n");
	printf(">>>>>\tPress 5 IF YOU WOULD LIKE TO SEE OUR ANALYSIS FROM THE DATA FOR PREDICTIONS ABOUT THE TRENDS FOR DIFFERENT PLACES\n\n");
	printf(">>>>>\tPress 6 IF YOU WANT TO QUIT");
	scanf("%d",&n);
	
	int y1=-1;
		switch(n)
		{	
				case 1:
				mp:
					int i;
				printf("\n\nENTER YOUR NAME\n");
				scanf("%s",&c);
				
				for(i=0;i<strlen(c);i++)
				{
					if(!isalpha(c[i]) && c[i]!=' ')
					{
						printf("PLEASE ENTER VALID NAME\n");
						goto mp;
					}
				}

				

				printf("\n\nENTER THE PASSWORD(PASSWORD MUST BE 8 CHARACTER LENGTH):\n");
				scanf("%s",&d);
				if(strlen(d)<8)
				{printf("\n\nPASSWORD MUST BE GREATER OR EQUAL 8 CHARACTER LENGTH\n");
				
				goto mp;}
				doy:
				int dd,mm,yy;
				printf("\n\nENTER YOYR DATE OF BIRTH:\n");
				printf("\n\nENTER YEAR :\n");
				scanf("%d",&yy);
				printf("\n\nENTER MONTH:\n");
				scanf("%d",&mm);
				printf("\n\nENTER DAY:\n");
				scanf("%d",&dd);
				if((yy<1940 || yy>2016) || (mm<0 && mm>12) ||(dd<0 || dd>30))
				{
				printf("SORRY INVALID ENTRY, RE-ENTER THE DATA\n");
				goto doy;}
				
				g=yy*10000+mm*100+dd;
				root=insert(g,c,d,root);

				break;
				case 2:
					re:
						mp1:
				printf("\n\nENTER YOUR DATE OF BIRTH(yyyymmdd):\n");
				scanf("%d",&x);
			
				printf("\n\nENTER YOUR PASSWORD:\n");
				scanf("%s",&d);
					if(strlen(d)<8)
				{printf("\n\nPASSWORD MUST BE 8 CHARACTER OR GREATER LENGTH\n");
				goto mp1;}
				
				y1=search(x,d,root);
				if(y1!=-1)
				{
					
					printf("...............WELCOME !!!!!!..............\n\n\n");
					as::start(y1);
				}
				else
				{
					int kh;
					printf("\n\nSORRY INVALID USER DETAILS!!!\n\n");
					printf("ENTER 1 TO GO TO MAIN MENU\n ENTER 2 TO RE-ENTER DATA\n\n");
					scanf("%d",&kh);
					switch (kh)
					{
						case 1:
							goto jk;
							break;
							case 2:
					goto re;
					break;
					default:
						printf("ENTER VALID CHOICE\n");
						goto re;
						break;
				}}
				break;
			case 3:
				re1:
					int a1;
				char b1[100];
				printf("\n\nPLEASE LOGIN!!!\nENTER YOUR DATE OF BIRTH\n");
				scanf("%d",&a1);
				
				printf("ENTER YOUR PASSWORD\n");
				scanf("%s",&b1);
				
				y1=search(a1,b1,root);
				if(y1!=-1)
				{
					int ch;
					printf("Press\n1.Plane:\n2.Train\n3. Holiday Ticket\n");
					scanf("%d",&ch);
				switch(ch){
						case 1:
							
								fp=fopen("seats_reserved_plane.txt", "r");
								if(fp==NULL)
									{
										printf("Error in opening file..!!");
									
										exit(0);
									}
									while(fgets(s, 99, fp)!=NULL)
									{
										printf("%s",s);
									}
									printf("\n");
									fclose(fp);
						break;

						case 2:
							
								fa=fopen("seats_reserved.txt", "r");
								if(fa==NULL)
									{
										printf("Error in opening file..!!");
									
										exit(0);
									}
									while(fgets(s, 99, fa)!=NULL)
									{
										printf("%s",s);
									}
									printf("\n");
						break;

						case 3:
							ft=fopen("seats.txt", "r");
								if(ft==NULL)
									{
										printf("Error in opening file..!!");
									
										exit(0);
									}
									while(fgets(s, 99, ft)!=NULL)
									{
										printf("%s",s);
									}
									printf("\n");
							break;

				}
				}
				else 
				{printf("\n\nSORRY!!! INVALID DETAILS...\n");
				printf("PRESS ANY KEY TO GO TO MAIN MENU");
				
				goto jk;
				}


				break;

			case 4:
				fw::places();
				break;


			case 5:
				{ 
					int choice, data[5],number;
					printf("\nHow many places would you like to see the data for ?\n");
					printf("\n1.Mumbai\n2.Pondicherry\n3.Goa\n4.Kolkata\n5.Chennai\n\n");
					scanf("%d",&number);

					for(i=0;i<number;i++){
						printf("Please enter the %d place of which you would like to see the data about\n\n",i+1);
						printf("\n1.Mumbai\n2.Pondicherry\n3.Goa\n4.Kolkata\n5.Chennai\n\n");
						scanf("%d",&choice);
						printf("\n\n");
						switch(choice){
							case 1:
								reg::Mumbai();
								break;
							case 2:
								reg::Pondicherry();
								break;
							case 3:
								reg::Goa();
								break;
							case 4:
								reg::Kolkata();
								break;
							case 5:
								reg::Chennai();
								break;
						}
					}

					printf("\n\nTHANKS FOR VISITING US\n");
					exit(0);
				}
			case 6:
				exit(0);
			default:
				{
				printf("\n\nSORRY!!! INVALID DETAILS...\n");		
				goto jk;}
			break;
			}
		}

		return 0;
 }
