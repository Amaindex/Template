//o(V*V)  ����ͼ 
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<list>
#include<algorithm>
using namespace std;
#define ll long long int
#define INF 0x3f3f3f3f       
#define MAXN 200//�����ֵ 
int lj[MAXN+1][MAXN+1];//�ڽӾ��� 
int us[MAXN+1];//�Ƿ����� 
int n,m;//�㡢���� 
int Prim()
{
	if(~scanf("%d%d",&n,&m)==0) return 0;
	//��ʼ�� 
	int qz=0,us_num=0;//Ȩֵ�͡��ù��ĵ��� 
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
	vector<int> a(n+1);//ÿ���㵽������̾���  
	fill(a.begin(),a.end(),INF);
	a[1]=0;//��Ŵ�1��ʼ 
	while(us_num!=n)
	{
		int min=INF,mini=1; 
		for(int i=1;i<=n;i++)//�ҵ�û�ù��ĵ����ľ�����̵�һ���� 
		{
			if(us[i]==0&&min>a[i])
			{
				min=a[i];
				mini=i;
			}
		}
		if(min==INF) break;
		us[mini]=1;
		qz+=min;
		us_num++;
		for(int i=1;i<=n;i++)//����û�ù��ĵ㵽������̾��� 
		{
			if(us[i]==0&&a[i]>lj[mini][i]) 
			{
				a[i]=lj[mini][i];
			}
		}
	}
	//��� 
	if(us_num==n) 
	{
		printf("%d\n",qz);
	}
	//else ����ͨͼ 
	return 1;
}
int main()
{
	while(Prim());
	return 0;
} 
