#include <stdio.h>
#include <math.h>
int main() {
    double a,b,c;
    printf("Example values is: a=0.5,b=3.1,c=0.4;\n");
    printf("a=" );
    scanf("\n%lf:",&a);
    printf("b=" );
    scanf("\n%lf:",&b);
    while (a==0 && b==0) {
        printf("Error. A and B Can not be zero at once.");
        printf("\nType new a:");
        scanf("%lf:",&a);
        printf("Type new b:");
        scanf("%lf:",&b);
    }
    printf("c=" );
    scanf("\n%lf:",&c);
    while ((2.0 * c)>=fabs(1)) {
        printf("Error. Type new c.");
        scanf("%lf:",&c);
    }
    double x = (sqrt(asin(2.0 * c) + exp(-2.0 * c) * (c + b)));
    printf("x=%f\n", x);
    double y = (cos(pow(c, 3.0))) * (cos(pow(c, 3.0))) - (c / sqrt(pow(a, 2) + pow(b, 2)));
    printf("y=%.3f", y);

    return 1;
}