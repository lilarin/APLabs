#include <stdio.h>
#include <math.h>

int main() {
    double eps,x,sum = 0;
    int iteration=0;
    do {
        printf("Type x (|x|<1):");
        scanf("%lf",&x);
    }
    while (fabs(x)>1);
    do {
        printf("Type epsilon (eps<1):");
        scanf("%lf",&eps);
    }
    while (eps>=1);
    for (int power=0; fabs(pow(x,power)) > eps; power++) {
        sum += pow(x,power);
        iteration += 1;
    }

    printf("Amount of iterations is: %d\nSum is: %.14lf\nIdeal sum is: %.14lf",iteration, 1/(1-x),sum);
    return 1;
}