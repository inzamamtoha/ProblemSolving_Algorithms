#include<bits/stdc++.h>
using namespace std;
#define LL long long int
void mat_mul(LL a[2][2],LL b[2][2])
{
	LL c[2][2],i,j,k,l;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			c[i][j]=0;
			for(k=0;k<2;k++)
			{
				c[i][j] = c[i][j] + ( a[i][k] * b[k][j] );
			}
		}
	}

	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			a[i][j]=c[i][j];
		}
	}

}
void mat_expo(LL F[2][2],LL res[2][2],int n)
{
	LL l=n;
	while(n)
	{
		if(n%2==1)
		{
			mat_mul(res,F);
		}
		mat_mul(F,F);
		n/=2;
	}

}
LL fibo_matrix(LL n)
{
    LL F[2][2],res[2][2];
    LL i,j,k,x;
    if(n==0)
		return 0;

	F[0][0]=1,F[0][1]=1;
	F[1][0]=1,F[1][1]=0;

	res[0][0]=1,res[0][1]=0;
	res[1][0]=0,res[1][1]=1;

	mat_expo(F,res,n-1);
	return res[0][0];

}
int main()
{
	LL i,j,k,n;
	scanf("%lld",&n);
	LL ans = fibo_matrix(n);
	printf("%lld\n",ans);
	main();

}


