#include<iostream>
using namespace std;
long long extend_gcd(long long a,long long b,long long &x,long long &y)//�� ax+by=gcd(a,b)��������,����gcd(a,b)
{
	if(a==0&&b==0) return -1;//�����Լ��
	if(b==0){x=1;y=0;return a;}
	long long d=extend_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
int bdfc(long long a,long long b,long long c,long long &x,long long &y)//��ax+by=c��x����С�������� (ax��c(mod b)����С��������) 
{
	long long d=extend_gcd(a,b,x,y);
	if(d==-1||c%d) return -1;
	x*=c/d;
	y*=c/d;//�ؽ�
	b/=d;
	a/=d;
	/*���н�
	x=x+b*t;
	y=y-a*t;
	ģb��ͬ�Ľ⹲�� d ����Ϊ��t=0,1,..d-1
	*/ 
	long long tx=x;
	x=(x%b+b)%b;//x����С�������� 
	y+=(tx-x)/b*a;//��Ӧy�Ľ� 
	return 0;
} 
