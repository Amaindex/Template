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
#define sc(i) scanf("%d",&i)
#define pr(j) printf("%d\n",j)
#define N 100005 //��������� 
int tr[N];//��״���� 
int n;//��ǰ������ 
int lowbit(int x){return x&(-x);}//��ȡ��������x���һ��1�Լ������0��ɵ��� 
void add(int x,int k)//��������k 
{
	while(x<=n)
	{
		tr[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x)//��ѯ1��x������� 
{
	int ans=0;
	while(x)
	{
		ans+=tr[x];
		x-=lowbit(x);
	}
	return ans;
}
int main()
{
	//��ʼ�� 
	sc(n);
	fill(tr,tr+n+1,0);
	for(int i=1;i<=n;i++)
	{
		int x;
		sc(x);
		add(i,x);
	}
	return 0;
}
