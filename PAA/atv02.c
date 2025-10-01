#include <stdio.h>

char verify(int E, int A, int X[]) {
    int s, ver, minInter;
    float sTest1, sTest2;

    s = E/A;
    ver = 0;

    sTest1 = -s;
    while (sTest1 < s) {
        sTest2 = sTest1;
        ver = 0;
        for (int i = 0; i<A; i++){
            if (X[i] <= sTest2 || X[i] > sTest2+s) {
                ver--;
            }
            sTest2+=s;
        }
        if (ver == 0) return 'S';
        else sTest1 += 0.01;
    }

    return 'N';
}

int main(void) {
    int E, A;
    int X[10000];

    scanf("%i",&E);
    scanf("%i",&A);
    for (int i = 0; i<A; i++) scanf("%i", &X[i]);

    printf("%c", verify(E,A,X));

}