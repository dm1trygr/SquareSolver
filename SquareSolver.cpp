#include <stdio.h>
#include <math.h>
#include <TXLib.h>
#include <float.h>

double coeff_input(void);
void solve(double a, double b, double c);

int main(void) {
    double a, b, c;

    printf("������� ������ ���������� (a):\n");
    a = coeff_input();

    printf("������ ������� ������ ����������� (b):\n");
    b = coeff_input();

    printf("� �������, ������� ������ ����������� (c):\n");
    c = coeff_input();

    solve(a, b, c);

    return 0;
}

double coeff_input(void) {
    double inputted_coefficient;
    while (scanf("%lf", &inputted_coefficient) != 1) {
        printf("��������� �������� �� �������� ������!\n");
    }
    while (getchar() != '\n') continue;
    return inputted_coefficient;
}

void solve(double a, double b, double c) {
    if (fabs(a) <= DBL_EPSILON) {
        if (fabs(b) <= DBL_EPSILON && fabs(c) <= DBL_EPSILON) {
            printf("������� ���������� �����\n");
        }
        else if (fabs(b) <= DBL_EPSILON && fabs(c) > DBL_EPSILON) {
            printf("������� ���\n");
        }
        else {
            double x = - c / b;
            printf("�������: x = %.3f\n", x);
        }
    }
    else {
        double discrim = b * b - 4 * a * c;
        if (discrim < 0) {
            printf("������� ���\n");
        }
        else if (fabs(discrim) <= DBL_EPSILON) {
            double x = - b / (2 * a);
            printf("�������: x = %.3f\n", x);
        }
        else {
            double x1 = (-b - sqrt(discrim)) / (2 * a),
                   x2 = (-b + sqrt(discrim)) / (2 * a);
            printf("�������: x1 = %.3f � x2 = %.3f\n", x1, x2);
        }
    }
}
