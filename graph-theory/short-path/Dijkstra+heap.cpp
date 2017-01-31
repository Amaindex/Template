//o((E+V)logV) 
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 30000
struct edge
{
	int v,w;//�յ㣬�������/�㣬��S�ľ��� 
	edge(int v1,int w1):v(v1),w(w1){}	
	bool operator < (const edge &e) const {return w>e.w; } //С����
};
int us[MAXN+1];//�Ƿ����� 
int pre[MAXN+1];//�洢·�� 
int n,m;//�㡢����  
int S,N;//���,�յ� 
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
	vector<vector<edge> > lj(n+1);//�ڽӱ�
	fill(us,us+n+1,0);
	//���� 
	for(int i=0;i<m;i++)
	{
		int v,e,w;
		scanf("%d%d%d",&v,&e,&w);
		lj[v].push_back(edge(e,w));//����ͼ 
	}
	//���� 
	priority_queue<edge> q;//���ȶ���ʵ�ֶ�
	vector<int> a(n+1);//��Ÿ���������ʱ�ĵ�S�ľ��룬����ĳ�ν�����֮ǰ��¼�ľ���С���͸��¾����·�� 
	fill(a.begin(),a.end(),INF); 
	q.push(edge(S,0));
	edge mini(0,0);
	while(!q.empty())
	{	 
		do
		{
			mini=q.top();
			q.pop();
		}while(us[mini.v]==1&&!q.empty());//�ҵ�û�ù��ĵ�S�ľ�����̵�һ���� 
		if(us[mini.v]==0)
		{				
			us[mini.v]=1;
			if(mini.v==N) break; 
			for(int i=0;i<lj[mini.v].size();i++)//����û�ù��ĵ㵽S����̾��� 
			{
				if(us[lj[mini.v][i].v]==0) 
				{
					int k=mini.w+lj[mini.v][i].w;
					if(a[lj[mini.v][i].v]>k)  
					{
						a[lj[mini.v][i].v]=k;
						q.push(edge(lj[mini.v][i].v,k));//Ҳ���Բ��ŵ�if����ڴ��������Ϊ�ѻ�ѡ��������ͬ���е�S�ľ�����С�ģ������Ķ�����ѡ��,���Լ�ʹ����ı�֮ǰ�Ĵ�Ҳû��ϵ 
						pre[lj[mini.v][i].v]=mini.v;
					}
				}
			}
		}
	}
	//��� 
	if(us[N]==1) 
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
