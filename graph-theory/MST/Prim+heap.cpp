//o(ElogV) ϡ��ͼ 
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
#define MAXN 30000
#define INF 0x3f3f3f3f       
struct edge
{
    int v,w;//�յ㣬�������/�㣬�����ľ��� 
    edge(int v1,int w1):v(v1),w(w1){}
    bool operator < (const edge &a) const{return w>a.w;} //С���� 
};
int us[MAXN+1];//�Ƿ����� 
int n,m;//�㡢����  
int Prim()
{		
  	if(~scanf("%d%d",&n,&m)==0) return 0;
  	//��ʼ�� 
	vector<vector<edge> > lj(n+1);//�ڽӱ�
	int qz=0,us_num=0;//Ȩֵ�ͣ��ù��ĵ��� 
	fill(us,us+n+1,0);
	//���� 
	for(int i=0;i<m;i++)
	{
		int v,e,w;
		scanf("%d%d%d",&v,&e,&w);
		lj[v].push_back(edge(e,w));
		lj[e].push_back(edge(v,w));
	}//����ͼ 
	//���� 
	priority_queue<edge> q;//���ȶ���ʵ�ֶ�
	vector<int> a(n+1);//��Ÿ���������ʱ�ĵ����ľ��룬����ĳ�ν�����֮ǰ��¼�ľ���С���͸��¾����·�� 
	fill(a.begin(),a.end(),INF);
	q.push(edge(1,0));//��Ŵ�1��ʼ 
	edge mini(0,0);
	while(!q.empty())
	{	 
		do
		{
			mini=q.top();
			q.pop();
		}while(us[mini.v]==1&&!q.empty());//�ҵ�û�ù��ĵ����ľ�����̵�һ���� 
		if(us[mini.v]==0)
		{			
			qz+=mini.w;
			us[mini.v]=1;
			us_num++; 
			if(us_num==n) break; 
			for(int i=0;i<lj[mini.v].size();i++)//����û�ù��ĵ㵽������̾��� 
			{
				if(us[lj[mini.v][i].v]==0) 
				{
					int k=lj[mini.v][i].w;
					if(a[lj[mini.v][i].v]>k)
					{
						a[lj[mini.v][i].v]=k;
						q.push(edge(lj[mini.v][i].v,k));//Ҳ���Բ��ŵ�if����ڴ��������Ϊ�ѻ�ѡ��������ͬ���е����ľ�����С�ģ������Ķ�����ѡ��,���Լ�ʹ����ı�֮ǰ�Ĵ�Ҳû��ϵ 
					}
				} 
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
