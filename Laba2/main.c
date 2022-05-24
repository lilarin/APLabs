#include <stdio.h>
#include <math.h>
int main() {
    double borderLeft,borderRight,Step,x,y,a=3.1;
    printf("Example values is: [-2;2], step = 0.5, a = 3.1;\n");
    printf("Left border is:" );
    scanf("\n%lf:",&borderLeft);
    printf("Right border is:" );
    scanf("\n%lf:",&borderRight);
    printf("Step is:" );
    scanf("\n%lf:",&Step);
    printf("A is:" );
    scanf("%lf:",&a);
    while (pow(a,3)<0) {
        printf("A should be zero or above. ");
        printf("Type new a:" );
        scanf("%lf:",&a);
    }
    for (x = borderLeft; x <= borderRight; x+=Step) {
        if (x < -1.0) {
        y = -x - 1;
        }
        else if (fabs(x)<=1) {
            y = 1.0 - pow(x, 2) * cos(x * M_PI); // (x * x) можна замінити pow(x,2)
        }
        else {
                y = x - (1.0 / sqrt(pow(a,3))); // sqrt(a*a*a) можна замінити на sqrt(pow(a,3))
        }
        printf("x=%f y=%f\n", x, y);
    }
    return 1; }