#include<iostream>
#include<string.h>
#include<stdlib.h>
namespace art{
char CHENNAI[50][50]={"MARINA BEACH", "KAPALEESHWARAR TEMPLE", "GOVERNMENT MUSEUM", "EDWARD ELLIOT'S BEACH", "SANTHOME CATHEDRAL", "GOLDEN BEACH RESORT", "GUINDY NATIONAL PARK", "FORT. ST. GEORGE", "DAKSHINACHITRA", "VALLUVAR KOTTAM"};
char GOA[50][50]={"BAGAH-BEACH","VAGATOR-BEACH","COLVA-BEACH","TALPONA-BEACH","SARNABATIM-BEACH","PATNEM-BEACH","MIRAMAR-BEACH","MAJORDA-BEACH","KALCHA-BEACH","GALGIBAGHA-BEACH","DONAPAULA-BEACH","COCO-BEACH"};
char KOLKATA[50][100]={"VICTORIA-MEMORIAL","BELUR-MATH","HOWRAH-BRIDGE","INDIAN-MUSEUM","MARBLE-PALACE-MANSION","MOTHER-HOUSE","SCIENCE-CITY","ST.-PAUL-CATHEDRAL","TAJPUR","BIRLA-MANDIR"};
char MUMBAI[100][100]={"HAJI-ALLI-DARGAH","JUHU-BEACH","GTEWAY-OF-INDIA","COLABA-CAUSEWAY","SIDDHI-VINAYAK-TEMPLE","THE-TAJ-MAHAL-PALACE","OBEROI-MUMBAI","IMAGICA","LONAWALA","KHANDALA"};
char PONDICHERRY[100][100]={"PARADISE-BEACH","AUROVILLE","SEASIDE-PROMINADE","ARIKAMEDU","CHUNAMBAR-BOAT-HOUSE","PARADIS-ISLAND","PONDICHERRY-MUSEUM","BOTANICAL-GARDEN","GOVERNMEN-PARK","MAHATMA-GANDHI-STATUE"};
struct five
{
int days[100];
char hotel[100];
char travel[100];
char place[50][50];
}goa_a,kolkata_a,chennai_a,mumbai_a,pondicherry_a;
struct ten
{
	int days[100];
	char hotel[100];
	char travel[100];
	char place[50][50];
}goa_b,chennai_b,kolkata_b,mumbai_b,pondicherry_b;


struct fifteen
{
	int days[100];
	char hotel[100];
	char travel[100];
	char place[50][50];
}goa_c,kolkata_c,chennai_c,mumbai_c,pondicherry_c;


struct twenty
{
int days[100];
char hotel[100];
char place[50][50];
char cruise[100];	
}goa_d,kolkata_d,chennai_d,mumbai_d,pondicherry_d;


void holiday()
{
	int i;
	for(i=0;i<3;i++)
	{
		strcpy(goa_a.place[i],GOA[i]);
		strcpy(kolkata_a.place[i],KOLKATA[i]);
		strcpy(chennai_a.place[i],CHENNAI[i]);
		strcpy(mumbai_a.place[i],MUMBAI[i]);
		strcpy(pondicherry_a.place[i],PONDICHERRY[i]);
		
	}
	for(i=0;i<5;i++)
	{
		strcpy(goa_b.place[i],GOA[i]);
		strcpy(kolkata_b.place[i],KOLKATA[i]);
		strcpy(chennai_b.place[i],CHENNAI[i]);
		strcpy(mumbai_b.place[i],MUMBAI[i]);
		strcpy(pondicherry_b.place[i],PONDICHERRY[i]);
		
	}
	for(i=0;i<7;i++)
	{
	strcpy(goa_c.place[i],GOA[i]);
		strcpy(kolkata_c.place[i],KOLKATA[i]);
		strcpy(chennai_c.place[i],CHENNAI[i]);
		strcpy(mumbai_c.place[i],MUMBAI[i]);
		strcpy(pondicherry_c.place[i],PONDICHERRY[i]);
	}
	for(i=0;i<7;i++)
	{
		strcpy(goa_d.place[i],GOA[i]);
		strcpy(kolkata_d.place[i],KOLKATA[i]);
		strcpy(chennai_d.place[i],CHENNAI[i]);
		strcpy(mumbai_d.place[i],MUMBAI[i]);
		strcpy(pondicherry_d.place[i],PONDICHERRY[i]);
	}
	
strcpy(goa_d.cruise,"AVIALABLE");
strcpy(kolkata_d.cruise,"AVIALABLE");
strcpy(chennai_d.cruise,"AVIALABLE");
strcpy(mumbai_d.cruise,"AVIALABLE");
strcpy(goa_d.cruise,"AVAIALABLE");
}

void print_package(struct five f)
{
int i;
FILE *fp;
fp=fopen("seats.txt","a");
    printf("NO. OF DAYS --> %d\n\n",2);
	printf("HOTEL CATEGORY 1-STAR\n\n");
	printf("TRANSPORT FACILITY IS TOURIST BUS\n\n");
	printf("TOURING PLACES PROVIDE:\n\n");
	fprintf(fp,"NO. OF DAYS -->2\nHOTEL CATEGORY 1-STAR\nTRANSPORT FACILITY IS TOURIST BUS\nTOURING PLACES PROVIDE:\n");
	for(i=0;i<3;i++)
	{
		printf("%s\t",f.place[i]);
		fprintf(fp,"%s\n",&f.place[i]);
	}
	fclose(fp);
	printf("\n\n\n\n");
}
void print_package(struct ten f)
{
int i;
FILE *fp;
fp=fopen("seats.txt","a");
    printf("NO. OF DAYS--> %d\n\n",3);
	printf("HOTEL CATEGORY 3-STAR\n\n");
	printf("TRANSPORT FACILITY IS TOURIST CAB\n\n");
	printf("TOURING PLACES PROVIDE:\n\n");
	fprintf(fp,"NO. OF DAYS -->3\nHOTEL CATEGORY 3-STAR\nTRANSPORT FACILITY IS TOURIST CAB\nTOURING PLACES PROVIDE:\n");
	for(i=0;i<5;i++)
	{
		printf("%s\t",f.place[i]);
		fprintf(fp,"%s\n",&f.place[i]);
	}
	fclose(fp);
	printf("\n\n\n\n");
}
void print_package(struct fifteen f)
{
int i;
	FILE *fp;
fp=fopen("seats.txt","a");
    printf("NO. OF DAYS --> %d\n\n",5);
	printf("HOTEL CATEGORY 5-STAR\n\n");
	printf("TRANSPORT FACILITY IS SEDAN\n\n");
	printf("TOURING PLACES PROVIDE:\n\n");
	fprintf(fp,"NO. OF DAYS -->5\nHOTEL CATEGORY 5-STAR\nTRANSPORT FACILITY IS SEDAN\nTOURING PLACES PROVIDE:\n");
	for(i=0;i<7;i++)
	{
		printf("%s\t",f.place[i]);
		fprintf(fp,"%s\n",&f.place[i]);
	}
	fclose(fp);
	printf("\n\n\n");
}
void print_package(struct twenty f)
{
int i;
	FILE *fp;
fp=fopen("seats.txt","a");
    printf("NO. OF DAYS --> %d\n",7);
	printf("HOTEL CATEGORY 7-STAR\n");
	printf("TRANSPORT FACILITY IS LUXURY SEDAN\n\n");
	printf("CRUISE AVAILAIBLE\n\n");
	printf("TOURING PLACES PROVIDE:\n\n");
	fprintf(fp,"NO. OF DAYS -->5\nHOTEL CATEGORY 5-STAR\nTRANSPORT FACILITY IS SEDAN\nTOURING PLACES PROVIDE:\n");
	for(i=0;i<10;i++)
	{
		printf("%s\t",f.place[i]);
		fprintf(fp,"%s\n",&f.place[i]);
	}
	fclose(fp);
	printf("\n\n\n");
}
void ass(int v)
{
	
	holiday();
	switch(v)
	{
	case 1:
	print_package(mumbai_a);
	break;
	case 2:
	print_package(pondicherry_a);
		break;
	case 3:
	print_package(kolkata_a);
		break;
	case 4:
	print_package(goa_a);
		break;
	case 5:
	print_package(chennai_a);
		break;
	case 6:
	print_package(mumbai_b);
		break;
	case 7:
	print_package(pondicherry_b);
		break;
	case 8:
	print_package(kolkata_b);
		break;
	case 9:
	print_package(goa_b);
		break;
	case 10:
	print_package(chennai_b);
		break;
	case 11:
	print_package(mumbai_c);
		break;
	case 12:
	print_package(pondicherry_c);
		break;
	case 13:
	print_package(kolkata_c);
		break;
	case 14:
	print_package(goa_c);
		break;
	case 15:
	print_package(chennai_c);
		break;
	case 16:
	print_package(mumbai_d);
		break;
	case 17:
	print_package(pondicherry_d);
		break;
	case 18:
	print_package(kolkata_d);
		break;
	case 19:
	print_package(goa_d);
		break;
	case 20:
	print_package(chennai_d);
		break;
	}
}
}
