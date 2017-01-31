#include<iostream>
using namespace std;
#define LL long long 
LL extend_gcd(LL a,LL b,LL &x,LL &y)//�� ax+by=gcd(a,b)��������,����gcd(a,b)
{
	if(a==0&&b==0) return -1;//�����Լ��
	if(b==0){x=1;y=0;return a;}
	LL d=extend_gcd(b,a%b,y,x);
	y-=a/b*x;
	return d;
}
//*********����Ԫ*******************
// ax �� 1(mod n)
LL mod_reverse(LL a,LL n)
{
	LL x,y;
	LL d=extend_gcd(a,n,x,y);
	if(d==1) return (x%n+n)%n;
	else return -1;
} 
//�� x �� ai(mod bi) bi�������� 
LL a[10005],b[10005],c[10005];
int main()
{
	int n;
	scanf("%d",&n);
	LL sum=1;//bi�۳� 
	for(int i=0;i<n;i++) 
	{
		scanf("%I64d",&b[i]);
		scanf("%I64d",&a[i]);
		sum*=b[i];
	}
	for(int i=0;i<n;i++) 
	{
		c[i]=sum/b[i];
	}
	LL x=0;
	for(int i=0;i<n;i++) x=(x+a[i]*mod_reverse(c[i],b[i])*c[i]%sum)%sum;//���һ���� 
	while(x<=0) x+=sum;//��С�������� 
	printf("%d\n",x);
}
