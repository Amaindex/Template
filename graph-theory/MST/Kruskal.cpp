//o(ElogE)ϡ��ͼ
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
#define MAXN 100//������       
struct edge
{
    int s,v,w;//���㼰���� 
    edge(int s1,int v1,int w1):s(s1),v(v1),w(w1){}
    bool operator <(const edge &a)const{return w<a.w;}//�������С�������� 
};
vector<edge> ed;
int n,m;//���������� 
//���鼯����
int bcj[MAXN+5];//�㼯 
// Getroot
int gr(int k)
{
    if(bcj[k]!=k) bcj[k]=gr(bcj[k]);
    return bcj[k];
}
// Merge 
void mg(int k1,int k2)
{
    int p1=gr(k1);
    int p2=gr(k2);
    if(p1==p2) return;
    bcj[p1]=p2;
}
int Kruskal()
{
	if(~scanf("%d%d",&n,&m)==0) return 0;
	//��ʼ�� 
	for(int i=0;i<=n;i++) bcj[i]=i;
	ed.clear();
	//���� 
	for(int i=0;i<m;i++)
    {
        int s,v,w;
        scanf("%d%d%d",&s,&v,&w);
        ed.push_back(edge(s,v,w));
    }
    sort(ed.begin(),ed.end());
    int qz=0,us_num=0;//Ȩֵ�͡��ù��ı���
	for(int i=0;i<m;i++)
    {
        if(gr(ed[i].s)!=gr(ed[i].v))//���һ�����������˵�root��ͬ 
        {
            mg(ed[i].s,ed[i].v);//�������߼������� 
            qz+=ed[i].w;
            us_num++;
        }
        if(us_num==n-1) break;
    }
    if(us_num==n-1)
    {
    	printf("%d\n",qz);
	}
	//else ����ͨͼ 
	return 1;
} 
int main()
{
	while(Kruskal());
	return 0;
} 
