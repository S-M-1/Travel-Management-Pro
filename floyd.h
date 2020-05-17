// Floyd warshall algorithm

#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<map>
#include<functional>
#include<vector>
#include<string>



using namespace std;


namespace fw{

double min(double a, double b){
	
	
	
	if( (a == INFINITY) || (a>b)){
		return b;
	}
	else if((b==INFINITY) || (a<b)){
		return a;
	}
	
	else{
		return a;
	}
}



void floyd_warshall_train(int place[],int c){
 	
 	double distance_by_train[5][5] = {
	 	{0,INFINITY,592,2014,1338}, {INFINITY,0,894,INFINITY,2408},{592,894,0,INFINITY,INFINITY},{2014,INFINITY,INFINITY,0,1504},{1333,205.3,INFINITY,1802,0}
	 }; 
	 
	
	
	double new_mat_train[5][5]={
	 	{0,INFINITY,592,2014,1338}, {INFINITY,0,894,INFINITY,2408},{592,894,0,INFINITY,INFINITY},{2014,INFINITY,INFINITY,0,1504},{1333,205.3,INFINITY,1802,0}
	 }; 
	 
	
	 

	
	int i,j,k;
	
	char d[50][50] = {
		{"Mumbai"},{"Pondicherry"},{"Goa"},{"Kolkata"},{"Chennai"}
	};
	
	
	for(k=0;k<5;k++){
		
			
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				if(i==j){
					new_mat_train[i][j] =0;
				}
				else{
					new_mat_train[i][j] = min(new_mat_train[i][j],new_mat_train[i][k]+new_mat_train[k][j]);					
				}
			}	
		}
	}
		
	double sum_d=0, value[100],temp;
	int index=0;
	for(i=0;i<c-1;i++){
		printf("The shortest distance between %s and %s is %lf kilometers by train \n",d[place[i]-1],d[place[i+1]-1],new_mat_train[place[i]-1][place[i+1]-1]);
		sum_d+=new_mat_train[place[i]-1][place[i+1]-1];
	}
	
	for(i=0;i<c;i++){

		if(new_mat_train[place[0]-1][place[i+1]-1]!=0)
				value[index++]=new_mat_train[place[0]-1][place[i+1]-1];
	}

	for(i=0;i<index-1;i++){
		for(j=0;j<index-i-1;j++){
			if(value[j]>value[j+1]){
				temp=value[j];
				value[j]=value[j+1];
				value[j+1]=temp;
			}
		}
	}

	printf("\n\n\nTherfore the places where you should travel in order to have the minimum distance so as to minimize the travel expenses is:\n\n");
	int t=0,y=1;

	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			
			if( (new_mat_train[i][j]==value[t])  && y==1 ){
				printf("%s to %s ",d[place[i]-1],d[place[j]-1]);
				t++;
				y++;
			}
			else if((new_mat_train[i][j]==value[t]) && y!=1){
				printf("to %s ",d[place[i]-1]);
				t++;
			}
		}
	}
	

	printf("\n\n\nThe total distance travelled is: %lf\n",sum_d);
}


void floyd_warshall_plane(int place[],int c){
	int k,i,j;

	 double distance_by_plane[5][5] = {
	{0,INFINITY,423,1654,1033}, {INFINITY,0,758.6,INFINITY,137.63}, {423,758.6,0,INFINITY,INFINITY}, {1654,INFINITY,INFINITY,0,1357.47}, 
	{1033,137.63,INFINITY,1357.47,0}
	};
	
	
	 double new_mat_plane[5][5] = {
	{0,INFINITY,423,1654,1033}, {INFINITY,0,758.6,INFINITY,137.63}, {423,758.6,0,INFINITY,INFINITY}, {1654,INFINITY,INFINITY,0,1357.47}, 
	{1033,137.63,INFINITY,1357.47,0}
	};
	
	char d[50][50] = {
		{"Mumbai"},{"Pondicherry"},{"Goa"},{"Kolkata"},{"Chennai"}
	};
	
	
	for(k=0;k<5;k++){
		
			
		for(i=0;i<5;i++){
			for(j=0;j<5;j++){
				new_mat_plane[i][j] = min(new_mat_plane[i][j],new_mat_plane[i][k]+new_mat_plane[k][j]);
			}	
		}
	}
	
	double sum_d=0;
	
	for(i=0;i<c-1;i++){
		printf("The shortest distance between %s and %s is %lf kilometers by plane \n",d[place[i]-1],d[place[i+1]-1],new_mat_plane[place[i]-1][place[i+1]-1]);	
		sum_d+=new_mat_plane[place[i]-1][place[i+1]-1];
	}

	double  value[100],temp;
	int index=0;


	for(i=0;i<c;i++){

		if(new_mat_plane[place[0]-1][place[i+1]-1]!=0)
				value[index++]=new_mat_plane[place[0]-1][place[i+1]-1];
	}

	for(i=0;i<index-1;i++){
		for(j=0;j<index-i-1;j++){
			if(value[j]>value[j+1]){
				temp=value[j];
				value[j]=value[j+1];
				value[j+1]=temp;
			}
		}
	}

	printf("\n\n\nTherfore the places where you should travel in order to have the minimum distance so as to minimize the travel expenses is:\n\n");
	int t=0,y=1;

	
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			
			if( (new_mat_plane[i][j]==value[t])  && y==1 ){
				printf("%s to %s ",d[place[i]-1],d[place[j]-1]);
				t++;
				y++;
			}
			else if((new_mat_plane[i][j]==value[t]) && y!=1){
				printf("to %s ",d[place[i]-1]);
				t++;
			}
		}
	}
	
		printf("The total distance travelled is: %lf\n",sum_d);
 	
}




void Mumbai(){
	char MUMBAI[10][50]={{"HAJI-ALLI-DARGAH"} ,{"JUHU-BEACH"},{"GATEWAY-OF-INDIA"} ,{"COLABA-CAUSEWAY"} ,{"SIDDHI-VINAYAK-TEMPLE"} ,
	{"THE-TAJ-MAHAL-PALACE"} ,{"OBEROI-MUMBAI"} ,{"IMAGICA"}, {"LONAWALA"} , {"KHANDALA"}};
	
	printf("Places to visit in Mumbai are:\n");
	
 		
		int i,j=0;

        for(i=0;i<10;i++){
            j=0;
            while(MUMBAI[i][j]!='\0'){
                printf("%c",MUMBAI[i][j]);
                j++;
            }
            printf("\n");
        }
        
}

void Pondicherry(){
	char PONDICHERRY[10][40]={{"PARADISE-BEACH"},{"AUROVILLE"},{"SEASIDE-PROMINADE"},{"ARIKAMEDU"},{"CHUNAMBAR-BOAT-HOUSE"},{"PARADIS-ISLAND"},
	{"PONDICHERRY-MUSEUM"},{"BOTANICAL-GARDEN"},{"GOVERNMEN-PARK"},{"MAHATMA-GANDHI-STATUE"}};
	printf("Places to visit in Pondicherry are:");
	
	
     	int i,j=0;
        for(i=0;i<10;i++){
            j=0;
            while(PONDICHERRY[i][j]!='\0'){
                printf("%c",PONDICHERRY[i][j]);
                j++;
            }
            printf("\n");
        }				 
}

void Goa(){
	char GOA[12][50]={{"BAGAH-BEACH"},{"VAGATOR-BEACH"},{"COLVA-BEACH"},{"TALPONA-BEACH"},
        {"SARNABATIM-BEACH"},{"PATNEM-BEACH"},{"MIRAMAR-BEACH"},{"MAJORDA-BEACH"},{"KALCHA-BEACH"},
        {"GALGIBAGHA-BEACH"},{"DONAPAULA-BEACH"},{"COCO-BEACH"}};

        int i,j=0;
		printf("Places to visit in Goa are:");
        for(i=0;i<12;i++){
            j=0;
            while(GOA[i][j]!='\0'){
                printf("%c",GOA[i][j]);
                j++;
            }
            printf("\n");
        }
}


void Kolkata(){
	char KOLKATA[10][60]={{"VICTORIA-MEMORIAL"} ,{"BELUR-MATH"} ,{"HOWRAH-BRIDGE"} ,{"INDIAN-MUSEUM"} ,{"MARBLE-PALACE-MANSION"} ,{"MOTHER-HOUSE"} ,
	{"SCIENCE-CITY"} ,{"ST.-PAUL-CATHEDRAL"} ,{"TAJPUR"} ,{"BIRLA-MANDIR"} };
	
	printf("Places to visit in Kolkata are:");
	
	
	
	 int i,j=0;

        for(i=0;i<10;i++){
            j=0;
            while(KOLKATA[i][j]!='\0'){
                printf("%c",KOLKATA[i][j]);
                j++;
            }
            printf("\n");
        }
}

void Chennai(){
	char CHENNAI[10][70]={{"MARINA BEACH"} , {"KAPALEESHWARAR TEMPLE"} , {"GOVERNMENT MUSEUM"} , {"EDWARD ELLIOT'S BEACH"}  , {"SANTHOME CATHEDRAL"} , 
	{"GOLDEN BEACH RESORT"} , {"GUINDY NATIONAL PARK"} , {"FORT. ST. GEORGE"} , {"DAKSHINACHITRA"} , {"VALLUVAR KOTTAM"}};
	
	
	printf("Places to visit in Chennai are:");
	
 int i,j=0;

        for(i=0;i<10;i++){
            j=0;
            while(CHENNAI[i][j]!='\0'){
                printf("%c",CHENNAI[i][j]);
                j++;
            }
            printf("\n");
        }
}




void places(){
	int i,place[5];
	int choice,budget;
	char mode_of_travel;
	
	printf("How many places are you planning to visit out of the following?\nHere are your choices:\n\n");
	
	printf("Mumbai\nPondicherry\nGoa\nKolkata\nChennai\n");
	
	scanf("%d",&choice);
	
	
	for(i=0;i<choice;i++){
		printf("Please enter the places you are planning to visit:\n1.Mumbai\n2.Pondicherry\n3.Goa\n4.Kolkata\n5.Chennai\n");
		printf("Enter your %d destination",i+1);
		scanf("%d",&place[i]);
		printf("\n\n");
			switch(place[i]){
				case 1:
					printf("GOOD CHOICE\n");
					Mumbai();
					break;
				case 2:
					printf("GOOD CHOICE\n");
					Pondicherry();
					break;
				case 3:
					printf("GOOD CHOICE\n");
					Goa();
					break;
				case 4:
					printf("GOOD CHOICE\n");
					Kolkata();
					break;
				case 5:
					printf("GOOD CHOICE\n");
					Chennai();
					break;
				default:
					printf("Wrong choice");
					break;
			
			}
			printf("\n\n");	
		}
			
			int cm;
			printf("What is your preferred mode of journey\n1.Train\n2.Plane");
			scanf("%d",&cm);
			
		switch(cm){
			case 1:
				floyd_warshall_train(place,choice);
				break;
			case 2:
				floyd_warshall_plane(place,choice);
				break;
		}
}

}