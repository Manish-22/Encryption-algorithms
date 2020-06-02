#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int checkPrime(int n)
{
	for (int i = 2; i <= n/2; i++)
    {
		if (n % i == 0)
		{
			return 0; // Not Prime
		}
	}

	return 1; // Prime
}

int findGCD(int a, int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
    // base case
    if (a == b)
        return a;
    // a is greater
    if (a > b)
        return findGCD(a-b, b);
    return findGCD(a, b-a); //b is greater
}
int powMod(int x,int y,int p)
{
    int res = 1;      // Initialize result

    x =x%p;        //decompose x within range of 1 to p

    while ( y >0)
    {
        //Find modular exponent if y is odd
        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // dividing y by 2
        x = (x*x) % p;
    }
    return res;

}
 int main()
 {
	 int p, q;
	 int n, phin;
	 int data, cipher, decrypt;

	while (1)
    {
		printf("Enter any two prime numbers: ");
		scanf("%d %d", &p, &q);

		if (!(checkPrime(p) && checkPrime(q)))
			printf("Enter only Prime numbers\n");
		else
			break;
	}

	n = p * q;

	phin = (p - 1) * (q - 1);

    int e = 2;

	while (e < phin)
    {
        if (findGCD(e, phin)==1)
            break;
        else
            e++;
    }

	printf("Value of phi: %d\nValue of n: %d\n", phin, n);

	double d1 = 1/ ( double )e;
    double d = fmod ( d1, phin );

    printf("Value of e: %d\nValue of d: %lf\n", e, d);

	printf("Enter some numerical data: ");
	scanf("%d", &data);

    cipher = powMod(data, e, n);
	printf("The cipher text is: %d\n", cipher);

    double c = pow(data,e);
    double m = pow(c,d);

    decrypt=(int)m%n;
    printf("The decrypted text is :%d",decrypt+1);

    return 0;
}
