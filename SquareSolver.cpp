#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <float.h>

double coeff_input(void);
void solve(double a, double b, double c);

int main(void) {
    double a, b, c;

    printf("Введите первый коэфициент (a):\n");
    a = coeff_input();

    printf("Теперь введите второй коэффициент (b):\n");
    b = coeff_input();

    printf("И наконец, введите третий коэффициент (c):\n");
    c = coeff_input();

    solve(a, b, c);

    return 0;
}

double coeff_input(void) {
    double inputted_coefficient;
    while (scanf("%lf", &inputted_coefficient) != 1) {
        printf("Введенное значение не является числом!\n");
    }
    while (getchar() != '\n') continue;
    return inputted_coefficient;
}

void solve(double a, double b, double c) {
    if (fabs(a) <= DBL_EPSILON) {
        if (fabs(b) <= DBL_EPSILON && fabs(c) <= DBL_EPSILON) {
            printf("Решений бесконечно много\n");
        }
        else if (fabs(b) <= DBL_EPSILON && fabs(c) > DBL_EPSILON) {
            printf("Решений нет\n");
        }
        else {
            double x = - c / b;
            printf("Решение: x = %.3f\n", x);
        }
    }
    else {
        double discrim = b * b - 4 * a * c;
        if (discrim < 0) {
            printf("Решений нет\n");
        }
        else if (fabs(discrim) <= DBL_EPSILON) {
            double x = - b / (2 * a);
            printf("Решение: x = %.3f\n", x);
        }
        else {
            double x1 = (-b - sqrt(discrim)) / (2 * a),
                   x2 = (-b + sqrt(discrim)) / (2 * a);
            printf("Решения: x1 = %.3f и x2 = %.3f\n", x1, x2);
        }
    }
}
