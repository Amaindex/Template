//o(V*V)
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 200//�����ֵ 
int lj[MAXN+1][MAXN+1];//�ڽӾ��� 
int us[MAXN+1];//�Ƿ����� 
int pre[MAXN+1];//·�� 
int n,m;//�㡢���� 
int S,N;//��㣬�յ� 
//���·�� 
void printpath(int k)
{
	if(k==S) printf("%d->",S);
	else
	{
		printpath(pre[k]);
		if(k==N) printf("%d\n",N);
		else printf("%d->",k);
	}
}
int dij()
{
	if(~scanf("%d%d",&n,&m)==0) return 0;
	//��ʼ�� 
	S=1;
	N=n;
	for(int i=1;i<=n;i++) //��Ŵ�1��ʼ
	{
		fill(lj[i],lj[i]+n+1,INF);
		lj[i][i]=0;
	}
	fill(us,us+n+1,0);
	//���� 
	for(int i=0;i<m;i++)
	{
		int v,e,w;
		scanf("%d%d%d",&v,&e,&w);
		if(lj[v][e]>w) 
		{
			lj[v][e]=w;	
			lj[e][v]=w;
		}//����ͼ 
	}
	//���� 
	vector<int> a(n+1);//ÿ���㵽S����̾���  
	fill(a.begin(),a.end(),INF);
	a[S]=0;
	while(us[N]==0)
	{
		int min=INF,mini=S; 
		for(int i=1;i<=n;i++)//�ҵ�û�ù��ĵ�S�ľ�����̵�һ���� 
		{
			if(us[i]==0&&min>a[i])
			{
				min=a[i];
				mini=i;
			}
		}
		if(min==INF) break;
		us[mini]=1;
		for(int i=1;i<=n;i++)//����û�ù��ĵ㵽S����̾��� 
		{
			if(us[i]==0&&a[i]>a[mini]+lj[mini][i]) 
			{
				a[i]=a[mini]+lj[mini][i];
				pre[i]=mini;//�洢·�� 
			}
		}
	}
	//��� 
	if(us[N]) 
	{
		printf("%d\n",a[N]);
		printpath(N);
	}
	//else �����ڴ�S��N��·��
	return 1;
}
int main()
{
	while(dij());
	return 0;
} 
