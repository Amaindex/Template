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
//*********����Ԫ*******************
//ax = 1(mod n)
long long mod_reverse(long long a,long long n)
{
	long long x,y;
	long long d=extend_gcd(a,n,x,y);
	if(d==1) return (x%n+n)%n;
	else return -1;
}
int main()
{
	long long n,m;
	cin>>m>>n;
	cout<<mod_reverse(m,n)<<endl;
}
