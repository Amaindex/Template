#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 32
int r,p; //������,ȡģ�� 
struct Matrix
{
	int a[N][N];
	void MakeI() { //��Ϊ��λ����
		memset(a,0,sizeof(a));
		for(int i = 0;i < r; ++i)
		a[i][i] = 1;
	}
}; 
Matrix operator + (const Matrix & m,const Matrix & n)
{
	Matrix c;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<r;j++)
		c.a[i][j]=(m.a[i][j]+n.a[i][j])%p;
	}
	return c;
}
Matrix operator * (const Matrix & m,const Matrix & n)
{
	Matrix c;
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < r; j++)
        {
            c.a[i][j] = 0;
            for(int k = 0; k < r; k++)
            {
                c.a[i][j] = (c.a[i][j]+m.a[i][k]*n.a[k][j]%p)%p;//����˷��ĳ˷�����
            }
        }
    }
    return c;
}
Matrix PowMod(const Matrix & m,int k)
{ //��m^k mod p
	Matrix result;
	result.MakeI(); //MakeI�ǽ�result��Ϊ��λ����
	Matrix base = m;
	while(k) {
		if( k & 1) result = result*base; //result*base mod p
		k >>= 1;
		base = base*base;
	}
	return result;
} 
Matrix PowSumMod(Matrix &m,int n)
{// return (a+ a^2 + ... + a^n) Mod p;
	Matrix re;
	re.MakeI(); //MakeI�ǽ�result��Ϊ��λ����
	if( n == 1) return m;
	if( n % 2 == 0)return (re+PowMod(m,n/2))*PowSumMod(m,n/2);
	else return (re+PowMod(m,(n-1)/2)) * PowSumMod(m,(n-1)/2)+ PowMod(m,n);
}
int main()
{
	int k;
	scanf("%d%d%d",&r,&k,&p);
	Matrix s;
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<r;j++) 
		{
			scanf("%d",&s.a[i][j]);
			s.a[i][j]%=p;
		}
	}
	s=PowSumMod(s,k);
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<r;j++)  printf("%d%c",s.a[i][j],j==r-1?'\n':' ');
	}
	return 0;
}
