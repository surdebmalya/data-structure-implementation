// Find the private and public keys for both alice and bob when p=23 and g=9

import java.util.*;
class Main {

    // Power function to return value of a ^ b mod P
private
    static long power(long a, long b, long p) {
        if (b == 1)
            return a;
        else
            return (((long)Math.pow(a, b)) % p);
    }

    // Driver code
public
    static void main(String[] args) {
        long P, G, x, a, y, b, ka, kb;

        Scanner sc = new Scanner(System.in);

        // Both the persons will be agreed upon the
        // public keys G and P

        // A prime number P is taken
        System.out.println("Enter P");
        P = sc.nextInt();

        // A primitive root for P, G is taken
        System.out.println("Enter G");
        G = sc.nextInt();
        ;

        // Alice will choose the private key a
        // a is the chosen private key
        a = 4;

        // Gets the generated key
        x = power(G, a, P);

        // Bob will choose the private key b
        // b is the chosen private key
        b = 3;

        // Gets the generated key
        y = power(G, b, P);

        // Generating the secret key after the exchange
        // of keys
        ka = power(y, a, P); // Secret key for Alice
        kb = power(x, b, P); // Secret key for Bob

        System.out.println("\nAlice : ");
        System.out.println("\tPrivate key :" + a);
        System.out.println("\tSecret key :" + ka);
        System.out.println("\nBOB : ");
        System.out.println("\tPrivate key :" + b);
        System.out.println("\tSecret key :" + kb);
    }
}