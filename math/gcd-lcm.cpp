int gcd(int a,int b)
{
	if(!b) return a;
	return gcd(b,a%b);
}
��С��������lcm(a,b) = a*b/gcd(a,b)

