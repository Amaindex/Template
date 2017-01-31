//o(V*V*V) 
#include<iostream>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 200
int dis[MAXN+1][MAXN+1];//dp���� 
int path[MAXN+1][MAXN+1];//·�� 
int n,m;//�㡢���� 
int u,v;//��㣬�յ� 
void flo()
{
	scanf("%d%d",&n,&m);
	//��ʼ�� 
	for(int i=0;i<=n;i++) 
	{
		//��Ҫ��¼·��ʱ 
		for(int j=0;j<=n;j++)
		{
			dis[i][j]=INF;
			path[i][j]=j;
		}
		//����Ҫʱ
		//fill(dis[i],dis[i]+n,INF);
		dis[i][i]=0;
	}
	//���� 
	for(int i=0;i<m;i++)
	{
		int u1,v1,w;
		scanf("%d%d%d",&u1,&v1,&w);
		if(dis[u1][v1]>w)
		{
			dis[u1][v1]=w;
			dis[v1][u1]=w;	
		}
	}
	//���� 
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][k]+dis[k][j]<dis[i][j]) 
				{
					dis[i][j]=dis[i][k]+dis[k][j];	
					path[i][j]=path[i][k];
				}		
			}
		}
	}
} 
//���·�� 
void printpath()
{
	int tmp=u; 
	printf("%d",u);
    while(tmp!=v)
    {
        printf("-->%d",path[tmp][v]);
        tmp=path[tmp][v];
    }
    printf("\n");
}
int main()
{
	flo();		
	while(~scanf("%d%d",&u,&v))
	{	
		printf("%d\n",dis[u][v]==INF?-1:dis[u][v]);
		if(dis[u][v]!=INF) printpath();		
	}
	return 0;
 } 
