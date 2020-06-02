#include <stdlib.h>
#include <stdio.h>
//Function to calculate x^y mod p
long int power(long int x,long int y,long int p)
{
    long int res = 1;      // Initialize result

    x =x%p ;      //decompose x within range of 1 to p

    while (y>0)
    {
        //Find modular exponent if y is odd        if (y & 1)
            res = (res*x) % p;

        y = y>>1; // dividing y by 2
        x = (x*x) % p;
    }
    return res;

}
int main()
{
    long int p, g, x, a, y, b, sa, sb;
    p = 23; // A prime number P is taken
    printf("The value of p : %ld\n", p);

    g = 9; // A primitve root for p, g is taken
    printf("The value of g : %ld\n", g);

    // Alice will choose the private key a
    a = rand(); // Here a is randomised as any value can be taken
    printf("The private key a for Alice : %ld\n", a);
    x = power(g, a, p); // key is generated

    // Bob will choose the private key b
    b =rand(); // Same is the case with b
    printf("The private key b for Bob : %ld\n", b);
    y = power(g, b, p); // key is generated

    // Generating the secret key after the exchange
        // of keys
    sa = power(y, a, p); // Secret key for Alice
    sb = power(x, b, p); // Secret key for Bob

    printf("Secret key for the Alice is : %ld\n", sa);
    printf("Secret Key for the Bob is : %ld\n", sb);

    return 0;
}
