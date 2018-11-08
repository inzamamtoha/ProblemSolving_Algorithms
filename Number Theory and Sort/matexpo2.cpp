#include <cstring>
#include <iostream>
#include <cstdlib>
#define ll long long
using namespace std;

/*
 * function to multiply two matrices
 */
void multiply(ll a[2][2],ll b[2][2])
{
	ll c[2][2],i,j,k,l;
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

 /*
  * function to calculate power of a matrix
  */
void power(ll F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    ll M[2][2] = {{1,1},{1,0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}

/*
 * function that returns nth Fibonacci number
 */
ll fibo_matrix(ll n)
{
    ll F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0];
}
/*
 * Main
 */
int main()
{
    int n;
    while (1)
    {
        cout<<"Enter the integer n to find nth fibonnaci no.(0 to exit): ";
        cin>>n;
        if (n == 0)
            break;
        cout<<fibo_matrix(n)<<endl;
    }
    return 0;
}
