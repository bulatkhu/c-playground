#include <stdio.h>
#include <stdbool.h>

void sieve(const int max)
{
    bool prim[max];

    for (int i = 0; i < max; i++)
    {
        // Inizialisierung einer Listen mit der Länge von max - 1
        prim[i] = true;
        // printf("i=%d: %s\n", i, prim[i] ? "true" : "false");
    }

    prim[0] = false;
    prim[1] = false;

    for (int i = 2; i < max; i++)
    {
        // Nicht prim Zahlen überspringen
        if (!prim[i])
        {
            continue;
        }

        for (int j = i * i; j < max; j += i)
        {
            if (!prim[j])
            {
                continue;
            }
            // Vielfachen von i als nicht prim markieren
            prim[j] = false;
        }

        // for (int j = i + 1; j < max; j++) {
        //     if (!prim[j]) {
        //         continue;
        //     }
        //
        //     if (j % i == 0) {
        //         prim[j] = false;
        //         // that means, that j is not prim
        //         printf("j=%d is not prim! i=%d\n", j, i);
        //     }
        //     // printf("i=%d: | j=%d %s\n", i, j, prim[i] ? "true" : "false");
        // }
    }

    for (int i = 0; i < max; i++)
    {
        if (prim[i])
        {
            // Prim Zahlen ausgabe, sowie in der Aufgabenstellung
            printf("%d\n", i);
        }
    }
}

int main(int argc, char **argv)
{
    const int MAX = 100;

    sieve(MAX);
}
