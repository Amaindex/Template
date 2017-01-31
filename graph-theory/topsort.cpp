#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<list>
#include<algorithm>
#include<stack>
using namespace std;
#define LL long long int
#define INF 0x3f3f3f3f
#define MAXN 150005//�����ֵ 
int n,m;//�㡢���� 
int jg[MAXN+5];//��� 
int ds[MAXN+5];//ÿ���������� 
int topsort()
{
	if(~scanf("%d%d",&n,&m)==0)	return 0;
	//��ʼ��
	int h=0;
	fill(ds,ds+n+1,0); 
	vector<vector<int> > lj(n+5);//�ڽӱ� 
	//����
	for(int i=0;i<m;i++)
	{
		int e,v;
		scanf("%d%d",&e,&v);
		lj[e].push_back(v); 
		ds[v]++;
	}
	queue<int> ld;//���Ϊ0�ĵ�Ķ��� 
	for(int i=1;i<=n;i++)//��Ŵ�1��ʼ 
	{
		if(ds[i]==0) ld.push(i); 
	}
	if(!ld.empty()) 
	{
		while(!ld.empty())
		{
			jg[h]=ld.front();
			for(int i=0;i<lj[jg[h]].size();i++)
			{
				ds[lj[jg[h]][i]]--;
				if(ds[lj[jg[h]][i]]==0) ld.push(lj[jg[h]][i]);
			}
			//lj[jg[h]].clear();//�����Ϊ0�ĵ��ͼ��ȥ�� 
			h++;
			ld.pop();
		}
		if(h==n)
		{
			//��� 
			for(int i=0;i<n;i++) 
			{
				if(i!=n-1) printf("%d ",jg[i]);
				else printf("%d\n",jg[i]);
			}
		}
		//else �л� 
	}
	//else �л� 
	return 1; 
}
int main()
{
	while(topsort());
	return 0; 
} 
