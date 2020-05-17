#include<stdio.h>
#include<stdlib.h>
#include"package.h"		


#define MAX 10

namespace dj{
void path1(int u,int v,int os)
{
	void dijkstra(double G[MAX][MAX],int n,int startnode,int v1);
	void tripplan(int a,int b);
	int arr[10][10],n,x;
	int i,j;

	double G[MAX][MAX]={
    {0,4000,INFINITY,5000,INFINITY},
    {4000, 0,3500,INFINITY,INFINITY},
    {INFINITY,3500,0,3800,INFINITY},
    {5000,INFINITY,3800,0,4500},
    {INFINITY,INFINITY,INFINITY,4500,0}
  };
  
n=5;
dijkstra(G,n,u,v);
if(os==1)
tripplan(u,v);	
}


void tripplan(int u,int v)
		{
			rrr:
		printf("\n\n\nENTER THE TOTAL AMOUNT/ BUDGET OF YOUR TRIP\n\n\n\n");
		printf("CHOOSE YOUR BUDGET FOR HOLIDAY PLAN\n\nPRESS\n\n1 FOR Rs.5000\n2 FOR 10000\n3 FOR 15000\n4 FOR 20000\n\n\n");
		int r1;
		scanf("%d",&r1);
		if(r1<1 && r1>4)
		{
			printf("ENTER VALID INPUT\n\n");
		goto rrr;
			}
		r1=r1*5000;
		r1=(r1/5000-1)*5+v+1;
		art::ass(r1);
		printf("\n");
	}



void dijkstra(double G[MAX][MAX],int n,int startnode,int v)
{
char d[10][100]={"MUMBAI","PONDICHERRY","KOLKATA","GOA","CHENNAI"};
	double cost[MAX][MAX],distance[MAX],pred[MAX];
	double visited[MAX],count,mindistance;
	int nextnode;
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(G[i][j]==0)
				cost[i][j]=INFINITY;
			else
				cost[i][j]=G[i][j];

	for(i=0;i<n;i++)
	{
		distance[i]=cost[startnode][i];
		pred[i]=startnode;
		visited[i]=0;
	}
	distance[startnode]=0;
	visited[startnode]=1;
	count=1;
	while(count<n-1)
	{
		mindistance=INFINITY;
		
		for(i=0;i<n;i++)
			if(distance[i]<mindistance&&!visited[i])
			{
				mindistance=distance[i];
				nextnode=i;
			}
						
			visited[nextnode]=1;
			for(i=0;i<n;i++)
				if(!visited[i])
					if(mindistance+cost[nextnode][i]<distance[i])
					{
						distance[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}
 i=v;
		if(i!=startnode)
		{
			printf("\nYOUR ROUTE IS =%s",d[i]);
			j=i;
			do
			{
				j=pred[j];
				printf(" <--- %s",d[j]);
			}while(j!=startnode);
}
printf("\n\n\n");
}

}